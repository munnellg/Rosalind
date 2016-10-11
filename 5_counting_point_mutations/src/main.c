#include <stdio.h>
#include <stdlib.h>

/* We don't expect to see any strands that are longer than this */
#define MAX_STRAND_LENGTH 1000

/* Compute the hamming distance between two input strings */
int hamming_distance(char str1[], char str2[]) {
	int h_dist, i;

	/* Initialize hamming distance to zero */
	h_dist = 0;

	/* Iterate over the strings together */
	for( i=0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		/* Count number of mismatched characters */
		if(str1[i] != str2[i]) {
			h_dist++;
		}
	}

	/* Return the distance between the strings */
	return h_dist;
}

int main(int argc, char* argv[]) {
	FILE* f;
	char str1[MAX_STRAND_LENGTH]; /* First protein sequence */
	char str2[MAX_STRAND_LENGTH]; /* Second protein sequence */

	/* Check to see that we got the correct number of inputs */
	if(argc < 2) {
		printf("Usage: hamm file\n");
		return -1;
	}

	/* Try to open input file */
	f = fopen(argv[1], "r");

	/* If we can't open the file then just quit */
	if(!f) {
		printf("Unable to open file %s\n", argv[1]);
		return -1;
	}

	/* Read two input strings from file */
	fgets(str1, sizeof str1, f);
	fgets(str2, sizeof str2, f);

	/* Compute and print hamming distance */
	printf("%i\n", hamming_distance(str1, str2));

	return 0;
}
