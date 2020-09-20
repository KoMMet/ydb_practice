#include "COMMON.h"
#include "Bfp.h"
#include "Daf.h"
#include "bfp.h"

void Bfpcomcreatedafacsset_one(dafacsset_s* dafp, char* keyp, char* valuep)
{
    if(dafp == NULL) return;
    if(keyp == NULL) return;
    if(valuep == NULL) return;
    dafp->midkeysnum = 0;
    dafp->keyname = keyp;
    dafp->setvalue = valuep;
}


void Bfpcomcreatedafacsget_one(dafacsget_s* dafp, char* keyp)
{
    if(dafp == NULL) return;
    if(keyp == NULL) return;
    dafp->getstr = keyp;
    dafp->getstrlength = DAFACS_STRLENGTH;
}

