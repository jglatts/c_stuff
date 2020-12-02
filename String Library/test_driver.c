#include "string.h"
#include <stdio.h>

void test_all_letters();
void test_num_in_range();
void test_diff();
void test_shorten();
void test_len_diff();
void test_rm_left_space(); 
void test_rm_right_space();

int main() {
	test_all_letters();
	test_num_in_range();
	test_diff();
	test_shorten();
	test_len_diff();
	test_rm_left_space();
	test_rm_right_space();
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

void test_shorten() {
	char s[] = "hello";
	puts("\nTest for shorten()");
	puts("Before:");
	printf("%s\n", s);
        puts("NEEDS TO BE FIXED....SEG FAULT AT SHORTEN()!!!");
	//shorten(s, 3);
	//printf("%s\n", s);
}

void test_len_diff() {
        puts("\nTest for len_diff()");
        char* s1 = "Philadelphia";
        char* s2 = "Hello";
        printf("The strings are %s and %s\n", s1, s2);
        printf("%s - %s = %d\n", s1, s2, len_diff(s1, s2));
}

void test_rm_left_space() {
	char s[] = "     Hello";
	puts("\nTest for rm_left_space()");
	printf("String is %s\n", s);
	rm_left_space(s);
	printf("String with left white-space removed is %s\n", s);
}

void test_rm_right_space() {
        char s[] = "Hello    ";
        puts("\nTest for rm_right_space()");
        printf("String is %s\n", s);
        rm_right_space(s);
        printf("String with right white-space removed is %s\n", s);
}

