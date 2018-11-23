#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void search(int *array, int low, int high, int value, int order){

	int inc = (high - low)/order;
	printf("inc is %d\n", inc);

	for(int i = 0; i < order; i++){
		if(array[low + (i+1)*inc] > value){
			search(array, low + (i*inc), low + (i+1)*inc, value, order);
		}else if(array[low + (i+1)*inc] < value){
			search(array, low + 1 + (i+1)*inc, low + (i+2)*inc, value, order);
		}else{
			printf("Search index is %d\n", low + (i+1)*inc);
			exit(0);
		}
	}
}

void main(){

	srand(time(NULL));
	int order = 0;
	printf("Enter the search order: ");
	scanf("%d", &order);

	int size = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);

	int *array = malloc(size*sizeof(int));

	int temp = 0;
	for(int i = 0; i < size; i++){
		printf("Enter the value for index %d: ", i);
		scanf("%d", &temp);
		array[i] = temp;
	}

	int value = 0;
	printf("Enter the search value: ");
	scanf("%d", &value);

	search(array, 0, size, value, order);
}