#Protein Sequence Generator

Helper application which generates sequences of proteins (DNA or RNA). Allows
us to run some slightly bigger tests before we submit our code to Rosalind.

By default will generate one DNA strand of length 10.

Optional Inputs:

+ `-n` an int specifying how many sequences should be generated
+ `-i` Enables the generation of FASTA IDs for protein sequences
+ `-r` Produce RNA rather than DNA
+ `-l` an int specifying how long the sequence should be

##Building and Running

To build, execute `make` in the root directory. This should produce an
executable called `gen`. Run this binary passing arguments if desired

For example:

`./gen -n 10 -r`
