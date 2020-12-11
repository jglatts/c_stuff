#include "string.h"

int find(char* h, char* n) {
	int ret = -1;
	for (int i = 0; i < _strlen(h); ++i) {
		if (h[i] == *n) {
			ret = i;
			break;
		}
	}
	return ret;
}
