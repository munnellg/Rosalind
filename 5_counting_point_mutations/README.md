#Counting Point Mutations

This problem was obtained from [Rosalind](http://rosalind.info/problems/locations/)

##Problem Statement

Given two strings s and t of equal length, the Hamming distance between s and
t, denoted dH(s,t), is the number of corresponding symbols that differ in s
and t.

+ Given: Two DNA strings s and t of equal length (not exceeding 1 kbp).
+ Return: The Hamming distance dH(s,t).

##Building and Running

To build, execute `make` in the root directory. This should produce an
executable called `hamm`. Run this binary passing a file two DNA sequences on
separate lines

For example:

`./hamm rosalind_hamm.txt`
