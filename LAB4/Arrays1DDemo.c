#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int  get_array_size();
int  get_low_limit();
int  get_high_limit();
int  find_sequence(int[], int);
void print_array(int[], int);
void fill_array(int[], int, int, int);
void find_with_range(int[], int);
void reverse_array(int[], int);
void print_sequence(int[], int);

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

int get_array_size() {
	int s;
	printf("Please Enter Array Size: ");
	scanf("%d", &s);
	return s;
}

int get_low_limit() {
	int low;
	printf("Please Enter Low Limit: ");
	scanf("%d", &low);
	return low;
}

int get_high_limit() {
	int high;
	printf("Please Enter High Limit: ");
	scanf("%d", &high);
	return high;
}

void print_array(int arr[], int size) {
	size_t count = 1;
	for (int i = 0; i < size; ++i, ++count) {
        	printf("%-10d", arr[i]);
                if (count % 10 == 0) printf("\n");
        }
}

void fill_array(int arr[], int size, int low, int high) {
	int count = 1;
	printf("\n......Filling Array......\n");
	for (int i = 0; i < size; ++i) {
		int val = (rand() % high) + 1;
		while (val < low) val = (rand() % high) + 1;
		arr[i] = val;
	}
	print_array(arr, size);	
	printf("\n");
}

void find_with_range(int arr[], int size) {
	int low_index, high_index, max, count = 1;
	printf("\n......Find Max In Range......\n");
	printf("Please Enter the Index Low Limit: ");
	scanf("%d", &low_index);
	max = arr[low_index];
	printf("Please Enter the Index High Limit: ");
	scanf("%d", &high_index);
	for (int i = 0; i < size; ++i, ++count) {	
		if (i >= low_index && i <= high_index) {
			if (arr[i] > max) max = arr[i];
                        printf("\033[1;31m");
                        printf("%-10d", arr[i]);
                        printf("\033[0m");
		}
		else printf("%-10d", arr[i]);
		if (count % 10 == 0) printf("\n");
	}
	printf("Max: %d\n", max);
}

void reverse_array(int arr[], int size) {
	int rev_arr[size];
	size_t count = 1, start = 0, end = size-1;
	printf("\n......Reversing Array......\n");
	while (start < end) {
		rev_arr[start] = arr[end];
		rev_arr[end--] = arr[start++];
	}
	printf("Original Array: \n");
	print_array(arr, size);	
	printf("\nReversed Array: \n");
        print_array(rev_arr, size);     
}

void print_sequence(int arr[], int size) {	 
	int seq = find_sequence(arr, size);
        while (seq >= 0) {
		printf("Seqeunce found at index %d\n", seq);
		seq = find_sequence(arr, size);
	}
	printf("Seqeunce not found\n");
}

int find_sequence(int arr[], int size) {
	int first, second;
	printf("\n......Finding Sequence......\n");
	printf("Enter Two Numbers: ");
	scanf("%d %d", &first, &second);
	for (int i = 0; i < size-1; ++i) {
		if (arr[i] == first && arr[i+1] == second) return i;
	}
	return -1;	
}

