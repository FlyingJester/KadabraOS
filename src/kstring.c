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

k_Bool k_CharIsSpace(char c){
    switch(c){
        case '\n':
        case '\t':
        case '\r':
        case '\v':
        case ' ':
            return 1;
        default:
            return 0;
    }
}
