#Complementing a Strand of DNA

This problem was obtained from [Rosalind](http://rosalind.info/problems/locations/)

##Problem Statement

In DNA strings, symbols 'A' and 'T' are complements of each other, as
are 'C' and 'G'.

The reverse complement of a DNA string s is the string sc formed by
reversing the symbols of s, then taking the complement of each symbol
(e.g., the reverse complement of "GTCA" is "TGAC").

+ Given: A DNA string s of length at most 1000 bp.
+ Return: The reverse complement sc of s.

##Building and Running

To build, execute `make` in the root directory. This should produce an
executable called `revc`. Run this binary with one of the DNA files as
input to find its Compliment

For example:

`./revc rosalind_revc.txt`
