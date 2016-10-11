#include <stdio.h>
#include <ctype.h>

/* Problem statements says max string is 1000bp, so shouldn't need
 * more than 1MB of space for the buffer*/
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
  /* File handle for reading data */
	FILE* f = NULL;

  /* Buffer for storing data loaded from file */
	char buffer[BUFFER_SIZE];

  /* Amount of data contained in buffer */
	int length;

	/* Check to see if we've been given an input file */
  if(argc < 2) {
		printf("Usage: revc file\n");
		return 1;
	}

	/* Try to open the file */
	f = fopen(argv[1], "r");

	/* If opening the file failed, exit with an error */
	if(!f) {
		fprintf(stderr, "Unable to open file %s\n", argv[1]);
		return 1;
	}
	
	/* Read file contents into our buffer */
	length = fread(&buffer, sizeof(char), BUFFER_SIZE, f);

	/* Close the file */
	fclose(f);
	
	/* Begin transforming the sequence */
	/* Read from end to start as we're reversing the sequence */
	for(length=length-1; length>=0; --length) {
		/* Process the buffer and print the output sequence */
		switch(buffer[length]) {
		case 'A':
			putchar('T'); /* Adenine becomes Thymine */
			break;
		case 'T':
			putchar('A'); /* Thymine becomes Adenine */
			break;
		case 'C':
			putchar('G'); /* Cytosine becomes Gianine */
			break;
		case 'G':			
			putchar('C'); /* Guanine becomes Cytosine */
			break;
		default:
			/* We'll ignore spaces, but anything else is erroneous input */
			if(!isspace(buffer[length])) {
				fprintf(stderr, "\nErroneous character %#04X\n", buffer[length]);
			}
		}
	}

	/* Print a newline at the end of our new sequence */
	putchar('\n');

	/* All done! */
	return 0;
}
