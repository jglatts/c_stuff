#include "string.h"
#include <stdlib.h>

char* pad(char* s, int d) {
	if (s == NULL) return NULL;
	int len = 0;
	char* ret_str = NULL;
	for (len; s[len] != '\0'; ++len) { }
	if (len == d) {
		int i;
		char* copy = (char*)malloc((len+1) * sizeof(char));
		for (i = 0; i < len; ++i) copy[i] = s[i];
		copy[i] = '\0';
		return copy;
	}
	else {
		int new_size = (len + d) + 1;
		int i, j;
		ret_str = (char*)malloc(new_size * sizeof(char));
		// copy the original string
		for (i = 0; i < len; ++i) {
			ret_str[i] = s[i]; 
		}
		// add the padding
		for (j = i; j < new_size; ++j) {
			ret_str[j] = ' ';
		}
		ret_str[j] = '\0';
	}
	return ret_str;
}	


