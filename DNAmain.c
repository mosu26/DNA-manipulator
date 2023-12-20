#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100
#define NUMPROTEINS 64

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

int main (){
  
  // testing call for function 1
  int resFunction1;
  char neu1 = 'G';
  char neu2 = 'C';

  printf("neu 1 is %c\n", neu1);
  printf("neu 2 is %c\n", neu2);
  resFunction1 = isBasePair (neu1, neu2);
  printf("The result of the function 1 is (true or false): %d\n", resFunction1);

  // testing call for function 2
  int resFunction2; // declared an integer (which is the result of function 2 that stores whatever we get from return in our function definition, (e.g. if we return false, resFunction2  = 0) 
  char strand1[SIZE];
  char strand2[SIZE];
  strcpy(strand1, "ATAT");
  strcpy (strand2, "TATA");
  resFunction2 = isItaDnaSequence (strand1, strand2);
  printf("The result for function 2 is (true or false): %d\n", resFunction2);

  // testing call for function 3
  char aStrand [SIZE] = "GCCAT";
  printf("This is the original strand: %s\n", aStrand);
  reverse (aStrand);
  printf("This is the reversed strand: %s\n", aStrand);

  // testing call for function 4
  char aStrand4[SIZE] = "GATCGATGCAA";
  printf("This is the original string: %s\n", aStrand4);
  complementIt(aStrand4);
  printf("This is the complement string: %s\n", aStrand4);

  // testing call for function 5
  int resFunction5; 
  char aStrand5 [SIZE] = "GGAAGG";
  resFunction5 = isItPalindrome(aStrand5);
  printf("The result for  function 5 is (true or false): %d\n", resFunction5);

  // testing call for function 6
  int resFunction6;
  char aStrand6 [SIZE] = "ATATATAT";
  resFunction6 = isStrandDnaPalindrome (aStrand6);
  printf("The result for function 6 is (true or false): %d\n", resFunction6);

  // testing call for function 7
  int resFunction7;
  char aStrand7 [SIZE] = "GCATATCG";
  resFunction7 = howMany (aStrand7, 'T');
  printf("here is the orignial string: %s\n", aStrand7);
  printf("The total number of the declared neuclotide is: %d\n", resFunction7);

  // testing call for function 8
  char aStrand8 [SIZE] = "TGCTAAGAC";
  char mRNA [SIZE];
  dnaToMrna (aStrand8, mRNA);
  printf("This is the original DNA sequence: %s\n", aStrand8);
  printf("This is the mRna strand: %s\n", mRNA);

  // testing call for function 9
  char aSeq[SIZE] = "ATCTGACAAAA";
  translateDnaToMrnaProteins (aSeq);
 
  return 0;
}
