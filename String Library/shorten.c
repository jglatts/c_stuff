#include "string.h"
#include <stdio.h>

void shorten(char* s, int new_len) {
	int len = _strlen(s);   	
	if (new_len < len) s[new_len] = '\0';
}
	
