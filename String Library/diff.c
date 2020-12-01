#include "string.h"
#include <stdio.h>

int diff(char* s1, char* s2) {
	int count = 0, shortest = 0, s1_len, s2_len;
	for (s1_len = 0; s1[s1_len] != '\0'; ++s1_len);
	for (s2_len = 0; s2[s2_len] != '\0'; ++s2_len);
	shortest = (s1_len < s2_len) ? s1_len : s2_len;
	for (int i = 0; i < shortest; ++i) {
		if (s1[i] != s2[i]) count++;
	}
	return count;
}
