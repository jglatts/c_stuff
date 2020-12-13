#include "string.h"
#include <stdio.h>

void rm_right_space(char* s) {
        int count = 0, first_space_index = 0;
        for (int i = 0; i < _strlen(s); ++i) {
                if (s[i] == ' ') {
                        first_space_index = i;
                        break;
                }
        }
        s[first_space_index] = '\0';
}
