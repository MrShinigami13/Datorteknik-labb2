/*
 print-prime.c
 By David Broman.
 Last modified: 2019-01-22 by Erik Mickols
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6
int col = COLUMNS;

int is_prime(int n){
	if(n <=3){
		return n>1;
	} else if((n%2==0)|(n%3==0)){
		return 0;
	}
	int i = 5;
	while(i*i<=n){
		if((n%i==0)|(n%(i+2)==0)){
			return 0;
		} i = i+6;
	} return 1;
}

void print_number(int n){
	if(col>1){
		printf("%10d ", n);
		col--;
	} else if(col==1){
		printf("%10d ", n);
		printf("\n");
		col = 6;
	}
}


void print_sieves(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
  //int A[n];
  int* p = (int*) malloc(n*sizeof(int));
  int* p_copy = p;
  for(int i=2; i<n; i++){
	  p[i] = 1;
	  
  }
  for(int i=2; i<(double)sqrt(n); i++){
	  if(p[i]==1){
		  for(int j=i*i; j<n; j=j+i){
				p[j] = 0;
		  }
	  }
  }
  for(int i=2; i<n; i++){
	  if(p[i]==1){ print_number(i); }
  }
  free(p_copy);
}





// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an integer number.\n");
  return 0;
}

 
