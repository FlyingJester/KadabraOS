#include "mmu.h"

struct k_MemoryPage *k_MMUFindFirstAvailablePage(struct k_MemoryPage *memory_start, uint64_t size){
k_this_start:
    if(memory_start->in_use){
        goto next;
    }
    
    if(memory_start->next_offset==0){
        uint64_t x_size = MEMORY_PAGE_SIZE - PAGE_HEADER_SIZE;
        while(x_size < size)
            x_size += MEMORY_PAGE_SIZE;

        memory_start->length = size;
        memory_start->next_offset = x_size;
    }
    if(memory_start->length >= size){
        return memory_start;
    }
next:
    memory_start = k_MMUFindNextPage(memory_start);
    goto k_this_start;

    return 0;
}

struct k_MemoryPage *k_MMUFindNextPage(struct k_MemoryPage *memory_start){
    return (struct k_MemoryPage *)(((uint8_t *)k_MMUAddressForPage(memory_start)) + memory_start->next_offset);
}

void *k_MMUAddressForPage(struct k_MemoryPage *page_header){
    return ((uint8_t *)page_header)+PAGE_HEADER_SIZE;
}
