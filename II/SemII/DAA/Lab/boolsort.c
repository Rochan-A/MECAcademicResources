#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void main(){

	srand(time(NULL));
	int array[10];

	for(int j = 0; j <= 10; j++){
		array[j] = rand()%95 + 5;
		printf("%d ", array[j]);
	}
	printf("\n");

	int max = 0;
	for(int j = 0; j <= 10; j++){
		if(array[j] > max){
			max = array[j];
		}
	}
	printf("Max %d\n", max);

	//int *a = (int *)malloc(max*sizeof(int));
	int a[100];

	for(int j = 0; j < max; j++){
		a[j] = 0;
	}

	for(int j = 0; j < 10; j++){
		a[array[j] - 1] = 1;
	}

	for(int j = 0; j < max; j++){
		if(a[j] == 1){
			printf("%d ", j+1);
		}
	}
}