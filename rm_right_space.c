#include "string.h"
#include <stdio.h>

void rm_right_space(char* s) {
	// add " " to know where the spaces are
        int len = 0, count = 0, first_space_index = 0;
        for (len; s[len] != '\0'; ++len) { }
        for (int i = 0; i < len; ++i) {
                if (s[i] == ' ') {
                        first_space_index = i;
                        break;
                }
        }
	/*
        for (int i = first_char_index; s[i] != '\0'; ++i) {
                if (count < len - first_char_index) s[count++] = s[i];
        }
	*/
        s[first_space_index] = '\0';
}
