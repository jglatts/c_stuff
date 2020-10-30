#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void get_user_input(int*, int*);
size_t get_user_menu_option(size_t*);
void generate_test_array(int i, int j, int[i][j]);
void print_array(int i, int j, int[i][j]);
void maximum(int i, int j, int[i][j]);
void minimum(int i, int j, int[i][j]);
void average(int i, int j, int[i][j]);

int main(void) {
        int num_students, num_grades;
        size_t user_choice = 0;
        srand(time(NULL));
        get_user_input(&num_students, &num_grades);
        int arr[num_students][num_grades];
        puts("....Generating Test Grades....");
        generate_test_array(num_students, num_grades, arr);
        void (*func_arr[4])(int i, int j, int [i][j]) = {print_array, minimum, maximum, average};
        while (get_user_menu_option(&user_choice) != 4) (*func_arr[user_choice])(num_students, num_grades, arr);
        return 0;
}

void get_user_input(int* num_students, int* num_grades) {
        printf("How Many Students: ");
        scanf("%d", num_students);
        printf("How Many Grades Per Student: ");
        scanf("%d", num_grades);
}

size_t get_user_menu_option(size_t* i) {
        puts("\nEnter A Choice: ");
        puts("\t0 Print the array of grades");
        puts("\t1 Find the minimum grade");
        puts("\t2 Find the maximum grade");
        puts("\t3 Print the average of all grades for each student");
        puts("\t4 End Program");
        printf("%s", "Your Option: ");
        scanf("%lu", i);
        return *i;
}

void generate_test_array(int i, int j, int arr[i][j]) {
        for (int x = 0; x < i; ++x) {
                for (int y = 0; y < j; ++y) arr[x][y] = (rand() % 99) + 1;
        }
}

void print_array(int i, int j, int arr[i][j]) {
        puts("");
        for (int x = 0; x < i; ++x) {
                printf("Student #%d grades: ", x);
                for (int y = 0; y < j; ++y) printf("%-3d ", arr[x][y] + 1);
                puts("");
        }
}

void maximum(int i, int j, int arr[i][j]) {
        puts("");
        for (int x = 0; x < i; ++x) {
                int max = arr[x][0];
                for (int y = 0; y < j; ++y) if (arr[x][y] > max) max = arr[x][y];
                printf("Maximum grade for student #%d is %d\n", x, max);
        }
}

void minimum(int i, int j, int arr[i][j]) {
        puts("");
        for (int x = 0; x < i; ++x) {
                int min = arr[x][0];
                for (int y = 0; y < j; ++y) if (arr[x][y] < min) min = arr[x][y];
                printf("Minimum grade for student #%d is %d\n", x, min);
        }
}

void average(int i, int j, int arr[i][j]) {
        puts("");
        for (int x = 0; x < i; ++x) {
                double grade_sum = 0;
                for (int y = 0; y < j; ++y) grade_sum += arr[x][y];
                printf("Average grade for student #%d is %.2f\n", x, (grade_sum / j));
        }
}
