#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* We examine sequence in groups of 3 */
#define RNA_CODE_LENGTH 3

/* Translated Codon table to 4x4x4 matrix */
static const char *rna_codon[4][4] = {
	{
		"FFLL",
		"SSSS",
		"YY\0\0",
		"CC\0W",
	},
	{
		"LLLL",
		"PPPP",
		"HHQQ",
		"RRRR",
	},
	{
		"IIIM",
		"TTTT",
		"NNKK",
		"SSRR",
	},
	{
		"VVVV",
		"AAAA",
		"DDEE",
		"GGGG",
	}
};

int main(int argc, char* argv[]) {
	FILE* f;
	char c, p;
	int idx;

	/* Buffer for RNA codes */
	int rna[RNA_CODE_LENGTH] = {0};

	/* Check for input file */
	if(argc < 2) {
		printf("Usage: prot file\n");
		return -1;
	}

	/* Open input file */
	f = fopen(argv[1], "r");

	/* Ensure file was opened */
	if(!f) {
		printf("Unable to open file %s\n", argv[1]);
		return -1;
	}

	/* Translate RNA Sequence to suitable integer codes */
	while( (c = fgetc(f)) != EOF) {
		switch(c) {
		case 'U':
			rna[idx++]=0; /* Integer code for Uracil */
			break;
		case 'C':
			rna[idx++]=1; /* Integer code for Cytosine */
			break;
		case 'A':
			rna[idx++]=2; /* Integer code for Adenine */
			break;
		case 'G':
			rna[idx++]=3; /* Integer code for Guanine */
			break;
		default:
			if(!isspace(c)) {
				/* Error! Quit everything and return error code */
				printf("Error: Invalid protein code %#2X\n", c);
				fclose(f);
				return -1;
			}
			break;
		}

		/* When we've read a group of three RNA elements, find the target */
		/* protein in the codon table                                     */
		if(idx > 2) {
			/* Reset idx */
			idx=0;

			/* Get the protein */
			p = rna_codon[rna[0]][rna[1]][rna[2]];

			/* Inidicates the sequence is done. Time to stop */
			if(p == '\0') {
				break;
			}

			/* If we're not done, print the protein and go again */
			printf("%c", p);
		}
	}


	printf("\n");

	/* Close the input file */
	fclose(f);

	/* All done */
	return 0;
}
