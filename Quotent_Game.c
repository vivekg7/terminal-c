/* Simple Quotent Game
 *
 * Quotent of b / a
 * 0 < b < 101  && 0 < a < 21 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scoreQG = 0;

int main(){
	int a, b, c = 0;
	system("clear");
	printf("-----------The Quotent Game----------\n\n\n");
	printf(".......................................\n");
	printf("=> Enter -1 To Exit\n\n");
	printf("Give only Integer Part of The Division\n");
	printf("And Here We Begin...\n\n");
	while(c != -1){
		srand(time(0));
		a = rand()%20 + 1;
		b = rand()%100 + 1;
		printf("QUOTENT OF %d / %d\n", b, a);
		scanf("%d",&c);
		system("clear");
		if(c == b/a){
			scoreQG++;
			if(scoreQG < 5)				 printf("      Correct\n");
			if(scoreQG>=5 && scoreQG<10) printf("*     Good!\n");
			if(scoreQG>=10 && scoreQG<20)printf("**    Wonderful!!\n");
			if(scoreQG>=20 && scoreQG<30)printf("***   Excellent!!!\n");
			if(scoreQG>=30)				 printf("***** Outstanding !!!!!\n");
			printf("\n%d in a row\nTry This\n", scoreQG);
//			printf("%d\n", clock());
		}else{
			while(c!=(b/a) && c!=-1){
				scoreQG = 0;
				printf("Wrong Answer\nYou can Do Better\n");
				printf("-1 To EXIT!!!\n");
				printf("QUOTENT OF %d / %d\n", b, a);
				scanf("%d",&c);
				system("clear");
				if(c == b/a) printf("      Correct\n%d in a row\nTry This\n", ++scoreQG);
			}
		}
	}
	return 0;
}
