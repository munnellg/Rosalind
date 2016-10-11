#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 100
#define DEFAULT_MSIZE 100

unsigned int *cache = NULL;
int msize = DEFAULT_MSIZE;
int enable_memoization = 1;

/* Memoization allows us to store previously computed values of the sequence */
/* so that we don't have to compute them again. Drastically speeds up        */
/* performance                                                               */
void memoize(int k, unsigned int v) {
	/* Check to see if cache is big enough to store value */
	if( k >= msize ) {

		/* If not, reallocate the cache */
		cache = realloc(cache, k+1);

		/* If reallocation failed, print error and disable memoization */
		if(!cache) {
			fprintf(stderr, "Unable to reallocate memory for memoization\n");
			enable_memoization = 0;
			msize = -1;
			return;
		}

		/* Otherwise, store the new size of the cache */
		msize = k+1;
	}

	/* Store value */
	cache[k] = v;
}


/* Lookup a value from the cache. Returns 0 for values which have not
 * been stored */
unsigned int lookup(int k) {
	/* Check to see if the key is within the range of the cache */
	if( k > msize ) {
		return 0;
	}

	/* Return the value from the cache */
	return cache[k];
}

/*
	gen - Number of generations
	ls - lifespan of a rabbit
	aom - age of maturity
*/
unsigned int m_fib(int gen, int ls, int aom) {
	unsigned int result;
	int i;

	/* Check for base case */
	if(gen < 2) {
		return 1;
	}

	/* Maybe we don't have to compute the result at all! */
	if(!enable_memoization || (result = lookup(gen)) == 0 ) {
		/* If we do, then lets do some fibonacci magic */
		for(i = (gen - ls); i <= (gen - aom); i++) {
			result += m_fib(i, ls, aom);
		}

		/* If we're caching results, store 'em */
		if( enable_memoization ) {
			memoize(gen, result);
		}
	}

	/* Return our rabbits */
	return result;
}

int main(int argc, char *argv[]) {
	FILE *f;
	int i, c;
	unsigned int r;
	char buffer[BUF_SIZE];
	int gen=6, aom=2, ls=3;

	/* Handle command line arguments */
	while ( (c = getopt (argc, argv, "d")) != -1 ) {
		switch (c)
		{
		case 'd':
			/* Disables memoization */
			msize = -1;
			enable_memoization = 0;
			break;
		default:
			break;
		}
	}

	/* Check to see if we've been given some input */
	/* If not, quit with an error                  */
	if(argc < 2) {
		fprintf(stdout, "No file passed as argument. Terminating.\n");
		return -1;
	}

	/* If we're caching results, allocate memory for our cache */
	if( enable_memoization ) {
		cache = calloc(msize, sizeof *cache);

		/* If cache allocation fails, disable memoization */
		if( !cache ) {
			fprintf(stderr, "Unable to allocate memory for memoization");
			msize = -1;
			enable_memoization = 0;
		}
	}

	/* Allow multiple input files */
	for(i=1; i<argc; i++) {
		/* Try to open the file */
		f = fopen(argv[i], "r");

		/* If opening the file fails, then just skip it */
		if(!f) {
			fprintf(stdout, "Unable to open %s\n", argv[i]);
			continue;
		}

		/* Otherwise, read the file into a buffer line by line */
		while(fgets(buffer, BUF_SIZE, f) != NULL) {
			/* Parse this line to extract generations and lifespan of our rabbits */
			c = sscanf(buffer, "%d %d", &gen, &ls);

			/* Check for failed read from file. */
			if(c != 2) {
				fprintf(stdout, "Failed to read values from file. Closing file\n");
				break;
			}

			/* Fibonacci magic */
			r = m_fib(gen-1, ls, aom);

			/* Print results for simulation input */
			fprintf(stdout, "%u rabbit%c after %d generation%c => ", r, r==1? 0:'s', gen, gen==1? 0:'s');
			fprintf(stdout, "Lifespan: %d Age of Maturity: %d\n", ls, aom);
		}
		/* close the file */
		fclose(f);
	}

	/* Free cache memory so no leaks */
	if(cache) {
		free(cache);
	}

	/* All done! */
	return 0;
}
