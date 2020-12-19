#include "Daf.h"
#include "libyottadb.h"

/*
 * 機能:データベースに値を設定する
 * 引数:inputp 設定用構造体P 取得するデータの設定情報
 *      outp   取得用構造体P
 * 戻り値:取得結果
 */
int32_t LDafacsget(dafacsset_s* inputp, dafacsget_s* outp)
{
    ydb_buffer_t keyname, midkeys[DAFACS_MIDOPACITY], getvalue;
    int32_t result;


    memset(&keyname, 0, sizeof(keyname));
    memset(&midkeys, 0, sizeof(midkeys));
    memset(&getvalue, 0, sizeof(getvalue));

    keyname.buf_addr = inputp->keyname;
    keyname.len_alloc = keyname.len_used = strlen(inputp->keyname);

    //データ取得の中間情報を設定する
    for(uint32_t i = 0; i < inputp->midkeysnum; i++)
    {
        midkeys[i].buf_addr = inputp->midkeys[i];
        midkeys[i].len_alloc = midkeys[i].len_used = strlen(inputp->midkeys[i]);
    }

    //データ取得用領域設定
    getvalue.buf_addr = outp->getstr;
    getvalue.len_alloc = getvalue.len_used = outp->getstrlength;

    //データ取得
    result = ydb_get_s(&keyname, inputp->midkeysnum, midkeys, &getvalue);

    //データ取得に失敗した場合はYDB_OK以外が設定される
    if(result != YDB_OK)
    {
        //YDBのエラーコードに沿ってエラーメッセージを表示する
        char str[50];
        ydb_buffer_t buf;
        buf.buf_addr = str;
        ydb_message(result, &buf);
        buf.buf_addr[buf.len_used] = '\0';
        puts(str);
    }
    else
    {
        getvalue.buf_addr[getvalue.len_used] = '\0';
    }

    return result;
}

