#include "string.h"
#include <stdlib.h>

char* dedup(char* s) {
	int alph_occurences[26] = {0};
	int len = _strlen(s), index = 0;
	char* ret_str = (char *)malloc(len + 1);
	while (*s) {
		if ((*s >= 65) && (*s <= 90)) {
			if (alph_occurences[*s-65] == 0) {
				ret_str[index++] = *s;
                		alph_occurences[*s-65] += 1;
			}
		}
		if ((*s >= 97) && (*s <= 122)) {
			if (alph_occurences[*s-97] == 0) {
				ret_str[index++] = *s;
                		alph_occurences[*s-97] += 1;
			}
		}
		s++;
	}
    	ret_str[len + 1] = '\0';
    	return ret_str;
}
