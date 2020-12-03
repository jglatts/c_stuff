#include "string.h"
#include <stdlib.h>

char* replace(char *s, char *pat, char *rep) {
    	int s_len = _strlen(s), pat_len = _strlen(pat), rep_len = _strlen(rep);
	char* ret_str = (char*)malloc((s_len + pat_len + rep_len + 1) * sizeof(char));
    	int index = 0;
	while (*s) {
        	if (*s == *pat) {
            		while (*rep) ret_str[index++] = *rep++;
            		rep -= rep_len;
        	}
        	else ret_str[index++] = *s;
        	s++;
    	}
    	ret_str[s_len + pat_len + rep_len + 1] = '\0';
    	return ret_str;
}
