#pragma once
#include <stdint.h>


/* sizeof(struct k_MemoryPage) should NEVER be larger than 64 bytes. */
#define PAGE_HEADER_SIZE 64
#define MEMORY_PAGE_SIZE 8192

struct k_MemoryPage {
    /* next_offset marks the number of bytes from this structures address plus
     * PAGE_HEADER_SIZE to the start of the next struct k_MemoryPage. 
     * Zero means there is no next page. */
    uint64_t length, next_offset;
    uint8_t in_use;
};

struct k_MemoryPage *k_MMUFindFirstAvailablePage(struct k_MemoryPage *memory_start, uint64_t size);
struct k_MemoryPage *k_MMUFindNextPage(struct k_MemoryPage *memory_start);
void *k_MMUAddressForPage(struct k_MemoryPage *page_header);
