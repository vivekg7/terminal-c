//For Infinite Player with char
//Best with Scores
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max_score = 0, max_tile = 0;
int score2048 = 0, tile_n = 2;

int checkgameover(int** mat);

void randomy(int** mat);

void pushright(int** mat);

void pushleft(int** mat);

void pushdown(int** mat);

void pushup(int** mat);

void ArrowKey(int** mat);

char interface();

char instructions();

char highscore();

char update_score();

char interface2(int** mat);

char playGame();

int main()
{
    system("clear");
    FILE *fp;
    fp = fopen("score2048.txt", "r");
    if(fp != NULL){
        fscanf(fp, "%d", &max_score);
        fscanf(fp, "%d", &max_tile);
    }
    fclose(fp);
    char choice;

    choice = interface();

    while(1){
        switch(choice){
            case '1' : choice = playGame(); break;
            case '2' : choice = instructions(); break;
            case '3' : choice = highscore(); break;
            case '4' : printf("Thanks A Lot!! For Being With Me.\nWe had fun Together\n\n\n"); return 0;
            case '5' : choice = interface(); break;
            case 'h' : choice = update_score(); break;
            default : printf("Please enter valid choice!! ");
                      choice = interface();
        }
    }

    return 0;
}

char interface(){
    char choice;
    printf("\n   ----version 1.0----\n\n");
    printf("-----------|2048|------------\n\n");

    printf("1 ---> New game!\n");
    printf("2 ---> Instructions\n");
    printf("3 ---> High Score\n");
    printf("4 ---> Exit\n\n");

    printf("What would you like to do? ");
    
    system("/bin/stty raw");
    choice = getchar();
    system("/bin/stty cooked");

    system("clear");
    return choice;
}

char highscore(){
    system("clear");
    printf("-----High Scores-----\n\n");
    printf("Maximum Tile Made: %d\n", max_tile);
    printf("Maximum Score:     %d\n\n", max_score);
    printf("Press <ENTER> to continue\n");
    getchar();
    system("clear");
    return '5';
}

char update_score(){
    max_tile = max_tile>tile_n ? max_tile:tile_n;
    max_score = max_score>score2048 ? max_score:score2048;
    FILE *fp;
    fp = fopen("score2048.txt", "w");
    fprintf(fp, "%d\n", max_score);
    fprintf(fp, "%d\n", max_tile);
    fprintf(fp, "%s\n", "This file contains Data for 2048 terminal game.");
    fclose(fp);
    return '5';
}

char instructions(){
    system("clear");
    printf("2048 is played on a gray 4 X 4 grid,\n");
    printf("with numbered tiles that slide smoothly when a player moves them using the four arrow keys.\n");
    printf("Every turn, a new tile will randomly appear in an empty spot on the board with a value of either 2 or 4.\n");
    printf("Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid.\n");
    printf("If two tiles of the same number collide while moving,\n");
    printf("they will merge into a tile with the total value of the two tiles that collided.\n");
    printf("Use number keys 2, 4, 6, 8 to make your move.\n\n");
    printf("Press <ENTER> to continue.\n");
    getchar();
    system("clear");
    return '5';
}

char interface2(int** mat){
    printf("+----+----+----+----+\n");
    for(int i = 0; i < 4; i++){
	if(mat[0][i] == '*') printf("|    ");
	else printf("|%4d", mat[0][i]);
    }
    printf("|\n");

    printf("+----+----+----+----+\n");
    for(int i = 0; i < 4; i++){
	if(mat[1][i] == '*') printf("|    ");
	else printf("|%4d", mat[1][i]);
    }
    printf("|\n");

    printf("+----+----+----+----+\n");
    for(int i = 0; i < 4; i++){
	if(mat[2][i] == '*') printf("|    ");
	else printf("|%4d", mat[2][i]);
    }
    printf("|\n");

    printf("+----+----+----+----+\n");
    for(int i = 0; i < 4; i++){
	if(mat[3][i] == '*') printf("|    ");
	else printf("|%4d", mat[3][i]);
    }
    printf("|\n");

    printf("+----+----+----+----+\n");

    char command;
    system("/bin/stty raw");
    command = getchar();
    system("/bin/stty cooked");
    system("clear");
    return command;
}

char playGame(){

    printf("===> Use keys 2, 4, 6, 8 to Nevigate\n===> Press 0 or Q To Leave The Game\n\n");
    char command, result = '1';
    int **mat;

    mat = (int**)malloc(4*sizeof(int*));
    mat[0] = (int*)malloc(4*sizeof(int));
    mat[1] = (int*)malloc(4*sizeof(int));
    mat[2] = (int*)malloc(4*sizeof(int));
    mat[3] = (int*)malloc(4*sizeof(int));

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            mat[i][j] = '*';
        }
    }

    srand(time(0));
    int n=rand()%16 ,i=0;
    while(i<2){
	    if(mat[n/4][n%4]=='*'){
	        mat[n/4][n%4]=2;
	        i++;
	    }else n=rand()%16;
    }

    while(result == '1'){
        command = interface2(mat);

        if(command == '0'||command == 'Q'||command == 'q'){
            printf("Are you sure you want to leave the game? Y --> YES or Anything else ---> NO\n");
            system("/bin/stty raw");
            command = getchar();
            system("/bin/stty cooked");
            if(command == 'Y' || command == 'y'){
		        system("clear");
		        return interface();
            }else {
                system("clear");
		        continue;
	        }
        }else{
            switch(command){
                case '8': pushup(mat); if(checkgameover(mat)) return 'h'; randomy(mat); break;
                case '2': pushdown(mat); if(checkgameover(mat)) return 'h'; randomy(mat); break;
                case '4': pushleft(mat); if(checkgameover(mat)) return 'h'; randomy(mat); break;
                case '6': pushright(mat); if(checkgameover(mat)) return 'h'; randomy(mat); break;
                case 27 : ArrowKey(mat); if(checkgameover(mat)) return 'h'; randomy(mat); break;
                default : printf("Please enter valid command! \n"); break;
            }
        }
    }
    return '4';
}

void randomy(int** mat){
	srand(time(0));
	int n = rand()%16;
	while(1){
		if(mat[n/4][n%4]=='*'){
			if(rand()%2) mat[n/4][n%4]=4;
			else mat[n/4][n%4]=2;
			return ;
		}
		n=rand()%16;
	}
}

int checkgameover(int** mat){
	int flag = 0, max = 2;
	for(int i=0; i<16; i++){
		if(mat[i/4][i%4] == '*') flag = 1;
		else if(mat[i/4][i%4] > max) max = mat[i/4][i%4];
	}
	if(flag){
		printf("Highest Tile %d\n\n", max);
		printf("Current Score : '%d'\n\n", score2048);
		return 0;
	}
	system("clear");
	printf("NO MOVES LEFT\n\nGAME OVER!!!!\n\n");
	printf("Congratulations!! You Made Highest Tile %d\n\nAnd Scored %d\n\n", max, score2048);
    tile_n = max;
	return 1;
}

void ArrowKey(int** mat){
	char ch;
	ch = getchar();
	ch = getchar();
	switch(ch){
		case 65: pushup(mat); return;
		case 66: pushdown(mat); return;
		case 67: pushright(mat); return;
		case 68: pushleft(mat); return;
	}
}

void pushright(int** mat){
	int k, point;
	for(int i=0; i<4; i++){
		point = 3;
		k = '*';
		for(int j=3; j>=0; j--){
			if(j == 0 && mat[i][j] == '*'){
				mat[i][point] = k;
			}else if(k != '*' && mat[i][j] == k){
				mat[i][j] = '*';
				mat[i][point--] = 2*k;
				score2048 += 2*k;
				k = '*';
			}else if(k != '*' && mat[i][j] != '*'){
				mat[i][point--] = k;
				k = mat[i][j];
				mat[i][j] = '*';
				if(j == 0) mat[i][point] = k;
			}else if(k == '*' && mat[i][j] != '*'){
				if(j == 0){
					k = mat[i][j];
					mat[i][j] = '*';
					mat[i][point] = k;
				}else{
					k = mat[i][j];
					mat[i][j] = '*';
				}
			}
		}
	}
}

void pushleft(int** mat){
	int k, point;
	for(int i=0; i<4; i++){
		point = 0;
		k = '*';
		for(int j=0; j<4; j++){
			if(j == 3 && mat[i][j] == '*'){
				mat[i][point] = k;
			}else if(k != '*' && mat[i][j] == k){
				mat[i][j] = '*';
				mat[i][point++] = 2*k;
				score2048 += 2*k;
				k = '*';
			}else if(k != '*' && mat[i][j] != '*'){
				mat[i][point++] = k;
				k = mat[i][j];
				mat[i][j] = '*';
				if(j == 3) mat[i][point] = k;
			}else if(k == '*' && mat[i][j] != '*'){
				if(j == 3){
					k = mat[i][j];
					mat[i][j] = '*';
					mat[i][point] = k;
				}else{
					k = mat[i][j];
					mat[i][j] = '*';
				}
			}
		}
	}
}

void pushdown(int** mat){
	int k, point;
	for(int i=0; i<4; i++){
		point = 3;
		k = '*';
		for(int j=3; j>=0; j--){
			if(j == 0 && mat[j][i] == '*'){
				mat[point][i] = k;
			}else if(k != '*' && mat[j][i] == k){
				mat[j][i] = '*';
				mat[point--][i] = 2*k;
				score2048 += 2*k;
				k = '*';
			}else if(k != '*' && mat[j][i] != '*'){
				mat[point--][i] = k;
				k = mat[j][i];
				mat[j][i] = '*';
				if(j == 0) mat[point][i] = k;
			}else if(k == '*' && mat[j][i] != '*'){
				if(j == 0){
					k = mat[j][i];
					mat[j][i] = '*';
					mat[point][i] = k;
				}else{
					k = mat[j][i];

					mat[j][i] = '*';
				}
			}
		}
	}
}

void pushup(int** mat){
	int k, point;
	for(int i=0; i<4; i++){
		point = 0;
		k = '*';
		for(int j=0; j<4; j++){
			if(j == 3 && mat[j][i] == '*'){
				mat[point][i] = k;
			}else if(k != '*' && mat[j][i] == k){
				mat[j][i] = '*';
				mat[point++][i] = 2*k;
				score2048 += 2*k;
				k = '*';
			}else if(k != '*' && mat[j][i] != '*'){
				mat[point++][i] = k;
				k = mat[j][i];
				mat[j][i] = '*';
				if(j == 3) mat[point][i] = k;
			}else if(k == '*' && mat[j][i] != '*'){
				if(j == 3){
					k = mat[j][i];
					mat[j][i] = '*';
					mat[point][i] = k;
				}else{
					k = mat[j][i];
					mat[j][i] = '*';
				}
			}
		}
	}
}

