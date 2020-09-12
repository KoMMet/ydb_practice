#include "Daf.h"
#include "libyottadb.h"


int32_t LDafacsget(dafacsset_s* inputp, dafacsget_s* outp)
{
    ydb_buffer_t keyname, midkeys[50], getvalue;
    int32_t result;


    memset(&keyname, 0, sizeof(keyname));
    memset(&midkeys, 0, sizeof(midkeys));
    memset(&getvalue, 0, sizeof(getvalue));

    keyname.buf_addr = inputp->keyname;
    keyname.len_alloc = keyname.len_used = strlen(inputp->keyname);

    for(uint32_t i = 0; i < inputp->midkeysnum; i++)
    {
        midkeys[i].buf_addr = inputp->midkeys[i];
        midkeys[i].len_alloc = midkeys[i].len_used = strlen(inputp->midkeys[i]);
    }

    getvalue.buf_addr = outp->getstr;
    getvalue.len_alloc = getvalue.len_used = outp->getstrlength;

    result = ydb_get_s(&keyname, inputp->midkeysnum, midkeys, &getvalue);

    if(result != 0)
    {
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

