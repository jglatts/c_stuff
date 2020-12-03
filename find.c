#include "string.h"

int find(char* h, char* n) {
	int ret = -1, len = 0;
	for(len; h[len] != '\0'; ++len) { }
	for (int i = 0; i < len; ++i) {
		if (h[i] == *n) {
			ret = i;
			break;
		}
	}
	return ret;
}
