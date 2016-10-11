#Counting DNA Nucleotides

This problem was obtained from [Rosalind](http://rosalind.info/problems/locations/)

##Problem Statement
A string is simply an ordered collection of symbols selected from some
alphabet and formed into a word; the length of a string is the number
of symbols that it contains.

An example of a length 21 DNA string (whose alphabet contains the
symbols 'A', 'C', 'G', and 'T') is "ATGCTTCAGAAAGGTCTTACG."

+ Given: A DNA string s of length at most 1000 nt.
+ Return: Four integers (separated by spaces) counting the respective
number of times that the symbols 'A', 'C', 'G', and 'T' occur in s .

##Building and Running

To build, execute `make` in the root directory. This should produce an
executable called `dna`. Run this binary with one of the DNA files as
input to count its nucleotides

For example:

`./dna rosalind_dna.txt`
