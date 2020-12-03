#include "string.h"
#include <stdlib.h>

char *str_connect(char **strs, int n, char c) {
	int new_str_len = 0;
	// get the length of each string
	for (int i = 0; i < n; ++i) new_str_len += (_strlen(strs[i])); 	
	// make room for seperator char and null terminator
	new_str_len += (n-1) + 1; 
	char* ret_str = (char*)malloc(new_str_len * sizeof(char));
	int index = 0;
	// generate new string
	for (int i = 0; i < n; ++i) {
		int str_len = _strlen(strs[i]);
		for (int x = 0; x < str_len; ++x) {
			ret_str[index++] = strs[i][x];
		}
		if (i < n-1) ret_str[index++] = c;
	}
	ret_str[index] = '\0';
	return ret_str;
}
