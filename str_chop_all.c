#include "string.h"
#include <stdlib.h>

char **str_chop_all(char *s, char c) {
        char buffer[100];
	char **tokens = NULL;
        int count = 0;
	int len = 0;
	for (len; s[len] != '\0'; ++len) if (s[len] == c) count++;
    	if (count == 0) return tokens;
	if ((tokens = (char **)malloc(sizeof(char*) * (count + 2))) == NULL) return tokens;
        char **temp = tokens;
    	while (*s != '\0') {
        	int len = 0;
        	while (*s != c && *s != '\0') buffer[len++] = *s++;
        	buffer[len] = '\0';
        	len = 0;
        	if ((*temp = (char *)malloc(sizeof(char*))) == NULL) {
            		tokens = NULL;
            		return tokens;
        	}
        	for (int i = 0; (*(*temp + i) = *(buffer + i)) != '\0'; i++); temp++;
        	if (*s != '\0') s++;
        }
        *temp = NULL;
        return tokens;
}
