#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Macros for colored output */
#define RED    "\033[1;31m"
#define GREEN  "\033[0;32m"
#define RESET  "\033[0m"

/* Function Prototypes */
int  get_array_size();
int  get_low_limit();
int  get_high_limit();
int  find_sequence(int[], int);
void print_array(int[], int);
void print_array_color(int[], int, int, int, bool);
void fill_array(int[], int, int, int);
void find_with_range(int[], int);
void reverse_array(int[], int);
void reverse_in_range(int[], int);
void print_sequence(int[], int);

/* Main Function */
int main() {
        int size = get_array_size();
        int low = get_low_limit();
        int high = get_high_limit();
        int arr[size];
        srand(time(NULL));
        fill_array(arr, size, low, high);
        find_with_range(arr, size);
        reverse_array(arr, size);
        reverse_in_range(arr, size);
        print_sequence(arr, size);
        return 0;
}

/* Get the array size from the user */
int get_array_size() {
        int s;
        printf("Please Enter Array Size: ");
        scanf("%d", &s);
        return s;
}

/* Get the array low limit from the user */
int get_low_limit() {
        int low;
        printf("Please Enter Low Limit: ");
        scanf("%d", &low);
        return low;
}

/* Get the array high limit from the user */
int get_high_limit() {
        int high;
        printf("Please Enter High Limit: ");
        scanf("%d", &high);
        return high;
}

/* Print the array */
void print_array(int arr[], int size) {
        size_t count = 1;
        for (int i = 0; i < size; ++i, ++count) {
                printf(GREEN);
                printf("%-6d", arr[i]);
                printf(RESET);
                if (count % 10 == 0) puts("");
        }
}

/* Print the array with color for the given low and high indices */
void print_array_color(int arr[], int size, int low, int high, bool max_check) {
        size_t count = 1;
        int max = arr[low];
        for (int i = 0; i < size; ++i, ++count) {
                if (i >= low && i <= high) {
                        if (arr[i] > max) max = arr[i];
                        printf(RED);
                        printf("%-6d", arr[i]);
                        printf(RESET);
                }
                else {
                          printf(GREEN);
                          printf("%-6d", arr[i]);
                          printf(RESET);
                }
                if (count % 10 == 0) puts("");
        }
        if (max_check) printf("Max: %d\n", max);
}

/* Fill the array based on the low and high limits */
void fill_array(int arr[], int size, int low, int high) {
        int count = 1;
        puts("\n......Filling Array......");
        for (int i = 0; i < size; ++i) {
                int val = (rand() % high) + 1;
                while (val < low) val = (rand() % high) + low;
                arr[i] = val;
        }
        print_array(arr, size);
        puts("");
}

/* Find the index if it's exists */
void find_with_range(int arr[], int size) {
        int low_index, high_index, max, count = 1;
        puts("\n......Find Max In Range......");
        printf("Please Enter the Index Low Limit: ");
        scanf("%d", &low_index);
        max = arr[low_index];
        printf("Please Enter the Index High Limit: ");
        scanf("%d", &high_index);
        print_array_color(arr, size, low_index, high_index, true);
}

/* Reverse the given array */
void reverse_array(int arr[], int size) {
        int rev_arr[size];
        size_t count = 1, start = 0, end = size-1;
        puts("\n......Reversing Array......");
        while (start < end) {
                rev_arr[start] = arr[end];
                rev_arr[end--] = arr[start++];
        }
        puts("Original Array: ");
        print_array(arr, size);
        puts("Reversed Array: ");
        print_array(rev_arr, size);
}

/* Reverse the array between two indices */
void reverse_in_range(int arr[], int size) {
        int low_index, high_index, low, high;
        int rev_arr[size];
        puts("\n......Reverse Array in Range......");
        printf("Please Enter Index Low Limit: ");
        scanf("%d", &low_index);
        printf("Please Enter Index High Limit: ");
        scanf("%d", &high_index);
        puts("\nOriginal Array");
        print_array(arr, size);
        printf("Reversed between %d and %d\n", low_index, high_index);
        // fill the new array
        for (int i = 0; i < size; ++i) rev_arr[i] = arr[i];
        //swap the elements
        low = low_index;
        high = high_index;
        while (low_index < high_index) {
                rev_arr[low_index] = arr[high_index];
                rev_arr[high_index--] = arr[low_index++];
        }
        print_array_color(rev_arr, size, low, high, false);
}

/* Print the index if the seqeuence is found */
void print_sequence(int arr[], int size) {
        int seq = find_sequence(arr, size);
        while (seq >= 0) {
                printf("Seqeunce found at index %d\n", seq);
                seq = find_sequence(arr, size);
        }
        puts("Seqeunce not found");
        puts("Program terminating");
}

/* Ask the user for a sequence and check */
int find_sequence(int arr[], int size) {
        int first, second;
        puts("\n......Finding Sequence......");
        printf("Enter Two Numbers: ");
        scanf("%d %d", &first, &second);
        for (int i = 0; i < size-1; ++i) {
                if (arr[i] == first && arr[i+1] == second) return i;
        }
        return -1;
}
