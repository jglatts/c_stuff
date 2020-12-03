#include "string.h"
#include <stdlib.h>

char* str_zip(char* s1, char* s2) {
	int s1_len = 0, s2_len = 0;
	for (s1_len; s1[s1_len] != '\0'; ++s1_len) { }
	for (s2_len; s2[s2_len] != '\0'; ++s2_len) { } 
	char *s3 = (char *)malloc((s1_len + s2_len + 1));
    	int count = 0, index = 0;
    	if (s1_len >= s2_len) {
        	while (*s1) {
            		if (count == s2_len) {
                		// copy over the rest of s1
                		s3[index] = *s1;
                		index++;
                		s1++;
            		}
            		else {
                		s3[index] = *s1;
                		index++;
                		s3[index] = *s2;
                		index++;
                		s1++;
                		s2++;
                		count++;
            		}
        	}	
    	}
    else {
        while (*s2) {
            if (count == s1_len) {
                // copy over the rest of s2
                s3[index] = *s2;
                index++;
                s2++;
            }
            else {
                s3[index] = *s1;
                index++;
                s3[index] = *s2;
                index++;
                s1++;
                s2++;
                count++;
            }
        }
    }
    // terminate the string
    s3[s1_len + s2_len + 1] = '\0';
    return s3;
}
