#include "COMMON.h"
#include "Utl.h"

static uint8_t utilsymbol[2] = {'0', '1'};

void LUtilbitprint(uint32_t x)
{
    uint32_t m = 1 << 31;
    for(; m != 0; m >>= 1)
    {
        printf("%c", utilsymbol[(m&x) != 0]);
    }
    puts("");
}

uint32_t LUtlbit32getLSB(uint32_t  a)
{
    return (a & -a);
}

uint32_t LUtlbit32popcount(uint32_t x)
{
    uint32_t n;
    n = (x >> 1) & 0x77777777;
    x = x - n;
    n = (n >> 1) & 0x77777777;
    x = x - n;
    n = (n >> 1) & 0x77777777;
    x = x - n;
    x = (x + (x >> 4)) & 0x0f0f0f0f;
    x = x*0x01010101;
    return x >> 24;
}
    
void LUtlbit32swap(uint32_t* ap, uint32_t* bp)
{
    (*ap)^=(*bp);
    (*bp)^=(*ap);
    (*ap)^=(*bp);
}

