#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int i;
	struct Node* ptr;
} Node;

Node* makeNodes(int n);
Node* addNode(Node *ptrNode);

int main(){
	system("clear");
	int n, m, current = 1, dest;
	Node *temp;
	printf("-----------------------------------------------\n");
	printf("Enter the Number of Nodes in the Linked List: ");

	scanf("%d", &n);
	printf("\n-----------------------------------------------\n");

	Node *Head = makeNodes(n);
	Node *ptrNode = Head;
	m = 0;

	while(m != 5){
		printf("What would you like to do? Current node is node %d.\n", current);
		printf("1--> Change data stored at curent node.\n");
		printf("2--> Print the data stored at current node.\n");
		printf("3--> Traverse between nodes.\n");
		printf("4--> Add a new node.\n");
		printf("5--> Exit.\n");

		scanf("%d", &m);

		switch(m){
			case 1:
				printf("-----------------------------------------------\n");
				printf("Enter the value you want to store in node %d: ", current);
				scanf("%d", &(ptrNode->i));
				printf("\n-----------------------------------------------\n");
				break;
			case 2:
				printf("------------------------------------------------\n");
				printf("Data stored at current node is: %d", ptrNode->i);
				printf("\n------------------------------------------------\n");
				break;
			case 3:
				printf("-------------------------------------------------\n");
				printf("Which node would you like to access now? (1~%d) ", n);
				scanf("%d", &dest);
				current = dest;
				printf("New current node is: '%d'", current);
				printf("\n-------------------------------------------------\n");
				ptrNode = Head;
				for(int j = 1; j < dest; j++) ptrNode = ptrNode->ptr;
				break;
			case 4:
				printf("-------------------------------------------------\n");
				printf("New node has been successfully added to the list!\n");
				printf("Total number of nodes in the linked list is: '%d'\n", ++n);
				printf("-------------------------------------------------\n");
				ptrNode->ptr = addNode(ptrNode->ptr);
				++current;
				break;
		}
	}
	return 0;
}

Node* makeNodes(int n){
	Node* qtr = (Node*)malloc(sizeof(Node));
	if(n<1) return NULL;
	else{
		qtr->i = 0;
		qtr->ptr = makeNodes(--n);
	}
	return qtr;
}

Node* addNode(Node *ptrNode){
	Node* qtr = (Node*)malloc(sizeof(Node));
	qtr->i = 0;
	qtr->ptr = ptrNode;
	return qtr;
}
