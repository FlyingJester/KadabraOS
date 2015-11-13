#include "kstring.h"

uint64_t k_StringLength(const char *str){
    uint64_t i = 0;
ks_strlen:
    if(str[i]==0)
        return i;
    else
        i++;
    goto ks_strlen;
}
