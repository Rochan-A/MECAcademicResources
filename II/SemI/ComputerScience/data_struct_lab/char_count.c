#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count(char *input, char *matrix){
	for(int i = 0; i < strlen(input); i++){
	matrix[(int)input[i] - 97] = matrix[(int)input[i] - 97] + 1;
	}
}

void main(){

	char input[200];
	char matrix[26];
	char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	for(int i = 0; i < 26; i++){
		matrix[i] = 0;
	}

	printf("Enter the input string:\n");
	scanf("%s", input);

	count(input, matrix);

	for(int i = 0; i < 26; i++){
		printf("%c: %d\n", alpha[i], matrix[i]);
	}

}