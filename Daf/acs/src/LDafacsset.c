#include "Daf.h"
#include "libyottadb.h"


/*
 * 機能:データベースに値を設定する
 * 引数:データ設定構造体P
 * 戻り値:データ設定処理結果 
 */
int32_t LDafacsset(dafacsset_s* datap)
{
    ydb_buffer_t keyname, midkeys[DAFACS_STRLENGTH], setvalue;
    int32_t result;

    memset(&keyname, 0, sizeof(keyname));
    memset(midkeys, 0, sizeof(midkeys));
    memset(&setvalue, 0, sizeof(setvalue));

    keyname.buf_addr = datap->keyname;
    keyname.len_alloc = keyname.len_used = strlen(datap->keyname);

    for(uint32_t i = 0; i < datap->midkeysnum; i++)
    {
        midkeys[i].buf_addr = datap->midkeys[i];
        midkeys[i].len_alloc = midkeys[i].len_used = strlen(datap->midkeys[i]);
    }

    setvalue.buf_addr = datap->setvalue;
    setvalue.len_alloc = setvalue.len_used = strlen(datap->setvalue);

    result = ydb_set_s(&keyname, datap->midkeysnum, midkeys, &setvalue);

    //データ設定の結果を判定する
    if(result != YDB_OK)
    {
        //YDBののエラーコードに沿ってエラーを表示する
        char str[DAFACS_MIDOPACITY];
        ydb_buffer_t buf;
        buf.buf_addr = str;
        ydb_message(result, &buf);
        buf.buf_addr[buf.len_used] = '\0';
        puts(str);
    }

    return result;
}
        

