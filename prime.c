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
	double prime = 1;	//variabel f�r att retunera 0 eller 1 beroende om det �r ett primtal eller inte
	double n_sqrt;
	n_sqrt = sqrt(n);
	for (int i = 2; i >= n_sqrt; i++) // h�r g�rs r�kngen om det �r primtal
	{
		
		double prime_check = n / i;	// check f�r att kolla om det �r ett primtal
		prime = intcheck(prime_check);
		if (prime == 1)
		{
			break;
		} 
	}



	if(prime != 1)	//kollar om det �r ett primtal och skrimer ut 0 eller 1 beroente p� resultatet
	{
		return 1; // ja det �r primtal
	}
	else
	{
		return 0;	// nej det �r inte ett primtal
	}
  
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
