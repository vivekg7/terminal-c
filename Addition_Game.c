/* Simple Addition Game For Kids
 * 
 * Add Two numbers between 1 and 100*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int scoreAG = 0;

int main() {
	int a, b, c = 0;
	system("clear");
	printf("-----------The Addition Game----------\n\n\n");
	printf(".......................................\n");
	printf("=> Enter -1 To Exit\n\n");
	printf("And Here We Begin...\n\n");
	while(c != -1){
		srand(time(0));
		a = rand()%100+1;
		b = rand()%100+1;
		printf("ADD %d And %d\n", a, b);
		scanf("%d", &c);
		system("clear");
		if(c == a+b){
			scoreAG++;
			if(scoreAG < 5)				 printf("      Correct");
			if(scoreAG>=5 && scoreAG<10) printf("*     Good!\n");
			if(scoreAG>=10 && scoreAG<20)printf("**    Wonderful!!\n");
			if(scoreAG>=20 && scoreAG<30)printf("***   Excellent!!!\n");
			if(scoreAG>=30)				 printf("***** Outstanding !!!!!\n");
			printf("\n%d in a row\nTry This\n", scoreAG);
//			printf("%d\n", clock());
		}else{ // Till the answer is not correct
			while(c!=(a+b) && c!=-1){
				scoreAG = 0;
				printf("Wrong Answer\nYou can Do Better\n");
				printf("-1 To EXIT!!!\n");
				printf("ADD %d And %d\n", a, b);
				scanf("%d", &c);
				system("clear");
				if(c == a+b) printf("      Correct\n%d in a row\nTry This\n", ++scoreAG);
			}
		}
	}
	return 0;
}
