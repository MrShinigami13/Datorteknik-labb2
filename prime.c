/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <math.h>

double intcheck(double variable)
{
	int intpartofvariable = (int)variable;
	double return_value = (double)intpartofvariable / variable;
	return (return_value);
}

int is_prime(int n){
	double prime = 1;	//variabel för att retunera 0 eller 1 beroende om det är ett primtal eller inte
	double n_sqrt;
	n_sqrt = sqrt(n);
	for (int i = 2; i >= n_sqrt; i++) // här görs räkngen om det är primtal
	{
		
		double prime_check = n / i;	// check för att kolla om det är ett primtal
		prime = intcheck(prime_check);
		if (prime == 1)
		{
			break;
		} 
	}



	if(prime != 1)	//kollar om det är ett primtal och skrimer ut 0 eller 1 beroente på resultatet
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
