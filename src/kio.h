#pragma once
#include "kterm.h"

void k_SelectTerminal(struct k_Terminal *term);

char k_GetChar();
void k_PutChar(char c);
void k_PutString(const char *s);
void k_PutStringWordWrap(const char *s);
void k_PrintInt(int32_t i);
void k_PrintUInt(uint32_t i);
