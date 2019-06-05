/* Simple Multiplication Gmae For Kids 
 * And Adults as well
 *
 * Multiply two numbers between 1 and 100*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int scoreMG = 0;

int main() {
	int a, b, c = 0;
	system("clear");
	printf("-----------The Multiplication Game----------\n\n\n");
	printf(".............................................\n");
	printf("=> Enter -1 To Exit\n\n");
	printf("And Here We Begin...\n\n");
	while(c != -1){
		srand(time(0));
		a = rand()%100+1;
		b = rand()%100+1;
		printf("MULTIPLY %d And %d\n", a, b);
		scanf("%d", &c);
		system("clear");
		if(c == a*b){
			scoreMG++;
			if(scoreMG < 5)				 printf("      Correct");
			if(scoreMG>=5 && scoreMG<10) printf("*     Good!\n");
			if(scoreMG>=10 && scoreMG<20)printf("**    Wonderful!!\n");
			if(scoreMG>=20 && scoreMG<30)printf("***   Excellent!!!\n");
			if(scoreMG>=30)				 printf("***** Outstanding !!!!!\n");
			printf("\n%d in a row\nTry This\n", scoreMG);
//			printf("%d\n", clock());
		}else{
			while(c!=(a*b) && c!=-1){
				scoreMG=0;
				printf("Wrong Answer\nYou can Do Better\n");
				printf("-1 To EXIT!!!\n");
				printf("MULTIPLY %d And %d\n", a, b);
				scanf("%d", &c);
				system("clear");
				if(c == a*b) printf("      Correct\n%d in a row\nTry This\n", ++scoreMG);
			}
		}
	}
	return 0;
}
