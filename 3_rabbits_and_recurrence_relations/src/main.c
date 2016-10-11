#include <stdio.h>
#include <stdlib.h>

/* Allow for absolutely massive fibonacci numbers with unsigned long long */
unsigned long long int nfib(int n, int k) {
	/* Base case - return */
	if(n < 2) {
		return 1;
	}
	/* Recurse */
	return nfib( n-1, k ) + k*nfib( n-2, k );
}

int main(int argc, char* argv[]) {
	int n, k;

	/* Get inputs from user */
	printf("Input number of iterations: ");
	scanf("%d", &n);
	printf("Input weight: ");
	scanf("%d", &k);

	/* Print result */
	printf("Result: %llu\n", nfib(n-1, k));
	return 0;
}
