#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void print_start_race();
void start_race();
void print_race(int, int);
void print_winner(int, int);
void check_player_move(int*, int);
void check_for_winner(int*, int*);
int  get_tort_move(int);
int  get_hare_move(int);

int main() {
    srand((unsigned)time(NULL));
    print_start_race();
    start_race();
    return 0;
}

void print_start_race() {
    puts("\nON YOUR MARK, GET SET");
    puts("BANG             !!!!!");
    puts("AND THEY'RE OFF  !!!!!");
}

void start_race() {
    int tort_index = 1, hare_index = 1, old_tort_index = 1;
    while (tort_index < 70 && hare_index < 70) {
        int tort_move = get_tort_move((rand() % 10) + 1);
        int hare_move = get_hare_move((rand() % 10) + 1);
        check_player_move(&tort_index, tort_move);
        check_player_move(&hare_index, hare_move);
        check_for_winner(&tort_index, &hare_index);
        print_race(tort_index, hare_index);
        sleep(1);
    }
    print_winner(tort_index, hare_index);
}

void check_player_move(int* player_index, int move) {
    if (*player_index + move >= 1) *player_index += move;
    else *player_index = 1;
}

void check_for_winner(int* tort, int* hare) {
    if (*tort > 70) *tort = 70;
    if (*hare > 70) *hare = 70;
}

void print_race(int tort_index, int hare_index) {
    int max = (tort_index >= hare_index) ? tort_index : hare_index;
    for (int i = 1; i <= max; ++i) {
        if (tort_index == hare_index && i == tort_index) printf("OUCH!!!!");
        else if (i == tort_index) printf("T");
        else if (i == hare_index) printf("H");
        else printf(" ");
    }
    puts("");
}

void print_winner(int tort, int hare) {
    if (tort == hare)   puts("\nTortoise Wins!!! YAY!!!");
    else (tort == 70) ? puts("\nTortoise Wins!!! YAY!!!") : puts("\nHare Wins. Yuch");
}

int get_tort_move(int i) {
    if (i >= 1 && i <= 5) return 3;  // fast plod, 50%
    if (i >= 6 && i <= 7) return -6; // slip, 20%
    return 1;                        // slow plod, 30%
}

int get_hare_move(int i) {
    if (i >= 1 && i <= 2) return 0;  // sleep, 20%
    if (i >= 3 && i <= 4) return 9;  // big hop, 20%
    if (i == 5) return -12;          // big slip, 10%
    if (i >= 6 && i <= 8) return 1;  // small hop, 30%
    return -2;                       // small slip, 20%
}
