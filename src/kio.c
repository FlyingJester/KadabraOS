#include "kio.h"
#include "kterm.h"

static struct k_Terminal *selected_terminal = 0;

void k_SelectTerminal(struct k_Terminal *term){
    selected_terminal = term;
}

char k_GetChar(){
    return 0;
}

void k_PutChar(char c){
    if(selected_terminal)
        k_TerminalPutChar(selected_terminal, c);
}

void k_PutString(const char *s){
    if(selected_terminal)
        k_TerminalPutString(selected_terminal, s);
}

void k_PutStringWordWrap(const char *s){
    if(selected_terminal)
        k_TerminalPutStringWordWrap(selected_terminal, s);
}

void k_PrintInt(int32_t i){
    if(!selected_terminal)
        return;

    if(i<0){
        if(selected_terminal->x+1 >= VGA_WIDTH)
            k_TermNewLine(selected_terminal);
        k_TerminalPutChar(selected_terminal, '-');
        i = -i;
    }
    k_PrintUInt(i);
}

void k_PrintUInt(uint32_t i){
    char buffer[80];
    int32_t at = 0;
    while(i){
        buffer[at] = i%10;
        at/=10;
        i++;
        if(at==80)
            break;
    }
    if(!at)
        k_TerminalPutChar(selected_terminal, '0');

    while(at){
        k_TerminalPutChar(selected_terminal, '0' + buffer[at]);
        at--;
    }
}
