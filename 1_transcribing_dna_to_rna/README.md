#Transcribing DNA into RNA

This problem was obtained from [Rosalind](http://rosalind.info/problems/locations/)

##Problem Statement
An RNA string is a string formed from the alphabet containing 'A', 'C', 'G',
and 'U'.

Given a DNA string t corresponding to a coding strand, its transcribed RNA
string u is formed by replacing all occurrences of 'T' in t with 'U' in u.

+ Given: A DNA string t having length at most 1000 nt.
+ Return: The transcribed RNA string of t.

##Building and Running

To build, execute `make` in the root directory. This should produce an
executable called `rna`. Run this binary with one of the RNA files as
input to count its nucleotides

For example:

`./dna rosalind_rna.txt`
