#pragma once
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

#define ks_makeColor(FORE_, BACK_) (FORE_ | (BACK_ << 4))
#define ks_makeVGACharacter(CHAR_, COLOR_) (((uint16_t)CHAR_) | (((uint16_t)COLOR_) << 8))
