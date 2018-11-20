#include <stdio.h>
#include <stdlib.h>

void multi(int **matrix_1, int **matrix_2, int **resultant){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int sum = 0;
			for(int k = 0; k < 3; k++){
				sum = sum + (matrix_1[i][j] * matrix_2[j][k]);
			}
			resultant[i][j] = sum;
		}
	}
}

void main(){

	int **matrix_1 = (int **)malloc(3*sizeof(int *));
	for(int i = 0; i < 3; i++){
		matrix_1[i] = (int *)malloc(3*sizeof(int));
	}

	int **matrix_2 = (int **)malloc(3*sizeof(int *));
	for(int i = 0; i < 3; i++){
		matrix_2[i] = (int *)malloc(3*sizeof(int));
	}

	int **resultant = (int **)malloc(3*sizeof(int *));
	for(int i = 0; i < 3; i++){
		resultant[i] = (int *)malloc(3*sizeof(int));
	}

	printf("Enter the values of the first matrix:\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &matrix_1[i][j]);
		}
	}

	printf("Enter the values of the second matrix:\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &matrix_2[i][j]);
		}
	}

	multi(matrix_1, matrix_2, resultant);

	printf("The product of matrix 1 and matrix 2 is:\n");
	for(int i = 0; i < 3; i++){
		printf("%d %d %d\n", resultant[i][0], resultant[i][1], resultant[i][2]);
	}

}