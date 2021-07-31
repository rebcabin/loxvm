//
// Created by BrianBeckman on 7/31/2021.
//

#include "memory.h"


void * reallocate(void * pointer, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        free (pointer);
        return NULL;
    }

    void * result = realloc(pointer, newSize);
    assert (result != NULL);
    if (result == NULL)
        exit (1);
    return result;
}