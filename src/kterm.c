#include "kterm.h"
#include "kstring.h"

void k_TermNewLine(struct k_Terminal *term){
    term->x = 0;
    term->y++;
    if(term->y > VGA_HEIGHT)
        term->y = 0;
}

void k_TerminalInit(struct k_Terminal *term){
    term->x = term->y = 0;
    term->color = ks_makeColor(kECPink, kECDarkGray);
    k_ClearTerminal(term);
}

void k_ClearTerminal(struct k_Terminal *term){
    const uint16_t blank_char = ks_makeVGACharacter(' ', term->color);
    unsigned i;
    term->buffer = (void *)0xB8000;
    for(i = 0; i<VGA_WIDTH * VGA_HEIGHT; i++){
        term->buffer[i] = blank_char;
    }
}

void k_TerminalPutString(struct k_Terminal *term, const char *string){
    const uint64_t len = k_StringLength(string);
    uint16_t i;
    for(i = 0; i<len; i++){
        k_TerminalPutChar(term, string[i]);
    }
}

void k_TerminalPutStringWordWrap(struct k_Terminal *term, const char *string){
    while(*string!='\0'){
        uint16_t word_length = 0;
        while(!k_CharIsSpace(string[word_length])){
            word_length++;
            if(string[word_length]=='\0'){
                k_TerminalPutString(term, string);
                return;
            }
        }

        if((word_length < VGA_WIDTH) && (term->x + word_length >= VGA_WIDTH)){
            if(word_length==0){
                while(k_CharIsSpace(*string))
                    string++;
                continue;
            }
            k_TermNewLine(term);
        }
        else if(word_length==0)
            word_length = 1;
        else if(word_length >= VGA_WIDTH)
            k_TermNewLine(term);
        
        {
            uint16_t i;
            for(i=0; i<word_length; i++)
                k_TerminalPutChar(term, string[i]);
        }
        string += word_length;
    }
}

void k_TerminalPutChar(struct k_Terminal *term, char c){
    switch(c){
        case '\n':
            do{
                k_TerminalPutChar(term, ' ');
            }while(term->x);
            break;
        case '\t':
            do{
                k_TerminalPutChar(term, ' ');
            }while(term->x%4);
            break;
        default:
            term->buffer[term->x + (term->y * VGA_WIDTH)] = ks_makeVGACharacter(c, term->color);
                term->x++;
                if(term->x >= VGA_WIDTH){
                    k_TermNewLine(term);
                }
            break;
    }
}
