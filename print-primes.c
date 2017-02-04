/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6



double intcheck(double variable)	// för att kolla om det är jämt delbart
{
	int intpartofvariable = (int)variable;
	double return_value = ((double)intpartofvariable / variable);
	return (return_value);
}

int is_prime(double n) {
	double prime = 1;	//variabel för att retunera 0 eller 1 beroende om det är ett primtal eller inte
	double n_sqrt;
	n_sqrt = sqrt(n);
	for (double i = 2; i <= n_sqrt; i++) // här görs räkngen om det är primtal
	{

		double prime_check = (n / i);	// check för att kolla om det är ett primtal
		prime = intcheck(prime_check);
		if (prime == 1)
		{
			break;
		}
	}



	if (prime != 1)	//kollar om det är ett primtal och skrimer ut 0 eller 1 beroente på resultatet
	{
		return 1; // ja det är primtal
	}
	else
	{
		return 0;	// nej det är inte ett primtal
	}

}
int calc = 1;

void print_number(int n)
{
	int colu = COLUMNS;
	if (calc == colu)	// byter rad efter "COLUMNS" antal siffror
	{
		printf("\n");
		printf("%10d ", n);
		calc = 1;
	}
	else
	{
		printf("%10d ", n);
		calc++;
	}
	
}


void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS


	for (int i = 1; i < n; i++)
	{
		
		int return_value = is_prime(i);
		if (return_value == 1)
		{
			print_number(i);
		}
			
		
	}
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}

 
