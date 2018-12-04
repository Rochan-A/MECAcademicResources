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

	struct node *stack;
	stack = (struct node *)malloc(sizeof(struct node *));
	int v, r;
	printf("Enter the first value to push into the stack:");
	scanf("%d", &v);
	init(stack, v);

	char a[100];
	printf("Enter the math expression:\n");
	scanf("%s", a);

	for(int i = 0; a[i] != '\0'; i++){
		if(a[i] == '{' || a[i] == '[' || a[i] == '('){
			struct node *element;
			element = (struct node *)malloc(sizeof(struct node *));
			push(element, a[i]);
		}else if(a[i] == '}' && top == '{'){
			r = pop();
		}else if(a[i] == ']' && top == '['){
			r = pop();
		}else if(a[i] == ')' && top == '('){
			r = pop();
		}
	}

}