#include "string.h"

int _strlen(char* s) {
	int len = 0;
	for (len; s[len] != '\0'; ++len) { }
	return len;
}
