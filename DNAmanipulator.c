#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100 // max size of sequence
#define NUMPROTEINS 64// max number of the protein names

// function prototypes
bool isBasePair (char neu1, char neu2);
bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]);
void reverse (char aStrand [SIZE]);
void complementIt (char aStrand [SIZE]);
bool isItPalindrome (char aStrand [SIZE]);
bool isStrandDnaPalindrome (char aStrand [SIZE]);
int howMany (char aStrand [SIZE], char neu);
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]);
void translateDnaToMrnaProteins (char aSeq [SIZE]);
char getCode (char protein [3]);

// function definition for function 1
bool isBasePair (char neu1, char neu2) {
  if ((neu1 == 'A' && neu2 == 'T')|| (neu1=='T'&& neu2 =='A')){
    return true; // returns true if neu1 and neu2 are a pair (AT or TA)
  } else if ((neu1=='C'&& neu2=='G')|| (neu1=='G'&& neu2=='C')){
    return true; // returns true if neu1 and neu2 are a pair (CG or GC)
  }
  return false;// returns false if neu1 and neu2 are not any of the appropriate pairs
}

// function definition for function 2
bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]){ 
  int length = strlen(strand1); // will count the length of the first DNA strand and store it as an integer in a variable named length 
  int i;// declare i for the for loop
  
  /* if statement to check if the length of the second Dna strand is even equal to the length of the first. 
  If it is not equal, it will return false to the main function and simply end this function so it won't run*/
  if (strlen(strand2) != length) { 
    return false;
  } 

  /* for loop that has an if statement inside. It will go through each element of our first DNA strand that was initilized in the main function. 
  It will start by checking to see if the first element of the first DNA strand and the first element of the second DNA strand 
  (that was also initialized in the main function) form a pair. i will then increase if no mispairs are found.*/
  for (i=0; i<length;i++ ){ 
    if (!((strand1[i] =='A' && strand2[i] =='T')||(strand1[i]=='T'&& strand2[i]=='A')||(strand1[i]=='C'&& strand2[i]=='G')||(strand1[i]=='G'&& strand2[i]=='C'))){
      return false; // as soon as it encounters a pair of elements that is not an appropriate pair, it will return false to main function 
    }
  }
  return true; // if all pairs of elements are proper, it will return true to main 
} 

// function definition for function 3
void reverse (char aStrand [SIZE]){
  int length  = strlen(aStrand); // will count the length of the DNA strand and store it as an integer in a variable named length 
  char reverseaStrand [length]; // created a new array, that will temprorairly store the reversed DNA strand
  int i;
  /*a for loop that will iterate through the original DNA strand. When its going through the first element of the original strand which has a subcript of 0, 
  the first element of the reverse strand will actually be equal to the last element of the original strand.*/
  for (i=0; i<length; i++){
    reverseaStrand[i] = aStrand[length-i-1]; 
  }
  aStrand[length] = '\0'; // adding a null to the end of the string, so it can end the string
  strcpy (aStrand, reverseaStrand); // will copy the reversed strand into the original strand and have it stored in aStrand
 
}

// function definition for function 4
void complementIt (char aStrand [SIZE]){
  int length = strlen(aStrand); // will count the length of the DNA strand and store it as an integer in a variable named length
  int i;
  /* for loop that will take the very first character in aStrand (which has a subscript of 0) and based on whatever the character is, 
  it will replace it with the complement character. Then the subscript increases, and the process repeats until all the characters 
  in aStrand are replaced with their complements and aStrand (which a DNA strand) will now become its complement DNA strand.*/
  for (i=0; i<length; i++){ 
    if (aStrand[i] == 'A'){
      aStrand[i] = 'T';
    } else if (aStrand[i] == 'T'){
      aStrand[i] = 'A';
    } else if (aStrand[i]=='C'){
      aStrand[i] = 'G';
    } else if(aStrand[i]=='G'){
      aStrand[i] ='C';
    } 
  }
}

// function definiion for function 5
bool isItPalindrome (char aStrand [SIZE]){
  int length = strlen(aStrand);// will count the length of the DNA strand and store it as an integer in a variable named length
  int i = 0; // declared i as an integer and initialized it to 0
  while (i<length){ // set the condition which is that if i is less than the length of the DNA strand (aStrand), then the loop will continue to run
    if (aStrand[i] !=aStrand[length-i-1]){ // if statement that will check whether the first element of the strand is equal to the last element of the strand. 
      return false;// if it is not equal, then the loop will end and return false to the main function  
    } 
    i++; //if the elements are equal, i increases to the next element in the array and and will check (e.g. is the second element equal to the second last) 
  } 
  return true; // if the entire loop completes, it will return true because that means that if you take the strand and reverse it, it will be the same strand.
}

// function definition for function 6
bool isStrandDnaPalindrome (char aStrand [SIZE]){

  int length = strlen(aStrand);
  char complaStrand [length]; // complement array that will temporarily store the complement of the array aStrand 
  for (int i=0; i<length; i++){ // a for loop to make the complement array (similar to the one used in function 5)
    if (aStrand[i] =='A'){
      complaStrand[i] = 'T';
    } else if (aStrand[i] =='T'){
      complaStrand[i] ='A';
    } else if (aStrand[i] =='C'){
      complaStrand[i] = 'G';
    } else if(aStrand[i] =='G'){
      complaStrand[i] = 'C';
    }
  }

  /* a while loop that will start by checking if the first element of the complement array (complaStrand) 
  is equal to the last element of the original array (aStrand).*/
  int i = 0; // declare i and set as 0
  while (i<length){
    if (complaStrand[i] !=aStrand[length-i-1]){
      return false; // if there is a mismatch it will return false
    }
    i++; // increments i
  }
  return true; // if the loop iterates through every single element it means that the complement array is the same as the original array in reverse and will return true
}

// function definition for function 7
int howMany (char aStrand [SIZE], char neu){
  int length  = strlen(aStrand);
  int sum = 0; // the variable named sum will store the total number of that specific neuclotide in the string 
  int i;
  //a for loop that will iterate through the whole strand and every time it encounters the declared neuclotide, it will increase the total sum by 1
  for (i=0; i<length; i++){
    if (aStrand[i] == neu){
      sum = sum +1;
    }
  }
  return sum; // will return the total number of that specific neuclotide in the strand back to main
}

// function definition for function 8
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]){
  int length = strlen(aSeq);
  int i;
  strcpy (mRNA, aSeq); // copies the aSeq string (the initialized DNA strand) into mRNA string

  complementIt (mRNA); // calling / using the function complemntIt to turn mRNA strand (which is currently equal to aSeq) into its complement strand

  // for loop that will replace every T there is in the complement strand with a U
  for (i=0; i<length; i++){
    if (mRNA[i] == 'T'){
      mRNA[i] ='U';
    }
  }
}

// function definition for function 9
void translateDnaToMrnaProteins (char aSeq [SIZE]){
  int i=0; // delcare and initilize i
  char aminoLetter; // declare a variable called  aminoLetter for the protein letter that will be given by getCode
  char mRNA [SIZE]; // declare an array that will be the mRNA strand of aSeq which was a DNA strand
  int mrnaLength = strlen(aSeq); // let the length of the mrna strand (mRNA) be equal to the length of the DNA strand (aSeq)
  printf("DNA: %s\n", aSeq); //print dna strand which is aSeq that was initialized in main

  // you need to change aSeq (a dna strand) into its mRNA strand which you can do using function 8
  dnaToMrna (aSeq, mRNA);
  printf("mRNA: %s, which translates to: \n", mRNA); // print the mRNA strand

  /* if statement that will help check if the mRNA strand is perfectly divisible into 3's (which means that it is a multiple of three). 
  If it is not, the extra nucleotides (which will be either 1 or 2 extra neuclotides) will be removed and not accounted for.*/
  if (mrnaLength % 3 != 0){
    if (mrnaLength % 3 == 1){
      mrnaLength = mrnaLength -1;// the 1 extra neuclotide is removed (so mRNA length is cut by 1)
    } else if (mrnaLength % 3 == 2){
      mrnaLength = mrnaLength - 2; // the 2 extra neuclotides will be removed (so mRNA length is cut by 2) 
    }
  }
  
  /* need a for a loop that will assign 3 elements of the mRna strand to an array and pass the array through the get code function. 
  It will then print the corresponding letters. It will do this repeatedly until all triplets are accounted for. */

  for (i=0;i<mrnaLength;i=i+3){
    char codon [4] ={mRNA[i], mRNA[i+1], mRNA[i+2], '\0'};// initializng the array called codon that will store 3 consecutive elements of the mRna strand at a time 
    aminoLetter = getCode (codon);// using the getCode function to get the protein 
    printf("%s : %c\n", codon, aminoLetter);
    if (aminoLetter == 'Z'){
      printf("The input sequence has an incorrect base\n");
    }
  }
}

// The getCode function 
char getCode (char protein [3]) {

  // array allProteins has a list of all 3-triplet amino acids required for this assignment

  char allProteins [NUMPROTEINS][SIZE] = {"GCA", "GCC", "GCG", "GCU", "AGA","AGG", "CGA", 
  "CGC","CGG","CGU","GAC", "GAU","AAC","AAU","UGC","UGU","GAA","GAG","CAA","CAG", "GGA", 
  "GGC","GGG","GGU","CAC", "CAU","AUA","AUC","AUU", "UUA", "UUG","CUA","CUC", "CUG", "CUU", "AAA", 
  "AAG","AUG", "UUC","UUU", "CCA", "CCC", "CCG", "CCU", "AGC","AGU","UCA","UCC","UCG", "UCU","ACA","ACC","ACG", "ACU", "UGG","UAC","UAU", "GUA","GUC","GUG", "GUU"};

  // array allCodes stores the single-letter code of each triplet given in the above array

  char allCodes [NUMPROTEINS] ={'A','A','A','A','R','R','R','R','R','R','D','D','N','N','C','C','E','E','Q','Q', 'G','G','G','G','H','H','I','I','I', 'L','L','L','L','L','L','K','K','M','F','F','P','P','P','P','S','S','S','S','S','S','T','T','T','T', 'W','Y','Y','V','V','V','V'};

  for (int i = 0; i < NUMPROTEINS; i++) {
    if  (strncmp (protein, allProteins[i], 3) == 0){
      return allCodes [i];
    }
  }

  return 'Z';   // to indicate an incorrect code - code that doesn't exist in array allCodes
}

