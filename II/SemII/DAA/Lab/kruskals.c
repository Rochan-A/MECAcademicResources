#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int first;
	int second;
} edge;

static int cyclic_recursive(const edge *edges, int n, int *visited, int order, int vertex, int predecessor){
	int i;
	int cycle_found = 0;
	visited[vertex] = 1;
	for (i = 0; i < n && !cycle_found; i++) {
		if (edges[i].first == vertex || edges[i].second == vertex) {
			/* Adjacent */
			const int neighbour = edges[i].first == vertex ?
				edges[i].second : edges[i].first;
			if (visited[neighbour] == 0) {
				/* Not yet visited */
				cycle_found = cyclic_recursive(edges, n, visited, order, neighbour, vertex);
			}
			else if (neighbour != predecessor) {
				/* Found a cycle */
				cycle_found = 1;
			}
		}
	}
	return cycle_found;
}

int cyclic(const edge *edges, int n, int order){
	int *visited = (int *)malloc(order * sizeof(int));
	int cycle_found;
	cycle_found = cyclic_recursive(edges, n, visited, order, 0, 0);
	return cycle_found;
}

int check_cyclic(int **matrix, int nodes){
	int order = nodes; /* Vertices */

	int count = 0;
	for(int i = 0; i < nodes; i++){
		for(int j = i + 1; j < nodes; j++){
			if(matrix[i][j] == 1){
				count++;
			}
		}
	}

	const int n = count; /* Edges */
	edge *edges;
	int c;

	edges = malloc(n * sizeof(edge));

	count = 0;
	for(int i = 0; i < nodes; i++){
		for(int j = i + 1; j < nodes; j++){
			if(matrix[i][j] == 1){
				edges[count].first = i;
				edges[count].second = j;
			}
			count++;
		}
	}

	c = cyclic(edges, n, order);
	free(edges);
	return c;
}

void main(){

	printf("Enter number of nodes in the graph:");
	int nodes = 0;
	scanf("%d", &nodes);

	const int order = nodes; /* Vertices */

	int** matrix = (int **)malloc(sizeof(int*)*nodes);

	for(int i = 0; i < nodes; i++){
		matrix[i] = (int *)malloc(sizeof(int)*nodes);
	}

	for(int i = 0; i < nodes; i++){
		for(int j = i + 1; j < nodes; j++){
			printf("Enter 1 if edge exists (%d, %d)", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("%d\n", check_cyclic(matrix, nodes));

}