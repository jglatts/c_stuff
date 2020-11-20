#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions
void* upperLower(const char * s);
int   convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void  compareStr(const char *s1, const char *s2);
void  comparePartialStr(const char *s1, const char *s2, int n);
void  randomize(void);
int   tokenizeTelNum(char *num);
void  reverse(char *text);
void  removeSpaces(char *str);
int   countSubstr (char * line, char * sub);
int   countChar (char * line, char c);
int   countWords(char *string);
void  countAlpha(char *string);
void  startsWithB(char *string[]);
void  endsWithed(char *string[]);

int main() {
    //random generator
    srand((unsigned)time(NULL));
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
    char *line1 = "helloworldworldworld";
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
    if (strcmp(s1, s2) < 0)
        printf("\n%s is less than %s\n", s1, s2);
    else if (strcmp(s1, s2) > 0)
        printf("\n%s is greater than %s\n", s1, s2);
    else
        printf("\n%s is equal to %s\n", s1, s2);
}

//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {
    char one[n], two[n];
    for (int i = 0; i < n; ++i) {
        one[i] = s1[i];
        two[i] = s2[i];
    }
    if (strncmp(s1, s2, n) < 0)
        printf("\n%s is less than %s\n\n", one, two);
    else if (strncmp(s1, s2, n) > 0)
        printf("\n%s is greater than %s\n\n", one, two);
    else
        printf("\n%s is equal to %s\n\n", one, two);
}

//6.(Random Sentences)
void randomize(void) {
    char* articles[] = {"the ", "a ", "one ", "some ", "any "};
    char* nouns[] = {"boy ", "girl ", "dog ", "town ", "car "};
    char* verbs[] = {"drove ", "jumped ", "ran ", "walked ", "skipped "};
    char* prepositions[] = {"to ", "from ", "over ", "under ", "on "};
    // get the proper format in
    for (int i = 0; i < 20; ++i) {
        char rand_sentance[110];
        strcpy(rand_sentance, articles[rand() % 5]);
        strcat(rand_sentance, nouns[rand() % 5]);
        strcat(rand_sentance, verbs[rand() %  5]);
        strcat(rand_sentance, prepositions[rand() % 5]);
        strcat(rand_sentance, articles[rand() % 5]);
        strcat(rand_sentance, nouns[rand() % 5]);
        printf("%s\n", rand_sentance);
    }
}

//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {
    char* num_ptr;
    char* tokens[3];
    char  number[15];
    int i = 0, area_code;
    num_ptr = strtok(++num, ")");
    while (num_ptr != NULL) {
        tokens[i++] = num_ptr;
        num_ptr = strtok(NULL, "-");
    }
    strcpy(number, tokens[0]);
    strcat(number, tokens[1]);
    strcat(number, tokens[2]);
    removeSpaces(number);
    area_code = atoi(tokens[0]);
    printf("\nArea Code: %d", area_code);
    printf("\nPhone Number: %s\n", number);
    return 0;
}

// Remove spaces from a given string
void removeSpaces(char* str) {
    int count = 0;
    for (int i = 0; i < str[i]; ++i) {
        if (str[i] != ' ') str[count++] = str[i];
    }
    str[count] = '\0';
}

//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {
    char* tokens[100];
    char* str = strtok(text, " ");
    int count = 0;
    while (str) {
        tokens[count++] = str;
        str = strtok(NULL, " ");
    }
    puts("");
    for (int i = count-1; i >= 0; --i) printf("%s ", tokens[i]);
    puts("");
}

//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {
    char* ret_str = strstr(line, sub);
    return (int)strlen(ret_str) / (int)strlen(sub);
}

//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {
    char* ret_str = strchr(line, c);
    int i = 0, count = 0;
    while (ret_str[i] != '\0' && ret_str != NULL) {
       if (ret_str[i++] == c) count++;
    }
    return count;
}


//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int alpha_count[sizeof(alpha)/sizeof(char)];
    printf("\nCount letters of alphabet in %s\n", string);
    for (int i = 0; i < sizeof(alpha)/sizeof(char); ++i) {
        alpha_count[i] = 0;
        for (int j = 0; string[j] != '\0'; ++j) {
            string[j] = toupper(string[j]);
            if (string[j] == alpha[i]) alpha_count[i]++;
        }
    }
    for (int j = 0; j < sizeof(alpha)/sizeof(char); ++j) printf("%c ", alpha[j]);
    puts("");
    for (int x = 0; x < sizeof(alpha_count)/sizeof(int); ++x) printf("%d ", alpha_count[x]);
}



//12.(Counting the Number of Words in a String)
int countWords(char *string) {
    char* str = strtok(string, " ");
    int count = 0;
    while (str) {
        count++;
        str = strtok(NULL, " ");
    }
    return count;
}

//13.(Strings Starting with "b")
void startsWithB(char *string[]) {
   char* temp = string[0];
   int index = 0, count = 0;
   while (temp != NULL) temp = string[index++];
   for (int i = 0; i <= sizeof(index)/sizeof(char); ++i) {
        char* str = string[i];
        //printf("\nLooking at %s", str);
        if (str[0] == 'b') count++;
   }
   printf("\nCount of strings that start with 'b' is %d\n", count);
}

//14.(Strings Ending with "ed")
void endsWithed(char *string[]) {
   char* temp = string[0];
   int index = 0, count = 0;
   while (temp != NULL) temp = string[index++];
   for (int i = 0; i <= sizeof(index)/sizeof(char); ++i) {
        char* str = string[i];
        size_t len = strlen(str);
        //printf("\nLooking at %s", str);
        if (str[len-2] == 'e' && str[len-1] == 'd') count++;
   }
   printf("\nCount of strings that end with 'ed' is %d\n", count);
}
