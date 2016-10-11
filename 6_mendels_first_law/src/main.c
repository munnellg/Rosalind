#include <stdio.h>
#include <stdlib.h>

#define NUM_ORGANISMS 3
#define DIMINISHING 0.25

int main(int argc, char* argv[]) {
	int organisms[NUM_ORGANISMS];
	float pr1[NUM_ORGANISMS] = {0};
	float pr2[NUM_ORGANISMS * NUM_ORGANISMS] = {0};
	float pr_dom, dim;
	int t, i, j;

	t = 0;
	pr_dom = 0;
	dim = 1;

	/* Start by getting the number of each organism type */
	printf("Homogenous Dominant: ");
	scanf("%d", &organisms[0]);
	printf("Hetrogenous: ");
	scanf("%d", &organisms[1]);
	printf("Homogenous Recessive: ");
	scanf("%d", &organisms[2]);

	/* Compute the total number of organisms */
	for( i=0; i<NUM_ORGANISMS; i++ ) {
		t += organisms[i];
	}

	/* For each type of organism, compute the probability that the first
	 * randomly chosen organism will be of that type */
	for( i=0; i<NUM_ORGANISMS; i++) {
		pr1[i] = (float)organisms[i]/t;
	}

	/* Decrement t as we have one less organism to choose from */
	t--;

	/* Compute the second round of probabilities accounting. What is the
	 * likelihood that a particular organism type will be chosen given
	 * that the first choice was of the same or a different type */
	for( i=0; i<NUM_ORGANISMS; i++ ) {
		for( j=0; j<NUM_ORGANISMS; j++ ) {
			pr2[NUM_ORGANISMS*i+j] = (float)( organisms[j] - ((i==j)? 1 : 0))/t;
		}
	}

	/* Compute the probability that a child will have a dominant
	 * allele */
	for( i=0; i<NUM_ORGANISMS; i++ ) {
		dim = 1;
		for( j=0; j<NUM_ORGANISMS; j++ ) {
			pr_dom += pr1[i] * pr2[NUM_ORGANISMS*i + j] * dim;
			dim = dim - DIMINISHING*i;
		}
	}

	/* Print the tree for aesthetics */
	printf("%.4f\n", 1.0);
	for( i=0; i<NUM_ORGANISMS; i++ ) {
		printf("\t%.4f\n", pr1[i]);
		for( j=0; j<NUM_ORGANISMS; j++ ) {
			printf("\t\t%.4f\n", pr2[NUM_ORGANISMS*i + j]);
		}
	}

	/* Print the result */
	printf("%.4f\n", pr_dom);

	return 0;
}
