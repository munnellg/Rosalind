#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUF_LENGTH 1024
#define DISCARD_BUFF_LENGTH 16

/* Enum for indexing proteins */
enum Proteins { A, C, G, T, NUM_PROTEINS };

/* Characters for printing proteins */
static const char protein_codes[] = { 'A', 'C', 'G', 'T' };

int main(int argc, char* argv[]) {
	FILE *f;
	char c;
	int idx, idx_max;
	int i, j;

	/* A buffer used for dumping the FASTA ID */
	char discard[DISCARD_BUFF_LENGTH];

	/* Zeroed matrix of protein counts */
	int matrix[NUM_PROTEINS][MAX_BUF_LENGTH] = {{0}};


	/* Usual stuff for reading in data from a file */
	if(argc < 2) {
		printf("Usage: cons file\n");
		return -1;
	}

	f = fopen(argv[1], "r");
	if(!f) {
		printf("Unable to open file %s\n", argv[1]);
		return -1;
	}

	/* Decipher the file contents */
	while( (c = fgetc(f)) != EOF) {
		switch(c) {
		case '>':
			/*  Discard the ID of the protein string and reset the index */
			fgets(discard, sizeof discard, f);
			idx = 0;
			break;
			/* Increment the appropriate protein index */
		case 'C':
			matrix[C][idx++]++;
			break;
		case 'G':
			matrix[G][idx++]++;
			break;
		case 'T':
			matrix[T][idx++]++;
			break;
		case 'A':
			matrix[A][idx++]++;
			break;
		default:
			if(!isspace(c)) {
				printf("Error in input file. Erroneous protein code %#2X\n", c);
				return -1;
			}
			break;
		}
	}

	/* Close the file, you silly boy */
	fclose(f);

	/* Compute and print the consensus protein string */
	for(i=0; i<idx; i++) {
		idx_max=0;
		for(j=0; j<NUM_PROTEINS; j++) {
			if(matrix[j][i] > matrix[idx_max][i]) {
				idx_max = j;
			}
		}
		printf("%c", protein_codes[idx_max]);
	}
	printf("\n");

	/* Print the consensus matrix */
	for(i=0; i<NUM_PROTEINS; i++) {
		printf("%c: ", protein_codes[i]);
		for(j=0; j<idx; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
