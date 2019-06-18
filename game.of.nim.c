/* The Game of Nim
 * Famous Algorithm
 * see on wikipedia */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// these are scores
// no. of games they won
int computerwin = 0;
int humanwin = 0;

// start Menu we see
int startmenu() {
    char c;
    system("clear");
    printf("----------------------------\n");
    printf("       Game of Nim\n");
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
    printf("%d Games Played\n", computerwin+humanwin);
    printf("You won %d Games\n\n", humanwin);
    printf("Press 0 to reset and Exit\n");
    printf("Press any other key to Exit\n");
    system("/bin/stty raw");
    c = getchar();
    system("/bin/stty cooked");
    system("clear");
    if ( c == '0' ) {
        computerwin = 0;
        humanwin = 0;
    }
    return 0;
}

// show help Menu
int help() {
    system("clear");
    printf("Given a number of piles in which each pile\n");
    printf("contains some numbers of coins. In each turn,\n");
    printf("a player can choose only one pile and remove\n");
    printf("any number of stones (at least one) from that\n");
    printf("pile. The player who take the last coin is the winner.\n\n");
    printf("Press any key to exit\n");
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
    printf("   The Game of Nim\n");
    printf("-----------------------\n\n");
    printf("Vivek Kumar Gupta\n");
    printf("B.Tech 1st Year\n");
    printf("2018-2019\n\n");
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
    fp = fopen("scoreNIM.txt", "w");
    fprintf(fp, "%d\n", computerwin);
    fprintf(fp, "%d\n", humanwin);
    fprintf(fp, "%s\n", "This file contains Data for The Game of Nim.");
    fclose(fp);
}

/* Game Starts Now */

// check game over return 1
int gameover( int piles, char *pile ) {
    for (int i=0; i<piles; i++) {
        if ( pile[i] )
            return 0;
    }
    return 1;
}

// return cumulative XOR of numbers
int cxor( int x, char* ar ) {
    int xor = 0;
    for (int i=0; i<x; i++) {
        xor = xor ^ ar[i];
    }
    return xor;
}

// computer makes his move
void computermove( int piles, char *pile ) {
    int x, y=0; // x = index to change; y = amount to change
    if ( cxor( piles, pile ) == 0 ) {
        while ( 1 ) {
            x = rand()%piles;
            if ( pile[x] > 0 ) {
                pile[x]--;
                printf("COMPUTER removes 1 stone from pile %d\n", x+1);
                return ;
            }
        }
    }
    int pmax=1, max = 1;
    for ( int i=0; i<piles; i++ ) {
        if ( max < pile[i] ) {
            max = pile[i];
        }
    }
    printf("Max %d ", max);
    while ( pmax <= max ) {
        pmax = pmax * 2;
    }
    pmax = pmax / 2;
    printf("PMax %d\n", pmax);
    x = -1;
    while ( pmax ) {
        max = 0;
        for ( int i=0; i<piles; i++ ) {
            if ( (pile[i]&pmax) == pmax ) {
                max++;
            }
        }
        printf("<%d %d> ", max, pmax);
        if ( max%2 == 0 ) {
            pmax = pmax/2;
        }
        else {
            for ( int i=0; i<piles; i++ ) {
                if ( ((pile[i]&pmax) == pmax) ) {
                    x = i;
                    break;
                }
            }
        }
        if ( x >= 0 )
            break;
    }
    while ( cxor( piles, pile ) ) {
        pile[x]--;
        y++;
        if ( pile[x] < 0 ) {
            printf("Error Occured Captain!!! ;)\n");
            break;
        }
    }
    printf("COMPUTER removes %d stones from pile %d\n", y, x+1);
}

// You make Your Move
void humanmove( int piles, char *pile ) {
    int x, y;
    while ( 1 ) {
        printf("HUMAN move -> ");
        scanf("%d %d", &x, &y);
        if ( x > piles || y <= 0 || pile[x-1] < y ) {
            printf("HUMAN wrong move\n     try again\n");
        } else {
            printf("HUMAN removes %d stones from pile %d\n", y, x);
            pile[x-1] -= y;
            break;
        }
    }
}

// Main Play Game Function
int playgame() {
    system("clear");
    int piles;
    char c;
    printf("Enter Number of piles >= 3(Default 3): \n");
    system("/bin/stty raw");
    c = getchar();
    system("/bin/stty cooked");
    if ( c >= '3' && c <= '9' )
        piles = c - '0';
    else 
        piles = 3;
    printf("\nChoosing Random coins on the piles\n");
    char *pile;
    pile = (char*)malloc(piles * sizeof(char));
    for (int i=0; i<piles; i++) {
        pile[i] = (char)( rand()%8 + 3);
        printf("%d ", pile[i]);
    }
    printf("\nTossing A coin to start the Game.\n");
    c = (char)rand()%2;
    if ( c==0 ) {
        printf("  ->  Computer Won !!\n");
    }else {
        printf("  ->  You Won !!\n");
    }
    printf("Press <ENTER> to start the Game\n");
    getchar();
    getchar();
    printf("Human ! Enter 'n' 'm' as your move\n");
    printf("n = pile Index ; m = coins to remove\n");
    while ( 1 ) {
        printf("Current Game Status -> ");
        if ( gameover(piles, pile) ) {
            if ( c!=0 ) {
                printf("\nCOMPUTER won \n");
                computerwin++;
                break;
            }
            else {
                printf("\nYOU won\n");
                humanwin++;
                break;
            }
        }
        for (int i=0; i<piles; i++)
            printf("%d ", pile[i]);
        printf("\n");
        if ( c==0 ) {
            computermove( piles, pile );
            c = 1;
        } else {
            humanmove( piles, pile );
            c = 0;
        }
    }
    printf("Press <ENTER> to continue \n");
    getchar();
    getchar();
    free(pile);
    writedata();
    return 0;
}

int main()
{
    srand(time(0));
    FILE *fp;
    fp = fopen("scoreNIM.txt", "r");
    if (fp != NULL) {
        fscanf(fp, "%d", &computerwin);
        fscanf(fp, "%d", &humanwin);
    }
    fclose(fp);
    int choice;
    choice  = startmenu();
    while (1) {
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
                return 0;
        }
    }
    return 0;
}
