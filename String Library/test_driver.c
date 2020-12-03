#include "string.h"
#include <stdlib.h>
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
void test_pad();  
void test_ends_with_ignore_case();
void test_repeat();
void test_replace();
void test_str_connect();
void test_rm_empties();
void test_str_chop_all();

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
	test_pad();
	test_ends_with_ignore_case();
	test_repeat();
	test_replace();
	test_str_connect();
	test_rm_empties();
	test_str_chop_all();
	return 0;
}

void test_all_letters() {
      char* str = "Hello World";
      puts("1) Test for all_letters()");
      if (all_letters(str)) {
		printf("%s\n", str);
  		puts("All characters in string were letters\n");
      }  
      else puts("All characters in string were not letters\n");
}

void test_num_in_range() {
	puts("2) Test for num_in_range()");
	char* s = "yellow";
	char b = 'f', t = 'm';
	int num_range = num_in_range("yellow", 'f', 'm');
	printf("The string is %s\n", s);
	printf("The range %c-%c\n", b, t);
	printf("There are %d letters in the range\n", num_range);
}

void test_diff() {
	puts("\n3) Test for diff()");
	char* s1 = "Book";
	char* s2 = "Back";
	int d = diff(s1, s2);
	printf("The strings %s and %s\n", s1, s2);
	printf("The string differs in %d ways\n", d);
}

void test_shorten() {
	char s[] = "hello world";
	puts("\n4) Test for shorten()");
	puts("Before:");
	printf("%s\n", s);
        shorten(s, 5);
	printf("%s\n", s);
}

void test_len_diff() {
        puts("\n5) Test for len_diff()");
        char* s1 = "Philadelphia";
        char* s2 = "Hello";
        printf("The strings are %s and %s\n", s1, s2);
        printf("%s - %s = %d\n", s1, s2, len_diff(s1, s2));
}

void test_rm_left_space() {
	char s[] = "     Hello";
	puts("\n6) Test for rm_left_space()");
	printf("String is %s\n", s);
	rm_left_space(s);
	printf("String with left white-space removed is %s\n", s);
}

void test_rm_right_space() {
        char s[] = "Hello    ";
        puts("\n7) Test for rm_right_space()");
        printf("String is %s\n", s);
        rm_right_space(s);
        printf("String with right white-space removed is %s\n", s);
}

void test_rm_space() {
        char s[] = "   Hello    ";
        puts("\n8) Test for rm_space()");
        printf("String is %s\n", s);
        rm_space(s);
        printf("String with white-space removed is %s\n", s);
}

void test_find() {
        char s[] = "Hello";
	char s1[]  = "l";
        puts("\n9) Test for find()");
        printf("Looking for %s in %s\n", s1, s);
        int i = find(s, s1);
        printf("Index of the first occurrence of %s is %d\n", s1, i);
}

void test_ptr_to() {
        char s[] = "Hello";
        char s1[]  = "l";
        puts("\n10) Test for ptr_to()");
        printf("Looking for %s in %s\n", s1, s);
        char* i = ptr_to(s, s1);
        printf("Pointer to fist occurence of %s is %p\n", s1, i);
}

void test_is_empty() {
        //char s[] = "Hello";
        char s[] = "  ";
	puts("\n11) Test for is_empty()");
        if (!is_empty(s)) printf("The string %s is not empty\n", s);
	else printf("The string is empty\n");
}

void test_str_zip() {
        char s1[] = "Temple";
        char s2[] = "Hello";
        puts("\n12) Test for str_zip()");
        printf("The original strings are %s and %s\n", s1, s2);
        printf("The zipped strings is %s\n", str_zip(s1, s2));
}

void test_capitalize() {
        char s[] = "hello world";
        puts("\n13) Test for capitalize()");
        printf("String before is %s\n", s);
        capitalize(s);
        printf("String after is %s\n", s);
}

void test_strcmp_ign_case() {
        char s1[] = "hello";
	char s2[] = "Hello";
        puts("\n14) Test for strcmp_ign_case()");
        printf("Strings are %s and %s\n", s1, s2);
        // add a better test print
        printf("The result is %d\n", strcmp_ign_case(s1, s2));
}

void test_take_last() {
        char s[] = "hello";
        puts("\n15) Test for take_last()");
        printf("String before is %s\n", s);
        take_last(s, 3);
        printf("String after is %s\n", s);
}

void test_dedup() {
        char s[] = "hellllo";
        puts("\n16) Test for dedup()");
        printf("String before is %s\n", s);
        printf("String after is %s\n", dedup(s));
}


void test_pad() {
	// add quotes here to see padding	 
        char s[] = "hello";
        puts("\n17) Test for pad()");
        printf("String before is '");
	for (int i = 0; s[i] != '\0'; ++i) printf("%c", s[i]);
	printf("'\n");
        printf("String after is '");
	char *s1 = pad(s, 8);
	for (int i = 0; s1[i] != '\0'; ++i) printf("%c", s1[i]);	
	printf("'\n");
}


void test_ends_with_ignore_case() {
	char s1[] = "Coding";
	char s2[] = "ing";
	puts("\n18) Testing for ends_with_ignore_case()");
	printf("The strings are %s and %s\n", s1, s2);
	if (ends_with_ignore_case(s1, s2)) printf("The string %s is a suffix of %s\n", s2, s1);
	else ("The string %s is not a suffix of %s\n", s2, s1);
}

void test_repeat() {
	char s[] = "hello";
	puts("\n19) Testing for repeat()");
	printf("The original string is %s\n", s);
	printf("The repeated string is %s\n", repeat(s, 5, '-'));
}

void test_replace() {
	char s1[] = "Steph is the X";
        char s2[] = "X";
	char s3[] = "best";
        puts("\n20) Testing for replace()");
        printf("The strings are %s, %s, and %s\n", s1, s2, s3);
	printf("The new replaced string is %s\n", replace(s1, s2, s3));
}

void test_str_connect() {
	char* s[4] = {"Hello", "World", "Hello", "World"};
	puts("\n21) Testing for str_connect()");
	printf("The strings are ");
	for (int i = 0; i < 4 ; ++i) printf("%s ", s[i]);
	printf("\nThe connected string is %s\n", str_connect(s, 4, '-'));
}

void test_rm_empties() {
        char* s[6] = {"Hello", "World", " ", " ", "Steph", NULL};
        //char** s_ptr = s;
	puts("\n22) Testing for rm_empties()");
        printf("The strings are ");
        for (int i = 0; i < 5; ++i) printf("%s ", s[i]);
        rm_empties(s);
	printf("\nThe new string is ");
	for (int i = 0; i < 5; ++i) printf("%s ", s[i]);
	puts(" ");
}

void test_str_chop_all() {
	char s[] = "Hello/World/Hello/Hello/World";
	puts("\n23) Testing str_chop_all()");
	printf("Original String %s\n", s);
	int arr_len = 0;
	char** s_ptr = str_chop_all(s, '/');
	while(s_ptr[arr_len]) arr_len++;
	for (int i = 0; i < arr_len; ++i) {
		printf("%s\n", s_ptr[i]);
	}
}

