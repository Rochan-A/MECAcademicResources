#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int return_highest_cf(int a, int b){
	int idx = 0, h = 0;

	if(a > b){
		h = a;
	}else{
		h = b;
	}

	for(int i = 1; i < h; i++){
		if(a % i == 0 && b % i == 0){
			idx = i;
		}
	}

	return idx;

}

void main(){

	int n = 0, d = 0;
	printf("Enter the numerator: ");
	scanf("%d", &n);

	printf("Enter the denominator:");
	scanf("%d", &d);

	int idx = 0;

	while(idx != 1){
		idx = return_highest_cf(n, d);
		n = n / idx;
		d = d / idx;
	}

	printf("The fraction is: %d/%d\n", n, d);
}