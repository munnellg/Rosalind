#Translating RNA into Protein

This problem was obtained from [Rosalind](http://rosalind.info/problems/locations/)

##Problem Statement

The 20 commonly occurring amino acids are abbreviated by using 20 letters from
the English alphabet (all letters except for B, J, O, U, X, and Z). Protein
strings are constructed from these 20 symbols. Henceforth, the term genetic
string will incorporate protein strings along with DNA strings and RNA strings.

The RNA codon table dictates the details regarding the encoding of specific
codons into the amino acid alphabet.

| U Col     | C Col     | A Col     | G Col|
|-----------|-----------|-----------|------|
|UUC F      |CUC L      |AUC I      |GUC V |
|UUU F      |CUU L      |AUU I      |GUU V |
|UUG L      |CUG L      |AUG M      |GUG V |
|UUA L      |CUA L      |AUA I      |GUA V |
|UCU S      |CCU P      |ACU T      |GCU A |
|UCC S      |CCC P      |ACC T      |GCC A |
|UCA S      |CCA P      |ACA T      |GCA A |
|UCG S      |CCG P      |ACG T      |GCG A |
|UAU Y      |CAU H      |AAU N      |GAU D |
|UAC Y      |CAC H      |AAC N      |GAC D |
|UAA Stop   |CAA Q      |AAA K      |GAA E |
|UAG Stop   |CAG Q      |AAG K      |GAG E |
|UGU C      |CGU R      |AGU S      |GGU G |
|UGC C      |CGC R      |AGC S      |GGC G |
|UGA Stop   |CGA R      |AGA R      |GGA G |
|UGG W      |CGG R      |AGG R      |GGG G |

+ Given: An RNA string s corresponding to a strand of mRNA (of length at most 10
kbp).
+ Return: The protein string encoded by s.

##Building and Running

To build, execute `make` in the root directory. This should produce an
executable called `prot`. Run this binary passing a file (or list of files)
containing scenarios for the simulator to play out

For example:

`./prot rosalind_fibd_2`
