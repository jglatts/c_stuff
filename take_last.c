#include "string.h"

void take_last(char *s, int n) {
	int len = 0;
	for (len; s[len] != '\0'; ++len) { }
	if (n >= len) return;
	for (int i = 0; i < n; i++) {
		s[i] = s[len - n + i];
	}
	s[n] = '\0';
}
