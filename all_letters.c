#include "string.h"
#include <stdio.h>

int all_letters(char* s) {
	// optimze this bad boi
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] >= 'a' && s[i] <= 'z')      continue;	// valid char
		else if (s[i] >= 'A' && s[i] <= 'Z') continue;  // valid char
		else if (s[i] == ' ')                continue;  // valid char
		else                                 return 0;	// invalid char
	}
	return 1;
}
