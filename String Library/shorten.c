#include "string.h"
#include <stdio.h>

void shorten(char* s, int new_len) {
	int len = 0;
    	char *s1 = s;
    	while (*(s1++) != '\0') len++;
	if (new_len < len) s1[new_len] = '\0';
	s = s1;
}
	
