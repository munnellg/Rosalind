#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1000

/* See if b occurs in a starting at idx */
int cmp_at_idx(char a[], char b[], int idx) {
	int i;
	/* While we're not at the end of the string */
	for(i=0; b[i] != '\0'; i++, idx++) {
		/* If we find a mismatch then return false */
		if(a[idx] != b[i]) {
			return 0;
		}
	}

	/* return true */
	return 1;
}

int main(int argc, char* argv[]) {
	FILE *f;
	char motif[MAX_BUFFER]; /* The motif we're searching for */
	char dna[MAX_BUFFER];   /* The protein sequence in which we're searching */
	int i, j, ln;

	/* Check to see if we've been given an input file */
	if(argc < 2) {
		printf("Usage: subs file\n");
		return -1;
	}

	/* Try to open the input file */
	f = fopen(argv[1], "r");

	/* If we failed to read the input then quit with an error */
	if(!f) {
		printf("Unable to open file %s", argv[1]);
		return -1;
	}

	/* Load both our sequences into their respective buffers */
	fgets(dna, sizeof dna, f);
	fgets(motif, sizeof motif, f);

	/* Get the sequence length and discard any trailing newline characters */
	ln = strlen(dna) - 1;
	if (dna[ln] == '\n') {
		dna[ln] = '\0';
	}

	/* Get the motif length and discard any trailing newline characters */
	ln = strlen(motif) - 1;
	if (motif[ln] == '\n') {
		motif[ln] = '\0';
	}

	/* Search for motif in sequence */
	for( i=0; dna[i] != '\0'; i++) {
		/* Do comparison */
		if(cmp_at_idx(dna, motif, i)) {
			/* If we found the sequence, print the index at which it was found */
			printf("%d ", i+1);
		}
	}

	/* Print newline at the end of output */
	printf("\n");

	/* All done! */
	return 0;
}
