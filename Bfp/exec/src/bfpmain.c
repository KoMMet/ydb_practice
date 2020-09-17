#include "COMMON.h"
#include "Bfp.h"
#include "Udv.h"
#include "Utl.h"
#include "Daf.h"
#include "bfp.h"

static void print_info(void);

int32_t main(int argc, char** argv)
{
    int initarg;
    char* optstr = "vu";

    while((initarg = getopt(argc, argv, optstr)) != -1)
    {
        if(initarg == 'v')
        {
            print_info();
            return 0;
        }
    }

    Bfpalmdrive();
    Bfpcommod();

    Ludvmanprint();


    //-----------db access set---------------
    dafacsset_s set;
    char keyname[50];
    char setval[50];

    strcpy(keyname, "helloydbname");
    strcpy(setval, "worldydbhello");

    set.midkeysnum = 0;
    set.keyname = keyname;
    set.setvalue = setval;

    LDafacsset(&set);

    //-----------db access get---------------
    dafacsget_s get;
    char getstr[50];
    get.getstr = getstr;
    get.getstrlength = 50;

    LDafacsget(&set, &get);

    puts(getstr);


    //-------------Utl test-----------------
    uint32_t a = 10; // 1010
    uint32_t res;
    res = LUtlbit32getLSB(a);
    LUtilbitprint(res);

    res = LUtlbit32popcount(a);
    printf("%d\n", res);

    uint32_t b = 5; // 0101
    LUtlbit32swap(&a, &b);
    printf("a=%d b=%d\n", a, b );

    return 0;
}

static void print_info(void)
{
    puts("system infomation...");
    puts("etc...");
}

