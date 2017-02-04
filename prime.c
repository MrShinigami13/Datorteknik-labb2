/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include<math.h>

bool intcheck(double variable)
{
	int intpartofvariable = (int)variable;
	return (variable == intpartofvariable);
}

int is_prime(int n){
	bool prime;	//variabel för att retunera 0 eller 1 beroende om det är ett primtal eller inte
	double n_sqrt = sqrt(n);
	for (i = 0; i <= n_sqrt; i++)
	{
		double prime_check = n / i;
		prime = intcheck(prime_check);
	}



	if(prime)
	{
		return 1;
	}
	else
	{
		return 0;
	}
  
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
