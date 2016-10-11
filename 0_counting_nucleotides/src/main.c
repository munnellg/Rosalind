#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	FILE* f = NULL;

	/* Counts for each nucleotide */
	int cnt_a = 0, cnt_c = 0;
	int cnt_g = 0, cnt_t = 0;
	char c;

	/* Too few arguments. Print usage information */
  if(argc < 2) {
		printf("Usage: dna file\n");
		return 1;
	}

	/* Open the input file */
	f = fopen(argv[1], "r");

	/* If we couldn't open the file then quit the program */
	if(!f) {
		fprintf(stderr, "Unable to open file %s\n", argv[1]);
		return 1;
	}

	/* Read the file character by character and keeps counts as
	 * appropriate */
	while(( c = fgetc(f) ) != EOF) {
		switch(c) {
		case 'A':  /* Count Adenine */
			cnt_a++;
			break;
		case 'C':  /* Count Cytosine */
			cnt_c++;
			break;
		case 'G':  /* Count Guanine */
			cnt_g++;
			break;
		case 'T':  /* Count Thymine */
			cnt_t++;
			break;
		default:
			/* Report any invalid characters (unless it's just a space) */
			if(!isspace(c)) {
				fprintf(stderr, "Erronous character: %#04X\n", c);				
			}
			break;
		}
	}

	/* Close the file */
	fclose(f);

	/* Print the results */
	printf("%d %d %d %d\n", cnt_a, cnt_c, cnt_g, cnt_t);
	return 0;
}
