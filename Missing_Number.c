/* Simple but interesting Program
 * The Missing Number Game
 *
 * Enter The Number Missing in the Grid
 *
 * Best to play on 3x3 Grid 
 * But choice is yours */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int scoreMN = 0;

void Suffle_Grid(int* , int);

void Print_Grid(int*, int);

int Interface();

int Play(int);

int main() {
    system("clear");
    srand(time(0));
    printf("----------V1.1----------\n\n");
    printf("The Missing Number Game\n\n\n");
    int i = Interface();
    while (1) {
        if (i == 0) {
            break;
        }
        else if (i > 2 && i < 10) {
            i = Play(i);
        }
        else {
            i = Interface();
        }
    }
    return 0;
}

void Suffle_Grid(int* arr, int n) {
    int a, b, tmp;
    for (int i=0; i<3*n; i++) {
        a = rand()%n;
        b = rand()%n;
        if (a == b) {
            i--;
            continue;
        }
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
}

void Print_Grid(int* arr, int n) {
    printf("Score: '%d'\n\n", scoreMN);
    for (int i=0; i<n; i++) {
        printf("+----");
    }
    printf("+\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("|");
            if (arr[i*n + j] == 56789)
                printf(" ** ");
            else 
                printf(" %2d ", arr[i*n + j]);
        }
        printf("|\n");
        for (int i=0; i<n; i++) {
            printf("+----");
        }
        printf("+\n");
    }
}

int Interface() {
    char i;
    printf(" 'N^2 - 1' boxes of NxN Grid will be filled\n");
    printf("with different numbers from 1 to N^2\n");
    printf("Enter the Missing Number As Fast As You can\n\n");
    printf(">> Now choose your N ;-\n");
    printf("  -> Enter a number between 3 to 9 to continue\n");
    printf("  -> Enter 0 to Exit\n");
    system("/bin/stty raw");
    i = getchar();
    system("/bin/stty cooked");
    system("clear");
    return i - '0';
}

int Play(int n) {
    int n_2 = n*n;
    printf("=> Enter 0 to Exit\n\n");
    int arr[n_2];
    for (int i=0; i<n_2; i++) {
        arr[i] = i+1;
    }
    int k, input;
    k = rand()%n_2;
    arr[k] = 56789;
    Suffle_Grid(arr, n_2);
    Print_Grid(arr, n);
    char freeinput;
    system("/bin/stty raw");
    freeinput = getchar();
    system("/bin/stty cooked");
    input = freeinput - '0';
    if (k+1 > 9) {
        system("/bin/stty raw");
        freeinput = getchar();
        system("/bin/stty cooked");
        input = input*10 + freeinput - '0';
    }
    system("clear");
    if (input == k+1) {
        scoreMN++;
        return n;
    }
    else {
        if ( input != 0 )
            printf("Wrong Answer\n\n");
        printf("You Scored %d\n\n", scoreMN);
        scoreMN = 0;
        return Interface();
    }
}
