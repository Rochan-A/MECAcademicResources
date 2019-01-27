#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int bubblesortiscute(int *a, int g){
	int n = 100;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			g++;
			if(a[j]<a[j+1]){
				continue;
			}else{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	return g;
}

int insertionsortiscuter(int *array, int g){
	int n = 100;
	for(int i = 0; i < n; i++){
		int low = i;
		for(int j = i+1; j < n; j++){
			g++;
			if(array[low] > array[j]){
				low = j;
			}
		}
		int temp = array[low];
		array[low] = array[i];
		array[i] = temp;
	}
	return g;
}

int selectionsortiscuter(int *array, int g){
	int n = 100;
	for(int i = 0; i < n; i++){
		int low = i;
		for(int j = i+1; j < n; j++){
			g++;
			if(array[low] > array[j]){
				low = j;
			}
		}
		int temp = array[low];
		array[low] = array[i];
		array[i] = temp;
	}
	return g;
}

void main(){

	srand(time(NULL));
	int array_b[100], array_s[100], array_i[100];

	for(int j = 0; j <= 100; j++){
		array_b[j] = rand()%1000;
	}

	for(int j = 0; j <= 100; j++){
		array_s[j] = array_b[j];
		array_i[j] = array_s[j];
	}

	int b = 0, s = 0, i = 0;

	b = bubblesortiscute(array_b, b);
	i = insertionsortiscuter(array_i, i);
	s = selectionsortiscuter(array_s, s);

	printf("Number of comparisions for bubble: %d, selection: %d, insersion: %d\n", b, s, i);
}