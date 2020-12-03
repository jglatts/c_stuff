	#include "string.h"
#include <stdlib.h>
#include <stdio.h>

void rm_empties(char **words) {
	int index = 0, arr_len = 0;
	int word_pos[100] = {-1};
	int space_pos[100] = {-1};
	while (words[arr_len]) arr_len++;
	puts(" ");
	printf("Size of string array %d\n", arr_len);
	// find the indices of words and empty strings
	while (words[index]) {
		int s_len = _strlen(words[index]);
		printf("Length of String %s is %d\n", words[index], s_len);
		// find the empty strings
		for (int i = 0; i < s_len; ++i) {
			if (words[index][i] == ' ' && s_len == 1) space_pos[index] = 1;
			else word_pos[index] = 1; 
		}
		index++;
	}
	int new_index = 0;
	int new_word_count = 0;
	int word_count = 0;
	for (int i = 0; i < 100; ++i) if (word_pos[i] == 1) word_count++;
	printf("\nThe word count is %d\n", word_count);
	for (int i = 0; i < arr_len; ++i) {
		if (space_pos[i] == 1) {
			//find the next word
			for (int j = i; j < arr_len; ++j) {
				if (word_pos[j] == 1) {
					new_index = j;
					break;			
				}
			} 
			if (new_word_count++ <= word_count) words[i] = words[new_index];
			else break;
		}
	}
}
