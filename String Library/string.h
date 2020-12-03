#ifndef string_h
#define string_h

// Library Function Prototypes
int     all_letters(char *s);
int     len_diff(char *s1, char *s2);
int     strcmp_ign_case(char *s1, char *s2);
int     find(char *h, char *n);
int     num_in_range(char *s1, char b, char t);
int     diff(char *s1, char *s2);
int     is_empty(char *s);
int     ends_with_ignore_case(char *s, char *suff);
int     _strlen(char* s);
void    shorten(char *s, int new_len);
void    rm_left_space(char *s);
void    rm_right_space(char *s);
void    rm_space(char *s);
void    rm_empties(char** words);
void    capitalize(char *s);
void    take_last(char *s, int n);
char*   ptr_to(char *h, char *n);
char*   str_zip(char *s1, char *s2);
char*   dedup(char *s);
char*   pad(char *s, int d);
char*   repeat(char *s, int x, char sep);
char*   replace(char *s, char *pat, char *rep);
char*   str_connect(char **strs, int n, char c);
char**  str_chop_all(char *s, char c);

#endif // string_h
