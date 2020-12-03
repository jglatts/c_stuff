#include "string.h"
#include <stdio.h>

char *ptr_to(char *h, char *n) {
        int len = 0;
        for(len; h[len] != '\0'; ++len) { }
        for (int i = 0; i < len; ++i) {
                if (h[i] == *n) return &h[i];
                        
        }
        return NULL;
}
