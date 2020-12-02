#include "string.h"

void rm_right_space(char* s) {
        int len = 0, count = 0, first_space_index = 0;
        for (len; s[len] != '\0'; ++len) { }
        for (int i = 0; i < len; ++i) {
                if (s[i] == ' ') {
                        first_space_index = i;
                        break;
                }
        }
        s[first_space_index] = '\0';
}
