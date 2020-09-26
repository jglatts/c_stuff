#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function Prototypes */
int  get_array_size();
int  get_low_limit();
int  get_high_limit();
int  find_sequence(int[], int);
void print_array(int[], int);
void print_array_color(int[], int, int, int);
void fill_array(int[], int, int, int);
void find_with_range(int[], int);
void reverse_array(int[], int);
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
                printf("\033[0;32m");
                printf("%-10d", arr[i]);
                printf("\033[0m");
                if (count % 10 == 0) puts("");
        }
}

/* Print the array with color for the given low and high indices */
void print_array_color(int arr[], int size, int low, int high) {
        size_t count = 1;
        int max = arr[low];
        for (int i = 0; i < size; ++i, ++count) {
                if (i >= low && i <= high) {
                        if (arr[i] > max) max = arr[i];
                        printf("\033[1;31m");
                        printf("%-10d", arr[i]);
                        printf("\033[0m");
                }
                else {
                          printf("\033[0;32m");
                          printf("%-10d", arr[i]);
                          printf("\033[0m");
                }
                if (count % 10 == 0) puts("");
        }
        printf("Max: %d\n", max);
}

/* Fill the array based  n the l w and high limits */
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
        print_array_color(arr, size, low_index, high_index);
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
        printf("Original Array: \n");
        print_array(arr, size);
        printf("\nReversed Array: \n");
        print_array(rev_arr, size);
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
