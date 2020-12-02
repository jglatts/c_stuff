#include "string.h"

int len_diff(char* s1, char* s2) {
	int s1_len = 0, s2_len = 0;
	for (s1_len; s1[s1_len] != '\0'; ++s1_len)
	for (s2_len; s2[s2_len] != '\0'; ++s2_len);
	return s1_len - s2_len;
}
