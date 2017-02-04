/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <math.h>

int intcheck(double variable)
{
	int intpartofvariable = (int)variable;
	return (variable == intpartofvariable);
}

int is_prime(int n){
	double prime;	//variabel för att retunera 0 eller 1 beroende om det är ett primtal eller inte
	double n_sqrt;
	double n_new = n;
	n_sqrt = sqrt(n_new);
	for (int i = 0; i <= n_sqrt; i++) // här görs räkngen om det är primtal
	{
		
		double prime_check = n / i;	// check för att kolla om det är ett primtal
		prime = intcheck(prime_check);
	}



	if(prime == 1)	//kollar om det är ett primtal och skrimer ut 0 eller 1 beroente på resultatet
	{
		return 1; // ja det är primtal
	}
	else
	{
		return 0;	// nej det är inte ett primtal
	}
  
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
