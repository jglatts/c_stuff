#include "string.h"
#include <stdio.h>

void test_all_letters();
void test_num_in_range();
void test_diff();

int main() {
	test_all_letters();
	test_num_in_range();
	test_diff();
        return 0;
}

void test_all_letters() {
      char* str = "Hello World";
      puts("Test for all_letters()");
      if (all_letters(str)) {
		printf("%s\n", str);
  		puts("All characters in string were letters\n");
      }  
      else puts("All characters in string were not letters\n");
}

void test_num_in_range() {
	puts("Test for num_in_range()");
	char* s = "yellow";
	char b = 'f', t = 'm';
	int num_range = num_in_range("yellow", 'f', 'm');
	printf("The string is %s\n", s);
	printf("The range %c-%c\n", b, t);
	printf("There are %d letters in the range\n", num_range);
}

void test_diff() {
	puts("\nTest for diff()");
	char* s1 = "Book";
	char* s2 = "Back";
	int d = diff(s1, s2);
	printf("The strings %s and %s\n", s1, s2);
	printf("The string differs in %d ways\n", d);
}
