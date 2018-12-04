#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *head = NULL;

void init(struct node *new, int val){
	new->value = val;
	new->next = NULL;
	head = new;
}

void push_back(struct node *new, int val){
	struct node *temp, *prev;
	temp = head;
	while(temp != NULL){
		prev = temp;
		temp=temp->next;
	}
	new->value = val;
	new->next = NULL;
	prev->next = new;
}

void push_front(struct node *new, int val){
	new->value = val;
	new->next = head;
	head = new;
}

int pop_back(){
	struct node *temp, *prev;
	temp = head;
	while(temp != NULL){
		prev = temp;
		temp=temp->next;
	}
	prev->next = NULL;
	int a = prev->value;
	return a;
}

int pop_front(){
	int a = head->value;
	head = head->next;
	return a;
}

int find(int search){
	struct node *temp;
	temp = head;
	while(temp!=NULL){
		if(temp->value == search){
			return 1;
		}else{
			temp=temp->next;
		}
	}
	return 0;
}

void erase(){
	head = NULL;
}

int is_empty(){
	if(head == NULL){
		return 1;
	}else{
		return 0;
	}
}

void add_before(struct node *new, int val, int index){
	new->value = val;

	int pos = 0;
	struct node *temp, *prev;
	temp = head;
	while(temp!=NULL){
		if(pos == index){
			new->next = temp;
			prev->next = new;
			break;
		}
		prev = temp;
		temp=temp->next;
		pos++;
	}
}

void add_after(struct node *new, int val, int index){
	new->value = val;

	int pos = 0;
	struct node *temp;
	temp = head;
	while(temp!=NULL){
		if(pos == index){
			new->next = temp;
			temp = new;
			break;
		}
		temp=temp->next;
		pos++;
	}
}

void display(){
	struct node *temp;
	temp=head;
	printf("Now displaying values in the Linked List:\n");
	while(temp!=NULL){

		printf("%d\n",temp->value);
		temp=temp->next;

	}
}

void main(){

	int v;
	struct node *ll;
	ll = (struct node *)malloc(sizeof(struct node *));
	printf("Enter the first value to push into the Linked List:");
	scanf("%d", &v);
	init(ll, v);

	while(1){
		int input;
		printf("Enter your choice:\n \
			1:\tPush an element to the end of the linked list\n \
			2:\tPush an element to the front of the linked list\n \
			3:\tPop an element at the end of the linked list\n \
			4:\tPop an element at the front of the linked list\n \
			5:\tCheck if an element is in the linked list\n \
			6:\tEmpty the linked list\n \
			7:\tCheck if the linked list is empty\n \
			8:\tAdd an element before a node in the linked list\n \
			9:\tAdd an element after a node in the linked list\n \
			10:\tDisplay the Linked List\n");
		scanf("%d", &input);

		if(input == 1){
			struct node *element;
			element = (struct node *)malloc(sizeof(struct node *));
			int val;
			printf("Enter the value to push to the Linked list:");
			scanf("%d", &val);
			push_back(element, val);
		}else if(input == 2){
			struct node *element;
			element = (struct node *)malloc(sizeof(struct node *));
			int val;
			printf("Enter the value to push to the Linked list:");
			scanf("%d", &val);
			push_front(element, val);
		}else if(input == 3){
			int a = pop_back();
			printf("Value popped is: %d\n", a);
		}else if(input == 4){
			int a = pop_front();
			printf("Value popped is: %d\n", a);
		}else if(input == 5){
			int search;
			printf("Enter a value to search in the Linked list:");
			scanf("%d", &search);
			if(find(search) == 1){
				printf("The search value is present in the \
Linked List");
			}else{
				printf("The search value is not present in \
the Linked List");
			}
		}else if(input == 6){
			erase();
		}else if(input == 7){
			if(is_empty() == 1){
				printf("The linked list is empty\n");
			}else{
				printf("The linked list is not empty\n");
			}
		}else if(input == 8){
			struct node *element;
			element = (struct node *)malloc(sizeof(struct node *));
			int val, loc;
			printf("Enter the value to add to the Linked list:");
			scanf("%d", &val);
			printf("Enter the location before which to add:");
			scanf("%d", &loc);
			add_before(element, val, loc);
		}else if(input == 9){
			struct node *element;
			element = (struct node *)malloc(sizeof(struct node *));
			int val, loc;
			printf("Enter the value to add to the Linked list:");
			scanf("%d", &val);
			printf("Enter the location after which to add:");
			scanf("%d", &loc);
			add_after(element, val, loc);
		}else if(input == 10){
			display();
		}else{
			printf("Invalid choice\n");
		}
	}
}