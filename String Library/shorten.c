#include "string.h"
#include <stdio.h>

void shorten(char* s, int new_len) { 	
	if (new_len < _strlen(s)) s[new_len] = '\0';
}
	
