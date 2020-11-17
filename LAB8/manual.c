#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

}

// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s) {
        char str[100];
        strcpy(str, s);
        // display string in upper case
        for (int i = 0; str[i] != '\0'; ++i) {
                str[i] = toupper(str[i]);
                printf("%c", str[i]);
        }
        // display string in lower case
        puts("");
        for (int j = 0; str[j] != '\0'; ++j) {
                str[j] = tolower(str[j]);
                printf("%c", str[j]);
        }
}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int one   = *s1 - '0';
    int two   = *s2 - '0';
    int three = *s3 - '0';
    int four  = *s4 - '0';
    return one + two + three + four;
}

//3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    float one   = atof(s1);
    float two   = atof(s2);
    float three = atof(s3);
    float four  = atof(s4);
    return one + two + three + four;
}

//4.(Comparing Strings)
void compareStr(const char *s1, const char *s2) {
        // double check this one
        if      (strcmp(s1, s2) < 0) printf("\n%s is less than %s\n", s1, s2);
        else if (strcmp(s1, s2) > 0) printf("\n%s is greater than %s\n", s1, s2);
        else                         printf("\n%s is equal to %s\n", s1, s2);
}

//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {


}

//6.(Random Sentences)
void randomize(void) {


}

//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {


}

//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {


}

//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {


}

//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {


}


//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {


}

//12.(Counting the Number of Words in a String)
int countWords(char *string) {


}

//13.(Strings Starting with "b")
void startsWithB(char *string[]) {



}

//14.(Strings Ending with "ed")
void endsWithed(char *string[]) {


}