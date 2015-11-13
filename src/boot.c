#include "kterm.h"
#include "kstring.h"
#include <stdint.h>

void k_ClearTerminal(struct k_Terminal *term){
    const uint16_t blank_char = ks_makeVGACharacter(' ', term->color);
    unsigned i;
    term->buffer = (void *)0xB8000;
    for(i = 0; i<VGA_WIDTH * VGA_HEIGHT; i++){
        term->buffer[i] = blank_char;
    }
}

void k_TerminalInit(struct k_Terminal *term){
    term->x = term->y = 0;
    term->color = ks_makeColor(kECPink, kECDarkGray);
    k_ClearTerminal(term);
}

void k_TermainPutChar(struct k_Terminal *term, char c){
    switch(c){
        case '\n':
            do{
                k_TermainPutChar(term, ' ');
            }while(term->x);
            break;
        case '\t':
            do{
                k_TermainPutChar(term, ' ');
            }while(term->x%4);
            break;
        default:
            term->buffer[term->x + (term->y * VGA_WIDTH)] = ks_makeVGACharacter(c, term->color);
                term->x++;
                if(term->x >= VGA_WIDTH){
                    term->x = 0;
                    term->y++;
                    if(term->y > VGA_HEIGHT)
                        term->y = 0;
                }
            break;
    }
}

void k_TerminalPutString(struct k_Terminal *term, const char *string){
    const uint64_t len = k_StringLength(string);
    uint16_t i;
    for(i = 0; i<len; i++){
        k_TermainPutChar(term, string[i]);
    }
}

void k_Main(){
    struct k_Terminal term;
    k_TerminalInit(&term);
    k_TerminalPutString(&term, "Hello, world!\n");
}
