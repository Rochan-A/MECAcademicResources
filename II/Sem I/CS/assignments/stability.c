#include <stdio.h>
#include <stdlib.h>

int h[10] = {3, 1, 5, 4, 2, 7, 9, 5, 6, 0};

void insertionsortiscute(int **a, int n){
	int i, j, boo[2];
	for(i = 1; i < n; i++){
		boo[0] = a[i][0];
		boo[1] = a[i][1];
		j = i - 1;
		while(j >= 0 && a[j][0] > boo[0]){
			a[j + 1][0] = a[j][0];
			a[j + 1][1] = a[j][1];
			j = j - 1;
		}
		a[j+1][0] = boo[0];
		a[j+1][1] = boo[1];
	}
}

void selectionsortiscuter(int **a, int len){
	for(int i = 0; i < len; i++){
		int low = i;
		for(int j = i+1; j < len; j++){
			if(a[low][0] > a[j][0]){
				low = j;
			}
		}
		int temp = a[low][0];
		int te = a[low][1];
		a[low][0] = a[i][0];
		a[low][1] = a[i][1];
		a[i][0] = temp;
		a[i][1] = te;
	}
}

void bubblesortiscute(int **a, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j][0] < a[j+1][0]){
				continue;
			}else{
				int temp = a[j][0];
				int te = a[j][1];
				a[j][0] = a[j+1][0];
				a[j][1] = a[j+1][1];
				a[j+1][0] = temp;
				a[j+1][1] = te;
			}
		}
	}
}

/*

void merging(int **a, int **b, int low, int mid, int high) {
	int l1, l2, i;

	for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
		if(a[l1][0] <= a[l2][0]){
			//b[i][0] = a[l1++][0];
			b[i][1] = a[l1++][1];
		}else{
			//b[i][0] = a[l2++][0];
			b[i][1] = a[l2++][1];
		}
	}

	while(l1 <= mid)
		b[i++][0] = a[l1++][0];
		//b[i++][1] = a[l1++][1];

	while(l2 <= high)
		b[i++][0] = a[l2++][0];
		//b[i++][1] = a[l2++][1];

	for(i = low; i <= high; i++)
		a[i][0] = b[i][0];
		//a[i][1] = b[i][1];
}

void sort(int **a, int **b, int low, int high) {
	int mid;

	if(low < high) {
		mid = (low + high) / 2;
		sort(a, b, low, mid);
		sort(a, b, mid + 1, high);
		merging(a, b, low, mid, high);
	}
}

*/

void main(){

	int **in = malloc(10*sizeof(int *));
	int **se = malloc(10*sizeof(int *));
	int **bu = malloc(10*sizeof(int *));

	for(int i = 0; i < 10; i++){
		in[i] = malloc(2*sizeof(int));
		se[i] = malloc(2*sizeof(int));
		bu[i] = malloc(2*sizeof(int));
	}

	for(int i = 0; i < 10; i++){
		in[i][1] = i;
		se[i][1] = i;
		bu[i][1] = i;

		in[i][0] = h[i];
		se[i][0] = h[i];
		bu[i][0] = h[i];
	}

	int **me = malloc(10*sizeof(int *));
	int **mn = malloc(10*sizeof(int *));

	for(int i = 0; i < 10; i++){
		me[i] = malloc(2*sizeof(int));
		mn[i] = malloc(2*sizeof(int));
	}

	for(int i = 0; i < 10; i++){
		me[i][1] = i;
		mn[i][0] = 0;
		mn[i][1] = 0;
		me[i][0] = h[i];
	}


	insertionsortiscute(in, 10);
	selectionsortiscuter(se, 10);
	bubblesortiscute(bu, 10);
	//sort(me, mn, 0, 10);

	printf("The original unsorted array:\n");
	for(int i = 0; i < 10; i++){
		printf("%d - %d\n", h[i], i);
	}

	printf("Insertion sort results:\n");
	for(int i = 0; i < 10; i++){
		printf("%d - %d\n", in[i][0], in[i][1]);
	}

	printf("Bubble sort results:\n");
	for(int i = 0; i < 10; i++){
		printf("%d - %d\n", bu[i][0], bu[i][1]);
	}

	printf("Selection sort results:\n");
	for(int i = 0; i < 10; i++){
		printf("%d - %d\n", se[i][0], se[i][1]);
	}

/*
	printf("Merge sort results:\n");
	for(int i = 0; i < 10; i++){
		printf("%d - %d\n", mn[i][0], mn[i][1]);
	}
*/
}