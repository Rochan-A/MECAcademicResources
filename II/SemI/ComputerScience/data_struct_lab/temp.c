
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *next;
}Node;

Node *top = NULL;


void push(int value){

Node *temp;
temp = malloc(sizeof(Node *));
temp->data=value;
temp->next=top;
top=temp;
}

int pop(){


int a = top->data;
top = top->next;
return a;

}

int topp(){
if(top != NULL){
int a = top->data;
return a;
}
}


int isitempty(){
if(top==NULL){
printf("EMPTYYY LISTTT\n");

}

else{

printf("NOT AN EMPTY LIST\n");
}

}





int main(){

while(1){
printf("1.push\n");
printf("2.pop\n");
printf("3.show the topmost member\n");
printf("4.to check if the stack is empty\n");

int x, y;
printf("Enter what you want\n");
scanf("%d",&x);

switch(x){

case 1: printf("Enter what you want to push\n");
scanf("%d", &y);
push(y);
break;
case 2: pop();
break;
case 3: printf("Top value of the stack = %d\n", topp());
break;
case 4: isitempty();

}

}



}
