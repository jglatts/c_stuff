#include "string.h"
#include <stdio.h>

int is_empty(char* s) {
	if (s == NULL)  return 1;
	if (*s == '\0') return 1;
	int len = 0;
	for(len; s[len] != '\0'; ++len) { }
	for (int i = 0; i < len; ++i) {
		if (s[i] != ' ') return 0;
	}
	return 1; // if we make it to here, only whitespace is in the string
}
