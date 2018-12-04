#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void bubblesortiscute(int *a, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]<a[j+1]){
				continue;
			}else{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void insertionsortiscuter(int *array, int len){
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
		for(int i = 100; i <= 10101; i += 100){
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
			insertionsortiscuter(array_i, i);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			array_time_i[count] += time_spent;
			}
			{
			clock_t begin = clock();
			bubblesortiscute(array_b, i);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			array_time_b[count] += time_spent;
			}
			count++;
		}
		letsplot(array_time_b, array_time_i, 100);
	}else if(a == 2){
		int *array_b = (int *)malloc(10*sizeof(int));
		int *array_i = (int *)malloc(10*sizeof(int));

		for(int j = 0; j < 10; j++){
			array_b[j] = rand()%50;
		}
		for(int j = 0; j < 10; j++){
			array_i[j] = rand()%50;
		}

		char **insertion = (char **)malloc(10*sizeof(char *));
		char **bubble = (char **)malloc(10*sizeof(char *));

		for(int j = 0; j < 10; j++){
			insertion[j] = (char *)malloc(50*sizeof(char));
			bubble[j] = (char *)malloc(50*sizeof(char));
		}

		reset(insertion);
		reset(bubble);

		graph(insertion, array_i);
		graph(bubble, array_b);

		clearscreen();

		for(int i=0;i<10;i++){
			printf("Bubble Sort viz\n\n");
			print_grid(bubble);
			sleep(1);
			for(int j=0;j<10-i-1;j++){
				clearscreen();
				printf("Bubble Sort viz\n\n");
				reset(bubble);
				graph_selected(bubble, array_b, i, j);
				print_grid(bubble);
				sleep(1);
				if(array_b[j]<array_b[j+1]){
					continue;
				}else{
					int temp = array_b[j];
					array_b[j] = array_b[j+1];
					array_b[j+1] = temp;
				}
			}
			reset(bubble);
			graph(bubble, array_b);
			clearscreen();
		}
		clearscreen();
		reset(bubble);
		graph(bubble, array_b);
		printf("Bubble Sort viz\n\n");
		print_grid(bubble);
		sleep(1);

		clearscreen();

		for(int i = 0; i < 10; i++){
			printf("Insertion Sort viz\n\n");
			print_grid(insertion);
			sleep(1);
			int low = i;
			for(int j = i+1; j < 10; j++){
				clearscreen();
				printf("Insertion Sort viz\n\n");
				reset(insertion);
				graph_selected(insertion, array_i, i, j);
				print_grid(insertion);
				sleep(1);
				if(array_i[low] >= array_i[j]){
					low = j;
				}
			}
			int temp = array_i[low];
			array_i[low] = array_i[i];
			array_i[i] = temp;
			reset(insertion);
			graph(insertion, array_i);
			clearscreen();
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