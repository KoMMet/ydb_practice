#pragma once
#include "COMMON.h"

enum 
{
    // data string max length
    DAFACS_STRLENGTH = 100,

    // dat amiddle keys max opacity
    DAFACS_MIDOPACITY = 50,
};

// data middle keys infomation
typedef char dafacsmidkeys[DAFACS_STRLENGTH][DAFACS_MIDOPACITY];

typedef struct dafacsset_s
{
    // data accsece key
    char* keyname;

    // data accsece middle keys
    dafacsmidkeys midkeys;

    // data accsece middle keys opacity
    uint32_t midkeysnum;

    // data accsece value
    char* setvalue;
} dafacsset_s;

typedef struct dafacsget_s
{
    // get data space
    char* getstr;

    // get data length
    size_t getstrlength;
} dafacsget_s;

int32_t LDafacsset(dafacsset_s* datap);
int32_t LDafacsget(dafacsset_s* inputp, dafacsget_s* outp);
