#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *head = NULL;
int top = 0;

void init(struct node *new, int val){

	new->value = val;
	new->next = NULL;
	head = new;
}

void push(struct node *new, int val){

	struct node *second = head;
	new->value = val;
	head = new;
	new->next = second;
	top = val;
}

int pop(){
	int val = head->value;
	head = head->next;
	top = head->value;
	return val;
}

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
	printf("Enter the first value to push into the stack:");
	scanf("%d", &v);
	init(stack, v);

	while(1){
		int input;
		printf("Enter your choice:\n1:\tPush an element\n2:\tPop an element\n3:\tDisplay the top most value\n4:\tDisplay the stack\n");
		scanf("%d", &input);
		if(input == 1){
			struct node *element;
			element = (struct node *)malloc(sizeof(struct node *));
			int val;
			printf("Enter the value to push to the stack:");
			scanf("%d", &val);
			push(element, val);
		}else if(input == 2){
			int a = pop();
			printf("The popped value is %d\n", a);
		}else if(input == 3){
			printf("The top most value is %d\n", top);
		}else if(input == 4){
			display();
		}else{
			printf("Invalid choice\n");
		}
	}
}