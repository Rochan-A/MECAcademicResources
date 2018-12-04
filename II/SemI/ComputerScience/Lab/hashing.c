#include <stdlib.h>
#include <stdio.h>

void hash(int *a, int h){

	int t = h % 20;
	while (a[t] != 0){
		t = t + 1;
		if(t > 20){
			t = 0;
		}
	}
	a[t] = h;
}

void linear(int *a, int y){

	int t = y % 20;
	while (a[t] != y){
		t = t + 1;
		if(t > 20){
			t = 0;
		}
	}
	printf("%d\n", t);
}

void main(){

	int a[20];

	for(int i = 0; i < 20; i++){
		a[i] = 0;
	}

	int e;
	printf("Enter the number of entries:\n");
	scanf("%d", &e);

	for(int i = 0; i < 5; i++){
		int h;
		printf("Enter a number:\n");
		scanf("%d", &h);
		hash(a, h);
	}

	for(int i = 0; i < 20; i++){
		printf("%d\n", a[i]);
	}

	int y;
	printf("Enter a number to search for:\n");
	scanf("%d", &y);

	linear(a, y);
}

