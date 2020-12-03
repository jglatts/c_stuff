#include "string.h"
#include <stdio.h>

int ends_with_ignore_case(char *s, char *suff) {
	int s_len = 0, suff_len = 0;
	for (s_len; s[s_len] != '\0'; ++s_len) { }
	for (suff_len; suff[suff_len] != '\0'; ++suff_len) { }
	int start_index_check = (s_len - 1) - (suff_len - 1);
	int suff_index = 0;
	for (int i = start_index_check; i < s_len; ++i) {
		if (s[i] != suff[suff_index]) return 0;
		if (suff_index < suff_len) suff_index++;
	}
	return 1;
}
