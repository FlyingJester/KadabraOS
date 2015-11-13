#include "kterm.h"
#include "kstring.h"
#include <stdint.h>

static const char *license_text1 =
"\
Permission to use, copy, modify, and/or distribute this software for any \
purpose with or without fee is hereby granted, provided that the above \
copyright notice and this permission notice appear in all copies. \
";

static const char *license_text2 = 
"\
THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL WARRANTIES \
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF \
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR \
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES \
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN \
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF \
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\
";

void k_Main(){
    struct k_Terminal term;
    k_TerminalInit(&term);
    k_TerminalPutStringWordWrap(&term, "Starting Kadabra Operating system version 0.01\n"\
    "\tCopyright (c) 2015 Martin McDonough\n"\
    "\t\n");
    k_TerminalPutStringWordWrap(&term, license_text1);
    k_TermNewLine(&term);
    k_TermNewLine(&term);
    k_TerminalPutStringWordWrap(&term, license_text2);    
}
