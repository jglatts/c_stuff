#include "string.h"
#include <stdlib.h>

#define MAX_STR_SIZE 100

void rm_empties(char **words) {
        int index = 0, arr_len = 0;
        int word_pos[MAX_STR_SIZE] = {-1};
        int space_pos[MAX_STR_SIZE] = {-1};
        while (words[arr_len]) arr_len++;
        // find the indices of words and empty strings
        while (words[index]) {
                int s_len = _strlen(words[index]);
                // find the empty strings
                for (int i = 0; i < s_len; ++i) {
                        if (words[index][i] == ' ' && s_len == 1) space_pos[index] = 1;
                        else word_pos[index] = 1;
                }
                index++;
        }
        // sum up words and spaces
        int word_count = 0, space_count = 0;
        int new_index = 0, stop_index = 0, new_word_count = 0;
        for (int i = 0; i < MAX_STR_SIZE; ++i) if (word_pos[i] == 1) word_count++;
        for (int i = 0; i < MAX_STR_SIZE; ++i) if (space_pos[i] == 1) space_count++;
        int lim = word_count - space_count;
        for (int i = 0; i < arr_len; ++i) {
                if (space_pos[i] == 1) {
                        //find the next word
                        for (int j = i; j < arr_len; ++j) {
                                if (word_pos[j] == 1) {
                                        new_index = j;
                                        break;
                                }
                        }
                        if (new_word_count < lim) {
                                words[i] = words[new_index];
                                new_word_count++;
                        }
                        else break;
                }
        }
        // fill the rest of the strings with '\0' values
        for (int x = word_count; x < arr_len; ++x) {
                words[x] = "\0";
        }
}
