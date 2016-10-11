#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	FILE* f = NULL;
	char c;

	/* Check to see if we've been passed an input file. */
	/* If not, then quit */
  if(argc < 2) {
		printf("Usage: rna file\n");
		return 1;
	}

	/* Open the input file */
	f = fopen(argv[1], "r");

	/* Ensure that we were able to open the file */
	if(!f) {
		fprintf(stderr, "Unable to open file %s\n", argv[1]);
		return 1;
	}

	/* Read the file letter by letter substituting any instance of Thymine with
	   Uracil */
	while(( c = fgetc(f) ) != EOF) {
		if( c == 'T' ) {
			putchar('U'); /* Substitute */
		} else {
			putchar(c);   /* Don't substitute */
		}
	}

	/* Close the input file */
	fclose(f);
	return 0;
}
