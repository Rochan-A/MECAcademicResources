#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void init(struct node *new, int val){

	new->value = val;
	new->next = NULL;
	tail = new;
	head = new;
}

void add(struct node *new, int val){

	struct node *second = tail;
	tail->next = new;
	new->value = val;
	new->next = NULL;
	tail = new;
}

//int remove(){
//}

void display()
{
	struct node *temp;
	temp=head;
	printf("Now displaying values in the stack:\n");
	while(temp!=NULL){

		printf("%d\n",temp->value);
		temp=temp->next;

	}
}

int is_empty(){
	if (head == NULL){
		return 0;
	}else{
		return 1;
	}
}

void main(){
	int v;
	struct node *stack;
	stack = (struct node *)malloc(sizeof(struct node *));
	printf("Enter the first value to add to the Linked List:");
	scanf("%d", &v);
	init(stack, v);

	while(1){
		int input;
		printf("Enter your choice: ");
		scanf("%d", &input);

		if(input == 1){
			struct node *new;
			new = (struct node *)malloc(sizeof(struct node *));
			int val;
			printf("Enter the value to add to the Linked List:");
			scanf("%d", &val);
			add(new, val);
		}else if(input == 2){
			display();
		}else{
			printf("Invalid input\n");
		}
	}
}