#include "string.h"
#include <stdio.h>

void test_all_letters();
void test_num_in_range();
void test_diff();
void test_shorten();
void test_len_diff();
void test_rm_left_space(); 
void test_rm_right_space();
void test_rm_space();
void test_find();
void test_ptr_to();
void test_is_empty();
void test_str_zip();
void test_capitalize();
void test_strcmp_ign_case();
void test_take_last();
void test_dedup();
void test_pad();  // needs source file
void test_ends_with_ignore_case();
void test_repeat();

int main() {
	test_all_letters();
	test_num_in_range();
	test_diff();
	test_shorten();
	test_len_diff();
	test_rm_left_space();
	test_rm_right_space();
        test_rm_space();
	test_find();
	test_ptr_to();
	test_is_empty();
	test_str_zip();
	test_capitalize();
	test_strcmp_ign_case();
	test_take_last();
	test_dedup();
	//test_pad();
	test_ends_with_ignore_case();
	test_repeat();
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

void test_rm_space() {
        char s[] = "   Hello    ";
        puts("\nTest for rm_space()");
        printf("String is %s\n", s);
        rm_space(s);
        printf("String with white-space removed is %s\n", s);
}

void test_find() {
        char s[] = "Hello";
	char s1[]  = "l";
        puts("\nTest for find()");
        printf("Looking for %s in %s\n", s1, s);
        int i = find(s, s1);
        printf("Index of the first occurrence of %s is %d\n", s1, i);
}

void test_ptr_to() {
        char s[] = "Hello";
        char s1[]  = "l";
        puts("\nTest for ptr_to()");
        printf("Looking for %s in %s\n", s1, s);
        char* i = ptr_to(s, s1);
        printf("Pointer to fist occurence of %s is %p\n", s1, i);
}

void test_is_empty() {
        //char s[] = "Hello";
        char s[] = "  ";
	puts("\nTest for is_empty()");
        if (!is_empty(s)) printf("The string %s is not empty\n", s);
	else printf("The string is empty\n");
}

void test_str_zip() {
        char s1[] = "Temple";
        char s2[] = "Hello";
        puts("\nTest for str_zip()");
        printf("The original strings are %s and %s\n", s1, s2);
        printf("The zipped strings is %s\n", str_zip(s1, s2));
}

void test_capitalize() {
        char s[] = "hello world";
        puts("\nTest for capitalize()");
        printf("String before is %s\n", s);
        capitalize(s);
        printf("String after is %s\n", s);
}

void test_strcmp_ign_case() {
        char s1[] = "hello";
	char s2[] = "Hello";
        puts("\nTest for strcmp_ign_case()");
        printf("Strings are %s and %s\n", s1, s2);
        // add a better test print
        printf("The result is %d\n", strcmp_ign_case(s1, s2));
}

void test_take_last() {
        char s[] = "hello";
        puts("\nTest for take_last()");
        printf("String before is %s\n", s);
        take_last(s, 3);
        printf("String after is %s\n", s);
}

void test_dedup() {
        char s[] = "hellllo";
        puts("\nTest for dedup()");
        printf("String before is %s\n", s);
        printf("String after is %s\n", dedup(s));
}

/*
void test_pad() {

}
*/

void test_ends_with_ignore_case() {
	char s1[] = "Coding";
	char s2[] = "ing";
	puts("\nTesting for ends_with_ignore_case()");
	printf("The strings are %s and %s\n", s1, s2);
	if (ends_with_ignore_case(s1, s2)) printf("The string %s is a suffix of %s\n", s2, s1);
	else ("The string %s is not a suffix of %s\n", s2, s1);
}

void test_repeat() {
	char s[] = "hello";
	puts("\nTesting for repeat()");
	printf("The original string is %s\n", s);
	printf("The repeated string is %s\n", repeat(s, 5, '-'));
}

