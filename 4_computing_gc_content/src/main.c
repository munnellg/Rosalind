#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ID_MAX_LENGTH 14 /* Maximum length of a FASTA ID */

float max_gc;                /* Highest GC content of any protein sequence */
char max_id[ID_MAX_LENGTH];  /* FASTA ID of sequence with highest gc content */

/* Compute GC content and update our global variables if appropriate */
void upd_max_gc(char cur_id[], int gc, int slen) {
	float cur_gc;

	if(slen > 0) {
		/* Compute GC content as percentage of sequence length */
		cur_gc = (float)gc/(float)slen;

		/* If length exceeds previous max, then update global variables */
		if(cur_gc > max_gc) {
			max_gc = cur_gc;
			strncpy(max_id, cur_id, ID_MAX_LENGTH);
		}
	}
}

int main(int argc, char* argv[]) {
	FILE* f;
	int gc, slen;
	char cur_id[ID_MAX_LENGTH], c; /* Input buffers */

	/* Ensure that we were passed an input to begin with */
	if(argc < 2) {
		printf("Usage: gc file\n");
		return -1;
	}

	max_gc = 0;       /* No max gc */
	gc = slen = 0;    /* No GC content - no sequence length */
	c = ' ';          /* Empty protein */

	cur_id[0] = '\0'; /* Empty string */
	max_id[0] = '\0'; /* Empty string */

	/* Open the input file */
	f = fopen(argv[1], "r");

	/* Ensure we were able to open the input file */
	if(!f) {
		printf("Unable to open file %s\n", argv[1]);
		return -1;
	}

	/* Read entire file character by character */
	while( (c = fgetc(f)) != EOF) {
		switch(c) {
		case '>': /* Start of new sequence */
			/* Compute gc content and update as appropriate */
			upd_max_gc(cur_id, gc, slen);
			/* Start new protein sequence */
			fgets(cur_id, sizeof cur_id, f);
			gc = slen = 0;
			break;
		case 'C':
		case 'G':
			gc++;   /* Count all C and G occurrences */
		case 'T':
		case 'A':
			slen++; /* Count every protein to get sequence length */
		default:
			break;
		}
	}

	/* Close the input file */
	fclose(f);

	/* Need to do one more test for the final sequence that we read */
	upd_max_gc(cur_id, gc, slen);

	/* Print FASTA ID of sequence with highest GC content. */
	/* Also print the GC content */
	printf("%s\n", max_id);
	printf("%.4f\n", max_gc*100);

	return 0;
}
