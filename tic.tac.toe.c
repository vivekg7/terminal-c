/* A little A.I. Based 
 * Tic-Tac-Toe Game
 *
 * reference :
 * https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/ 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// board dimesions N x N
// Customizable
#define N 3

// customisable signs
#define computersign 'o'
#define humansign 'x'

#define max(x, y) x>y?x:y
#define min(x, y) x<y?x:y

char **board;

// these variables store scores
int computerwin = 0;
int humanwin = 0;
int bothwin = 0;

/* Main Computational Part of the Game Begins */
int checkwin() {
    // check row & column
    int ro, co;
    for ( int i=0; i<N; i++ ) {
        ro = 0;
        co = 0;
        for ( int j=0; j<N; j++ ) {
            if ( board[i][j] == computersign )
                ro++;
            else if ( board[i][j] == humansign )
                ro--;
            if ( board[j][i] == computersign )
                co++;
            else if ( board[j][i] == humansign )
                co--;
        }
        if ( ro == N || co == N )
            return 10;
        if ( ro == -(N) || co == -(N) )
            return -10;
    }
    // check diagonal
    ro = 0;
    co = 0;
    for ( int i=0; i<N; i++ ) {
        if ( board[i][i] == computersign )
            ro++;
        else if ( board[i][i] == humansign )
            ro--;
        if ( board[i][N-i-1] == computersign )
            co++;
        else if ( board[i][N-i-1] == humansign )
            co--;
    }
    if ( ro == N || co == N )
        return 10;
    if ( ro == -(N) || co == -(N) )
        return -10;
    // check for incompleteness
    for ( int i=0; i<N*N; i++ ) {
        if ( board[i/N][i%N] == '_' )
            return 1;
    }
    // else it's a draw
    return 0;
}

int minimax( int depth, _Bool isMax ) {
    int chk = checkwin();
    if ( chk == 10 ) {
        return chk - depth;
    } else if ( chk == 0 || chk == -10 ) {
        return chk + depth;
    }
    int val;
    int bestVal;
    if ( isMax ) {
        bestVal = -20;
        for ( int i=0; i<N*N; i++ ) {
            if ( board[i/N][i%N] == '_' ) {
                board[i/N][i%N] = computersign;
                val = minimax( depth+1, false );
                board[i/N][i%N] = '_';
                bestVal = max( bestVal, val );
            }
        }
    }
    else {
        bestVal = 20;
        for ( int i=0; i<N*N; i++ ) {
            if ( board[i/N][i%N] == '_' ) {
                board[i/N][i%N] = humansign;
                val = minimax( depth+1, true );
                board[i/N][i%N] = '_';
                bestVal = min( bestVal, val );
            }
        }
    }
    return bestVal;
}

int findBestMove() {
    int bestMove = -1;
    int bestVal;
    int val;
    for ( int i=0; i<N*N; i++ ) {
        if ( board[i/N][i%N] == '_' ) {
            bestMove = i;
            board[i/N][i%N] = computersign;
            bestVal = minimax(0, false);
            board[i/N][i%N] = '_';
        }
    }
    if ( bestMove == -1 )
        return -1;
    for ( int i=0; i<N*N; i++ ) {
        if ( board[i/N][i%N] == '_' ) {
            board[i/N][i%N] = computersign;
            val = minimax(0, false);
            board[i/N][i%N] = '_';
            if ( val > bestVal ) {
                bestVal = val;
                bestMove = i;
            }
        }
    }
    return bestMove;
}
/* Main Computational Part of the Game ENDS !! */

/* The FrontEND part of the Game Begins */
// start Menu we see
int startmenu() {
    char c;
    system("clear");
    printf("----------------------------\n");
    printf("       Tic Tac Toe\n");
    printf("----------------------------\n\n");
    printf("Enter a number from 1 to 5\nMake Your Choice:\n");
    printf("1.> Start the game\n");
    printf("2.> Score Summary\n");
    printf("3.> Help\n");
    printf("4.> About\n");
    printf("5.> Exit\n");
    system("/bin/stty raw");
    c = getchar();
    system("/bin/stty cooked");
    system("clear");
    if ( c > '0' && c < '6' )
        return c - '0';
    return 0;
}

// show scores
int scores() {
    system("clear");
    char c;
    printf("Games Played   : %d\n", computerwin+humanwin+bothwin);
    printf("You won        : %d\n", humanwin);
    printf("Computer won   : %d\n", computerwin);
    printf("Draw games     : %d\n\n", bothwin);
    printf("Press 0 to reset and Exit\n");
    printf("Press any other key to Exit\n");
    system("/bin/stty raw");
    c = getchar();
    system("/bin/stty cooked");
    system("clear");
    if ( c == '0' ) {
        computerwin = 0;
        humanwin = 0;
        bothwin = 0;
    }
    return 0;
}

// show help Menu
int help() {
    system("clear");
    printf("Your sign is '%c' . Make three consecutive '%c'\n", humansign, humansign);
    printf("in a row or in a column or diagonally .\n");
    printf("Input is two integers separated by space\n");
    printf("x y : coordinates where you put your 'x'\n");
    printf("in that move . Your opponant is my \n");
    printf("algorithm , A simple A.I.\n");
    printf("HAppy Thinking\n");
    printf("\nPress any key to exit\n");
    system("/bin/stty raw");
    getchar();
    system("/bin/stty cooked");
    system("clear");
    return 0;
}

// about the author
int about() {
    system("clear");
    printf("---------V 1.0---------\n");
    printf("   Tic Tac Toe Game\n");
    printf("-----------------------\n\n");
    printf("Vivek Kumar Gupta\n");
    printf("B.Tech 1st Year\n");
    printf("2018-2019\n\n");
    printf("Imagination is more important than Knowledge. ~ Albert Einstein\n\n");
    printf("Press any key to exit\n");
    system("/bin/stty raw");
    getchar();
    system("/bin/stty cooked");
    system("clear");
    return 0;
}

// write the updated scores to file
void writedata() {
    FILE *fp;
    fp = fopen("scoreTTT.txt", "w");
    fprintf(fp, "%d\n", computerwin);
    fprintf(fp, "%d\n", humanwin);
    fprintf(fp, "%d\n", bothwin);
    fprintf(fp, "%s\n", "This file contains Data for The Tic Tac Toe Game.");
    fclose(fp);
}

// print Board Status
void printBoard() {
    printf("Current Game Status ->\n");
    printf("    +   +\n");
    printf("  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("+---+---+---+\n");
    printf("  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("+---+---+---+\n");
    printf("  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("    +   +\n");
}

// Function For Computer to Decide And Make His Move
// It uses the above computational Functions
void computermove() {
    int res = findBestMove();
    if ( res == -1 ) {
        printf("An Error Occured\nNo Move Left\n");
    } else {
        board[res/N][res%N] = computersign;
        printf("Computer Made Her Move at Row: %d and Column : %d\n", res/N, res%N);
    }
}

// Human Move GUI
void humanmove() {
    int x, y;
    while ( 1 ) {
        printf("HUMAN move -> ");
        scanf("%d %d", &x, &y);
        if ( x>=N || x<0 || y>=N || y<0 ) { // array Index Bound
            printf("Wrong Move\n");
            printf("Please Write Non-Negative Values less than 3\n");
        } else if ( board[x][y] != '_' ) { // Board Empty Bound
            printf("Wrong Move\n");
            printf("You Can't Write There\n");
            printf("Cell Not Empty\n");
        } else {
            board[x][y] = humansign;
            printf("HUMAN made their move at Row : %d and Column : %d\n", x, y);
            break;
        }
    }
}

// Main Play Game Function
int playgame() {
    system("clear");
    for ( int i=0; i<N*N; i++ ) {
        board[i/N][i%N] = '_';
    }
    printf("Tossing A coin to start the Game.\n");
    int x = rand()%2;
    if ( x==0 ) {
        printf("  ->  Computer Won\n");
    } else {
        printf("  ->  You Won\n");
    }
    printf("Press <ENTER> to start the Game.\n");
    getchar();
    printf("Human ! Enter -> x y <- as your move\n");
    printf("Coordinates where you want your sign.\n");
    int game;
    while ( 1 ) {
        printBoard();
        game = checkwin();
        if ( game == 10 ) {
            printf("\nComputer Won !!\n");
            computerwin++;
            break;
        } else if ( game == -10 ) {
            printf("\nCongratulations !!\nYou WON !\n");
            humanwin++;
            break;
        } else if ( game == 0 ) {
            printf("\nGame Draw\n -> No one Win\n");
            bothwin++;
            break;
        }
        if ( x==0 ) {
            computermove();
            x = 1;
        } else {
            humanmove();
            x = 0;
        }
    }
    printf("Press <ENTER> to continue to MENU\n");
    getchar();
    getchar();
    writedata();
}

int main()
{
    board = (char**)malloc(N * sizeof(char*));
    for ( int i=0; i<N; i++ ) {
        board[i] = (char*)malloc(N * sizeof(char));
    }
    srand(time(0));
    FILE *fp;
    fp = fopen("scoreTTT.txt", "r");
    if ( fp != NULL ) {
        fscanf(fp, "%d", &computerwin);
        fscanf(fp, "%d", &humanwin);
        fscanf(fp, "%d", &bothwin);
    }
    fclose(fp);
    int choice;
    choice = startmenu();
    while ( 1 ) {
        switch ( choice ) {
            case 0 :
                choice = startmenu();
                break;
            case 1 :
                choice = playgame();
                break;
            case 2 :
                choice = scores();
                break;
            case 3 :
                choice = help();
                break;
            case 4 :
                choice = about();
                break;
            case 5 :
                printf("Thanks For Playing :)\n");
                writedata();
                for (int i=0; i<N; i++)
                    free(board[i]);
                free(board);
                return 0;
        }
    }
    return 0;
}
