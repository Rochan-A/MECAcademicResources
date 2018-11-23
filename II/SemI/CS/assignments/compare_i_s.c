#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void insertionsortiscute(int *a, int n){
	int i,j,boo;
	for(i=1;i<n;i++){
		boo=a[i];
		j=i-1;
		while(j>=0 && a[j]>boo){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=boo;
	}
}

void selectionsortiscuter(int *array, int len){
	for(int i = 0; i < len; i++){
		int low = i;
		for(int j = i+1; j < len; j++){
			if(array[low] > array[j]){
				low = j;
			}
		}
		int temp = array[low];
		array[low] = array[i];
		array[i] = temp;
	}
}

void letsplot(double *a, double *b, int n){
	FILE *gnuplot = popen("gnuplot -persistent", "w");
	fprintf(gnuplot, "plot '-', '-'\n");
	for (int i = 0; i < n; i++){
		fprintf(gnuplot, "%d %f\n", i*100, a[i]);
	}
	fprintf(gnuplot, "e\n");
	for (int i = 0; i < n; i++){
		fprintf(gnuplot, "%d %f\n", i*100, b[i]);
	}
	fprintf(gnuplot, "e\n");
}

void clearscreen(){
	printf("\e[1;1H\e[2J");
}

void print_grid(char **grid){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 50; j++){
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

void reset(char **grid){
	for(int j = 0; j < 10; j++){
		for(int h = 0; h < 50; h++){
			grid[j][h] = ' ';
		}
	}
}

void graph(char **grid, int *array){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i]; j++){
			grid[i][j] = '#';
		}
	}
}

void graph_selected(char **grid, int *array, int row1, int row2){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < array[i]; j++){
			if(i == row1){
				grid[i][j] = 'S';
			}else if(i == row2){
				grid[i][j] = 'C';
			}else{
				grid[i][j] = '#';
			}
		}
	}
}

void main(){

	int a;
	printf("Enter your choice:\n1.\tGraph the sorting\n2.\tVisualize the sorting\n");
	scanf("%d", &a);
	srand(time(NULL));

	if(a == 1){
		double *array_time_b = (double *)malloc(100*sizeof(double));
		double *array_time_i = (double *)malloc(100*sizeof(double));

		int count = 0;
		for(int i = 5; i <= 1005; i += 10){
			int *array_b = (int *)malloc(i*sizeof(int));
			int *array_i = (int *)malloc(i*sizeof(int));

			for(int j = 0; j <= i; j++){
				array_b[j] = rand()%100000;
			}
			for(int j = 0; j <= i; j++){
				array_i[j] = rand()%100000;
			}

			{
			clock_t begin = clock();
			insertionsortiscute(array_i, i);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			array_time_i[count] += time_spent;
			}
			{
			clock_t begin = clock();
			selectionsortiscuter(array_b, i);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			array_time_b[count] += time_spent;
			}
			count++;
		}

		for(int i = 0; i < 100; i++){
			if(array_time_b[i] >= array_time_i[i]){
				printf("Insertion is better %d\n", i);
			}
		}

		letsplot(array_time_b, array_time_i, 100);
	}else if(a == 2){
		int *array_i = (int *)malloc(10*sizeof(int));

		for(int j = 0; j < 10; j++){
			array_i[j] = rand()%50;
		}

		char **insertion = (char **)malloc(10*sizeof(char *));

		for(int j = 0; j < 10; j++){
			insertion[j] = (char *)malloc(50*sizeof(char));
		}

		reset(insertion);

		graph(insertion, array_i);

		clearscreen();

		int i,j,boo;
		for(i=1;i<10;i++){
			printf("Insertion Sort viz\n\n");
			print_grid(insertion);
			sleep(1);
			boo=array_i[i];
			j=i-1;
			while(j>=0 && array_i[j]>boo){
				clearscreen();
				printf("Insertion Sort viz\n\n");
				reset(insertion);
				graph_selected(insertion, array_i, i, j);
				print_grid(insertion);
				sleep(1);
				array_i[j+1]=array_i[j];
				j=j-1;
			}
			reset(insertion);
			graph(insertion, array_i);
			clearscreen();
			array_i[j+1]=boo;
		}
		clearscreen();
		reset(insertion);
		graph(insertion, array_i);
		printf("Insertion Sort viz\n\n");
		print_grid(insertion);
		sleep(1);
	}else{
		printf("Incorrect choice\n");
		exit(0);
	}
}