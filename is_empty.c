#include "string.h"
#include <stdio.h>

int is_empty(char* s) {
	if (s == NULL)  return 1;
	if (*s == '\0') return 1;;
	for (int i = 0; i < _strlen(s); ++i) if (s[i] != ' ') return 0;
	return 1; // if we make here, only whitespace is in the string
}
