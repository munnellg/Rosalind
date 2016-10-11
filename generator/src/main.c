#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	char nucleobases[] = { 'A', 'C', 'G', 'T' }; /* Proteins for DNA */
	int len, id, i, n;
	char c;

	len = 10; /* Length of generated protein sequence */
	id = 0;   /* Don't generate a unique ID for each sequence */
	n = 1;    /* Only generate one protein sequence */

	/* Seed the random number generator with the current time on the clock */
	srand(time(NULL));

	/* Process command line arguments */
	while ((c = getopt (argc, argv, "n:irl:")) != -1) {
		switch (c)
		{
		case 'l':               /* Overwrite default length of protein sequence */
			len = atoi(optarg);
			break;
		case 'r':               /* Generate RNA, not DNA */
			nucleobases[3] = 'U'; /* Replace Thymine with Uracil */
			break;
		case 'i':               /* Give each protein sequence a FASTA ID */
			id = 1;
			break;
		case 'n':               /* Number of sequences to generate */
			n = atoi(optarg);
			break;
		default:
			break;
		}
	}

	// For whatever number of sequence we have to generate
	for(n; n>0; n--) {
		/* If we're generating sequence IDs, create one and print it */
		if(id) {
			printf(">Generate_%04d\n", rand()%10000);
		}

		/* Generate random sequence of protiens */
		for( i=0; i<len; i++) {
			printf("%c", nucleobases[rand()%4]);
		}

		/* End the sequence with a new line */
		printf("\n");
	}

	/* All done! */
	return 0;
}
