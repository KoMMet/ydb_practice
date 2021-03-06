#include "COMMON.h"
#include "Bfp.h"
#include "Udv.h"
#include "Utl.h"
#include "Daf.h"
#include "bfp.h"

static void print_info(void);

int32_t 
main(int argc, char** argv)
{
    int32_t initarg;
    char* optstr = "hk:v:";
    char keyname[DAFACS_STRLENGTH];
    char setval[DAFACS_STRLENGTH];

    strcpy(keyname, "initkey");
    strcpy(setval, "initvalue");

    if(argc == 1)
    {
        puts("invalid argment");
        print_info();
        return 0;
    }

    while((initarg = getopt(argc, argv, optstr)) != -1)
    {
        if(initarg == 'h')
        {
            print_info();
            return 0;
        }

        switch(initarg)
        {
            case 'k':
                strcpy(keyname, optarg);
                break;
            case 'v':
                strcpy(setval, optarg);
                break;
            default:
                puts("invalid argment");
                break;
        }
    }

    Bfpalmdrive();
    Bfpcommod();

    LUdvmaprint();


    //-----------db access set---------------
    dafacsset_s set;

    //キーが一つのデータ設定
    Bfpcomcreatedafacsset_one(&set, keyname, setval);

    LDafacsset(&set);

    //-----------db access get---------------
    dafacsget_s get;
    char getstr[DAFACS_STRLENGTH];

    //キーが一つのデータ取得
    Bfpcomcreatedafacsget_one(&get, getstr);

    LDafacsget(&set, &get);

    puts(keyname);
    puts(getstr);

}

/*
 * 機能:起動時のヘルプメッセージを表示する 
 * 引数:なし
 * 戻り値:なし
 */
static void print_info(void)
{
    puts("args: -k: key -v value");
    puts("-k key -v value");
}

