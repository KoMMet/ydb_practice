#pragma once
#include "COMMON.h"
#include "Daf.h"

void Bfpalmdrive(void);
void Bfpcommod(void);

void Bfpcomcreatedafacsset_one(dafacsset_s* dafp, char* keyp, char* valuep);
void Bfpcomcreatedafacsget_one(dafacsget_s* dafp, char* keyp);

