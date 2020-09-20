#pragma once
#include "COMMON.h"

enum 
{
    DAFACS_STRLENGTH = 100,
};

typedef char dafacsmidkeys[50][50];

typedef struct dafacsset_s
{
    char* keyname;
    dafacsmidkeys midkeys;
    uint32_t midkeysnum;
    char* setvalue;
} dafacsset_s;

typedef struct dafacsget_s
{
    char* getstr;
    size_t getstrlength;
} dafacsget_s;

int32_t LDafacsset(dafacsset_s* datap);
int32_t LDafacsget(dafacsset_s* inputp, dafacsget_s* outp);
