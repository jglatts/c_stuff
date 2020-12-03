#include "string.h"
#include <stdlib.h>

char* repeat(char* s, int x, char sep) {
	int len = 0;
	for (len; s[len] != '\0'; ++len) { }
	int new_len = (len * x) + (x - 1);
	char* ret_str = (char*)malloc(new_len * sizeof(char));		
	int new_str_index = 0;
	while (new_str_index < new_len) {
		for (int i = 0; i < len; ++i) {
			ret_str[new_str_index++] = s[i];
		}
		ret_str[new_str_index++] = sep;
	}
	ret_str[new_len] = '\0';
	return ret_str;
}
