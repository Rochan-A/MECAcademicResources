#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int VERTICES[10] = {1,2,3,4,5,6,7,8,9,10};

int min(int *arr, int len){
	int min = 100;
	for(int i = 0; i < len; i++){
		if(arr[i] <= min){
			min = arr[i];
		}
	}
	return min;
}

void printPowerSet(int *set, int set_size, int **cost){
	/*set_size of power set of a set with set_size
	  n is (2**n -1)*/
	unsigned int pow_set_size = pow(2, set_size);
	int counter, j;

	/*Run from counter 000..0 to 111..1*/
	for(counter = 0; counter < pow_set_size; counter++)
	{
		int co = 0;
		for(j = 0; j < set_size; j++){
			/* Check if jth bit in the counter is set
			   If set then print jth element from set */
			if(counter & (1<<j))
				//printf("%d", set[j]);
				cost[counter][co] = set[j] + 1;
				co += 1;
		}
		//printf("\n");
	}
}



int tsp_dyna(int **matrix, int **cost, int nodes){

	// Set with only 2 points

	for(int i = 0; i < nodes; i++){
		for(int j = 0; j < nodes; j++){
			if(cost[i][j] > matrix[i][j]){
				cost[i][j] = matrix[i][j];
			}
		}
	}
}

void main(){

	int nodes;
	printf("Enter the number of nodes: ");
	scanf("%d", &nodes);

	int a = 1;

	for(int i = 0; i < nodes; i++){
		a = a << 1;
	}
	int** matrix = (int **)malloc(sizeof(int*)*nodes);

	for(int i = 0; i < nodes; i++){
		matrix[i] = (int *)malloc(sizeof(int)*nodes);
	}

	int** cost = (int **)malloc(sizeof(int*)*(a));

	for(int i = 0; i < a; i++){
		cost[i] = (int *)malloc(sizeof(int)*(nodes + 1));
	}

	for(int i = 0; i < a; i++){
			cost[i][nodes] = 99;
	}

	int* set = (int *)malloc(sizeof(int)*nodes);

	for(int i = 0; i < nodes; i++){
		set[i] = i;
	}


	printPowerSet(set, nodes, cost);
/*
	for(int i = 0; i < nodes; i++){
		for(int j = i + 1; j < nodes; j++){
			printf("Enter cost of edge between (%d, %d)", i, j);
			scanf("%d", &matrix[i][j]);
			matrix[j][i] = matrix[i][j];
		}
	}

	for(int i = 0; i < nodes; i++){
		for(int j = i + 1; j < nodes; j++){
			printf("Enter cost of edge between (%d, %d)", j, i);
			scanf("%d", &matrix[j][i]);
		}
	}
*/
	printf("Cost matrix is\n");
	for(int i = 0; i < a; i++){
		for(int j = 0; j < nodes + 1; j++){
			if(i == j){
//				matrix[i][j] = 0;
			}
			printf("%d ", cost[i][j]);
		}
		printf("\n");
	}

//	printf("The cost for tsp is: %d", tsp_dyna(matrix, cost, nodes));
}

/*
C({1},1) = 0
for s = 2 to n:
    for all subsets S ⊆ {1,2,...,n} of size s and containing 1:
        C(S,1) = ∞
        for all j∈S,j≠1:
            C(S, j) = min{C(S−{j},i)+dij:i∈S,i≠j}
return minjC({1,...,n},j)+dj1


If size of S is 2, then S must be {1, i},
 C(S, i) = dist(1, i)
Else if size of S is greater than 2.
 C(S, i) = min { C(S-{i}, j) + dis(j, i)} where j belongs to S, j != i and j != 1.

*/
