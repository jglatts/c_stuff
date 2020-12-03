#include "string.h"

int strcmp_ign_case(char *s1, char *s2) {
	int s1_len = 0, s2_len = 0, ret = 0;
	for (s1_len; s1[s1_len] != '\0'; ++s1_len) { }
	for (s2_len; s2[s2_len] != '\0'; ++s2_len) { }
	// convert both strings to lowercase
	for (int i = 0; i < s1_len; ++i) {
		if ((s1[i] >= 65) && (s1[i] <= 90)) {
			s1[i] -= 32;
		}
	}
	for (int i = 0; i < s2_len; ++i) {
		if ((s2[i] >= 65) && (s2[i] <= 90)) {
			s2[i] -= 32;
		}
	}
	if (s1_len == s2_len) {
		for (int i = 0; i < s1_len; ++i) {
			if ((i == s1_len-1) && s1[i] == s2[i]) return 0;
		}
	}
	else if (s1_len >= s2_len) {
        	for (int i = 0; i < s2_len; i++) {
                    	if (s1[i] < s2[i])  return 1;
      	    		if (s1[i] > s2[i])  return -1;
        	}
    	}
	else {
		for (int i = 0; i < s1_len; i++) {
                   	if (s2[i] < s1[i])  return 1;
            		if (s2[i] > s1[i])  return -1;
        	}
    	}
	return ret;
}

