/* Simple Remainder Finding Game
 *
 * find b % a
 * 0 < b < 101
 * 0 < a < 21 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scoreRG = 0;

int main(){
	int a, b, c = 0;
	system("clear");
	printf("-----------The Remainder Game----------\n\n\n");
	printf(".........................................\n");
	printf("=> Enter -1 To Exit\n\n");
	printf("Give only Remainder of The Division\n");
	printf("And Here We Begin...\n\n");
	while(c != -1){
		srand(time(0));
		a = rand()%20 + 1;
		b = rand()%100 + 1;
		printf("REMAINDER %d %% %d\n", b, a);
		scanf("%d", &c);
		system("clear");
		if(c == b%a){
			scoreRG++;
			if(scoreRG < 5)				 printf("      Correct\n");
			if(scoreRG>=5 && scoreRG<10) printf("*     Good!\n");
			if(scoreRG>=10 && scoreRG<20)printf("**    Wonderful!!\n");
			if(scoreRG>=20 && scoreRG<30)printf("***   Excellent!!!\n");
			if(scoreRG>=30)				 printf("***** Outstanding !!!!!\n");
			printf("\n%d in a row\nTry This\n", scoreRG);
//			printf("%d\n", clock());
		}else{
			while(c!=(b%a) && c!=-1){
				scoreRG = 0;
				printf("Wrong Answer\nYou can Do Better\n");
				printf("-1 To EXIT!!!\n");
				printf("REMAINDER  %d %% %d\n", b, a);
				scanf("%d",&c);
				system("clear");
				if(c == b%a) printf("      Correct\n%d in a row\nTry This\n", ++scoreRG);
			}
		}
	}
	return 0;
}
