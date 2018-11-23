#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count(char *input, char *matrix){
	for(int i = 0; i < strlen(input); i++){
	matrix[(int)input[i] - 97] = matrix[(int)input[i] - 97] + 1;
	}
}

int compare(char **matrix){
	int t = 0;
	for(int i = 0; i < 26; i++){
		if(matrix[0][i] == matrix[1][i]){
			t = 0;
		}else{
			t = 1;
		}
	}
	return t;
}

void main(){

	char word_1[200];
	char word_2[200];

	char **matrix = (char **)malloc(2*sizeof(char *));
	for(int i = 0; i < 2; i++){
		matrix[i] = (char *)malloc(26*sizeof(char));
	}

	printf("Enter the first word:\n");
	scanf("%s[^\n]", word_1);
	printf("Enter the second word:\n");
	scanf("%s[^\n]", word_2);

	count(word_1, matrix[0]);
	count(word_2, matrix[1]);

	for(int i = 0; i < 26; i++){
		printf("%d %d\n", matrix[0][i], matrix[1][i]);
	}

	int o = compare(matrix);

	if( o - 1 == 0){
		printf("The given words are not anagrams\n");
	}else{
		printf("The given words are anagrams\n");
	}

}