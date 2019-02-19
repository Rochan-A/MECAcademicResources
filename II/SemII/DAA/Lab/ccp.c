#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void selection_x(int **array){
	int n = 10;
	for(int i = 0; i < n; i++){
		int low = i;
		for(int j = i+1; j < n; j++){
			if(array[low][0] > array[j][0]){
				low = j;
			}
		}
		int t_x = array[low][0];
		int t_y = array[low][1];
		array[low][0] = array[i][0];
		array[low][1] = array[i][1];
		array[i][0] = t_x;
		array[i][1] = t_y;
	}
}

void selection_y(int **array){
	int low = 0;
	int high = 0;

	for(int i = 0; i < 10; i++){
		if(array[i][1] >= 0){
			low = i;
		}
	}

	for(int i = 9; i >= 0; i--){
		if(array[i][1] >= 0){
			high = i;
		}
	}

	int n = 10;
	for(int i = low; i < high + 1; i++){
		int low = i;
		for(int j = i+1; j < high + 1; j++){
			if(array[low][1] > array[j][1]){
				low = j;
			}
		}
		int t_x = array[low][0];
		int t_y = array[low][1];
		array[low][0] = array[i][0];
		array[low][1] = array[i][1];
		array[i][0] = t_x;
		array[i][1] = t_y;
	}
}

double distance(int* a, int* b){
	return sqrt(abs(a[0] - b[0])^2 + abs(a[1] - b[1])^2);
}

float bruteForce(int** array, int low, int high){
	float min = 1000;
	for (int i = low; i < high; ++i)
		for (int j = i+1; j < high; ++j)
			if (distance(array[i], array[j]) < min)
				min = distance(array[i], array[j]);
	return min;
}

float min(float x, float y)
{
	return (x < y)? x : y;
}

float stripClosest(int** strip, int size, float d)
{
	float min = d;

	selection_y(strip);

	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j][1] - strip[i][1]) < min; ++j)
			if (distance(strip[i],strip[j]) < min)
				min = distance(strip[i], strip[j]);

	return min;
}

float closestUtil(int** array, int low, int high){
	if (high - low <= 3)
		return bruteForce(array, low, high);

	int mid = (high + low)/2;

	float dl = closestUtil(array, low, mid);
	float dr = closestUtil(array, mid + 1, high);

	int* strip[10];

	for(int i = 0; i < 10; i++){
		strip[i] = (int *)malloc(sizeof(int)*2);
	}

	for(int i = 0; i < 10; i++){
		strip[i][0] = -1;
		strip[i][0] = -1;
	}

	float d = min(dl, dr);

	int j = 0;

	for (int i = 0; i < 10; i++)
		if (abs(array[i][0] - array[mid][0]) < d)
			strip[j] = array[i], j++;

	return min(d, stripClosest(strip, j, d) );
}

float closest(int** array, int low, int high){
	return closestUtil(array, low, high);
}

void main(){

	srand(time(NULL));
	int* array_b[10];

	for(int i = 0; i < 10; i++){
		array_b[i] = (int *)malloc(sizeof(int)*2);
	}

	for(int i = 0; i < 10; i++){
		array_b[i][0] = rand()%20;
	}

	for(int i = 0; i < 10; i++){
		array_b[i][1] = rand()%20;
	}

	selection_x(array_b);

	printf("The smallest distance is %f ", closest(array_b, 0, 10));

}