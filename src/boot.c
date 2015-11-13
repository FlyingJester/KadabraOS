#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

enum k_VGAColorI{
    kECBlack,
    kECBlue,
    kECGreen,
    kECCyan,
    kECRed,
    kECMagenta,
    kECBrown,
    kECGray,
    kECDarkGray,
    kECLightBlue,
    kECLightGreen,
    kECLightCyan,
    kECPink,
    kECLightMagenta,
    kECTan,
    kECWhite
};

typedef uint8_t k_VGAColor;


struct k_Terminal{
    uint8_t x, y;
    k_VGAColor color;
    uint16_t *buffer;
};


static k_VGAColor ks_makeColor(enum k_VGAColorI fore_color, enum k_VGAColorI back_color){
    return fore_color | (back_color << 4);
}

static uint16_t ks_makeVGACharacter(char c, k_VGAColor color){
    const uint16_t c16 = c, color16 = color;
    return c16 | (color16 << 8);
}

static uint16_t ks_shortStringLength(const char *str){
    uint16_t i = 0;
ks_strlen:
    if(str[i]==0)
        return i;
    else
        i++;
    goto ks_strlen;
}

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
    const uint16_t len = ks_shortStringLength(string);
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
