// There is a problem with the input
// How to take input as well as let the program run simultaneously
//
// you need to press key each time for the snake to move

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char Exit();

void instructions();

char interface();

void GameInfinite();

void GameWall();

int Increase = 0, scoreS;

void PrintScreen(char **mat);

void randomfruit(char **mat);

char inputfun(char Dir);

void addto(char Dir, char **mat, int *Snake, int snaker);

void donotadd(char Dir, char **mat, int *Snake, int snaker);

int SnakeMoves(char Dir, char **mat, int *Snake, int snaker);

int SnakeMoveswhy(char Dir, char **mat, int *Snake, int snaker);

int main(){
	char choice;
	
	system("clear");
	
	while(1){
		choice = interface();
		
		switch(choice){
		case '1': GameInfinite(); break;
		case '2': GameWall(); break;
		case '3': instructions(); break;
		case '4': choice = Exit(); if(choice != '0') return 0; break;
		default : system("clear"); printf("Please Enter a Valid Choice\n"); break;
		}
	}

	return 0;
}

char Exit(){
	char command;
	system("clear");
	printf("We Had Our Fun Together.\n\n");
	printf("Press 0 to Come Back\n");
	printf("Else Any Key to Exit\n");
	system("/bin/stty raw");
	command = getchar();
	system("/bin/stty cooked");
	printf("\n");
	system("clear");
	return command;
}

char interface(){
	char command;
	printf("---------V0.1---------\n\n");
	printf("--+--SnakeSession--+--\n\n");
	printf("Enter:\n");
	printf("1 ==> Mode InfiniteWall\n");
	printf("2 ==> Mode ClosedWall\n");
	printf("3 ==> Instructions\n");
	printf("4 ==> Exit\n");
	system("/bin/stty raw");
	command = getchar();
	system("/bin/stty cooked");
	return command;
}

void instructions(){
	system("clear");
	char command;
	printf("Use 2, 4, 6, 8 to Nevigate\n");
	printf("You can Only Change Direction left or right\n");
	printf("Else the Snake Will be Default Forward\n");
	printf("Eat '*' to Gain Points and Increase Size\n");
	printf("Eat $ to Gain Point and not Increase Size\n");
	//Eat & to Gain Point and Decrease Size
	//Even Letters/Numbers can be included As Money
	//etc "TO BE INCLUDED"
	printf("Press '0' to Pause During The Game\n");
	printf("In ClosedWall mode DoNot Touch The Wall\n\n");
	printf("Press Any Key To Continue.\n");
	system("/bin/stty raw");
	command = getchar();
	system("/bin/stty cooked");
	system("clear");
}

void GameInfinite(){

	scoreS = 0;
	int Snake[96], snaker = 2;
	char **mat, Direction = '6';
	mat = (char**)malloc(8*sizeof(char*));

	for(int i = 0; i<8; i++){
		mat[i] = (char*)malloc(13*sizeof(char));
		mat[i][12] = '\0';
	}

	for(int i = 0; i < 96; i++)
		mat[i/12][i%12] = ' ';

	mat[4][4] = '+';
	mat[4][5] = '+';

	Snake[1] = 4*100 + 4;
	Snake[0] = 4*100 + 5;

	randomfruit(mat);

	while(1){
		system("clear");
		PrintScreen(mat);
		Direction = inputfun(Direction);
		snaker = SnakeMoveswhy(Direction, mat, Snake, snaker);
		if(snaker == 92){
			system("clear");
			printf("\nSCORED: '%d'\nYou Earned My Heart! Thank You!!\n\n", scoreS);
			break;
		}
		if(snaker == 0){
			system("clear");
			printf("\nSCORED: '%d'\nTAKE SOME REST\n\n", scoreS);
			break;
		}
		if(Increase){
			Increase = 0;
			randomfruit(mat);
		}
	}
}

void GameWall(){

	scoreS = 0;
	int Snake[96], snaker = 2;
	char **mat, Direction = '6';
	mat = (char**)malloc(8*sizeof(char*));

	for(int i = 0; i<8; i++){
		mat[i] = (char*)malloc(13*sizeof(char));
		mat[i][12] = '\0';
	}

	for(int i = 0; i < 96; i++)
		mat[i/12][i%12] = ' ';

	mat[4][4] = '+';
	mat[4][5] = '+';

	Snake[1] = 4*100 + 4;
	Snake[0] = 4*100 + 5;

	randomfruit(mat);

	while(1){
		system("clear");
		PrintScreen(mat);
		Direction = inputfun(Direction);
		snaker = SnakeMoves(Direction, mat, Snake, snaker);
		if(snaker == 92){
			system("clear");
			printf("\nSCORED: '%d'\nYou Earned My Heart! Thank You!!\n\n", scoreS);
			break;
		}
		if(snaker == 0){
			system("clear");
			printf("\nSCORED: '%d'\nTAKE SOME REST\n\n", scoreS);
			break;
		}
		if(Increase){
			Increase = 0;
			randomfruit(mat);
		}
	}
}

void PrintScreen(char **mat){
	printf("score: '%d'\n", scoreS);
	printf("################\n");
	for(int i = 0; i<8; i++){
		printf("||");
		printf("%s", mat[i]);
		printf("||\n");
	}
	printf("################\n");
}

void randomfruit(char **mat){
	srand(time(0));
	int n;
	while(1){
		n = rand()%96;
		if(mat[n/12][n%12] == ' '){
			mat[n/12][n%12] = '*';
			break;
		}
	}
	n = rand()%10;
	if(n == 5)
		while(1){
			n = rand()%96;
			if(mat[n/12][n%12] == ' '){
				mat[n/12][n%12] = '$';
				break;
			}
		}
}

char inputfun(char Dir){
	char newDir, flag = 1;
	while(1){
		system("/bin/stty raw");
		newDir = getchar();
		system("/bin/stty cooked");
		switch(newDir){
			case '0': if(flag){printf("\n----PAUSED----\n"); flag = 0;} break;
			case '2': if(Dir == '4'||Dir == '6') return newDir; return Dir;
			case '8': if(Dir == '4'||Dir == '6') return newDir; return Dir;
			case '4': if(Dir == '8'||Dir == '2') return newDir; return Dir;
			case '6': if(Dir == '8'||Dir == '2') return newDir; return Dir;
			case 'a': if(Dir == '8'||Dir == '2') return '4'; return Dir;
			case 's': if(Dir == '8'||Dir == '2') return '6'; return Dir;
			case 'z': if(Dir == '4'||Dir == '6') return '2'; return Dir;
			case 'w': if(Dir == '4'||Dir == '6') return '8'; return Dir;
			//case 21 : Arrow
			case 'q':
			case 'Q': return '0';
			default : return Dir;
		}
	}
	return Dir;
}

int SnakeMoves(char Dir, char **mat, int *Snake, int snaker){

	switch(Dir){
		case '0': return 0;
		case '2': if(Snake[0]/100 == 7) return 0;
				if(mat[Snake[0]/100 + 1][Snake[0]%100] == '+') return 0;
				if(mat[Snake[0]/100 + 1][Snake[0]%100] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
				if(mat[Snake[0]/100 + 1][Snake[0]%100] == '$') scoreS += 500;
				donotadd(Dir, mat, Snake, snaker); return snaker;
		case '8': if(Snake[0]/100 == 0) return 0;
				if(mat[Snake[0]/100 - 1][Snake[0]%100] == '+') return 0;
				if(mat[Snake[0]/100 - 1][Snake[0]%100] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
				if(mat[Snake[0]/100 - 1][Snake[0]%100] == '$') scoreS += 500;
				donotadd(Dir, mat, Snake, snaker); return snaker;
		case '4': if(Snake[0]%100 == 0) return 0;
				if(mat[Snake[0]/100][Snake[0]%100 - 1] == '+') return 0;
				if(mat[Snake[0]/100][Snake[0]%100 - 1] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
				if(mat[Snake[0]/100][Snake[0]%100 - 1] == '$') scoreS += 500;
				donotadd(Dir, mat, Snake, snaker); return snaker;
		case '6': if(Snake[0]%100 == 11) return 0;
				if(mat[Snake[0]/100][Snake[0]%100 + 1] == '+') return 0;
				if(mat[Snake[0]/100][Snake[0]%100 + 1] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
				if(mat[Snake[0]/100][Snake[0]%100 + 1] == '$') scoreS += 500;
				donotadd(Dir, mat, Snake, snaker); return snaker;
	}
	return snaker;
}

int SnakeMoveswhy(char Dir, char **mat, int *Snake, int snaker){

	switch(Dir){
		case '0': return 0;
		case '2': if(Snake[0]/100 == 7){
					if(mat[0][Snake[0]%100] == '+') return 0;
					if(mat[0][Snake[0]%100] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
					if(mat[0][Snake[0]%100] == '$') scoreS += 500;
					donotadd(Dir, mat, Snake, snaker); return snaker;
					}
				if(mat[Snake[0]/100 + 1][Snake[0]%100] == '+') return 0;
				if(mat[Snake[0]/100 + 1][Snake[0]%100] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
				if(mat[Snake[0]/100 + 1][Snake[0]%100] == '$') scoreS += 500;
				donotadd(Dir, mat, Snake, snaker); return snaker;
		case '8': if(Snake[0]/100 == 0){
					if(mat[7][Snake[0]%100] == '+') return 0;
					if(mat[7][Snake[0]%100] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
					if(mat[7][Snake[0]%100] == '$') scoreS += 500;
					donotadd(Dir, mat, Snake, snaker); return snaker;
					}
				if(mat[Snake[0]/100 - 1][Snake[0]%100] == '+') return 0;
				if(mat[Snake[0]/100 - 1][Snake[0]%100] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
				if(mat[Snake[0]/100 - 1][Snake[0]%100] == '$') scoreS += 500;
				donotadd(Dir, mat, Snake, snaker); return snaker;
		case '4': if(Snake[0]%100 == 0){
					if(mat[Snake[0]/100][11] == '+') return 0;
					if(mat[Snake[0]/100][11] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
					if(mat[Snake[0]/100][11] == '$') scoreS += 500;
					donotadd(Dir, mat, Snake, snaker); return snaker;
					}
				if(mat[Snake[0]/100][Snake[0]%100 - 1] == '+') return 0;
				if(mat[Snake[0]/100][Snake[0]%100 - 1] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
				if(mat[Snake[0]/100][Snake[0]%100 - 1] == '$') scoreS += 500;
				donotadd(Dir, mat, Snake, snaker); return snaker;
		case '6': if(Snake[0]%100 == 11){
					if(mat[Snake[0]/100][0] == '+') return 0;
					if(mat[Snake[0]/100][0] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
					if(mat[Snake[0]/100][0] == '$') scoreS += 500;
					donotadd(Dir, mat, Snake, snaker); return snaker;
					}
				if(mat[Snake[0]/100][Snake[0]%100 + 1] == '+') return 0;
				if(mat[Snake[0]/100][Snake[0]%100 + 1] == '*') {addto(Dir, mat, Snake, snaker); return snaker + 1;}
				if(mat[Snake[0]/100][Snake[0]%100 + 1] == '$') scoreS += 500;
				donotadd(Dir, mat, Snake, snaker); return snaker;
	}
	return snaker;
}

void addto(char Dir, char **mat, int *Snake, int snaker){
	scoreS += 100;
	Increase = 1;
	for(int i = snaker; i>0; i--)
		Snake[i] = Snake[i - 1];
	
	switch(Dir){
		case '2': if(Snake[1]/100 == 7) Snake[0] = Snake[1]%100;
				  else Snake[0] = Snake[1] + 100;
				  break;
		case '4': if(Snake[1]%100 == 0) Snake[0] = Snake[1] +11;
				  else Snake[0] = Snake[1] - 1;
				  break;
		case '6': if(Snake[1]%100 == 11) Snake[0] = (Snake[1]/100)*100;
				  else Snake[0] = Snake[1] + 1;
				  break;
		case '8': if(Snake[1]/100 == 0) Snake[0] = Snake[1] + 700;
				  else Snake[0] = Snake[1] - 100;
				  break;
	}
	mat[Snake[0]/100][Snake[0]%100] = '+';
}

void donotadd(char Dir, char **mat, int *Snake, int snaker){
	//printf("(%d)", Snake[snaker-1]);
	mat[Snake[snaker-1]/100][Snake[snaker-1]%100] = ' ';
	for(int i = snaker - 1; i>0; i--)
		Snake[i] = Snake[i - 1];
	
	switch(Dir){
		case '2': if(Snake[1]/100 == 7) Snake[0] = Snake[1]%100;
				  else Snake[0] = Snake[1] + 100;
				  break;
		case '4': if(Snake[1]%100 == 0) Snake[0] = Snake[1] +11;
				  else Snake[0] = Snake[1] - 1;
				  break;
		case '6': if(Snake[1]%100 == 11) Snake[0] = (Snake[1]/100)*100;
				  else Snake[0] = Snake[1] + 1;
				  break;
		case '8': if(Snake[1]/100 == 0) Snake[0] = Snake[1] + 700;
				  else Snake[0] = Snake[1] - 100;
				  break;
	}
	mat[Snake[0]/100][Snake[0]%100] = '+';
}
