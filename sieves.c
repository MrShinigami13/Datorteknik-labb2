// program for geting prime numbers using sieves
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6	// bestämer hur många columner det ska listas i



int calc = 1;
void print_number(int n)
{
	printf("%10d ", "debug10");
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

void print_sieves(int n)
{
	int bool_array[n];
	printf("%10d ", "debug1");
	for (int i = 0; i < n; i++)	// skapa en array med bara 1:or
	{
		bool_array[i] = 1;
		printf("%10d ", "debug2");
	}
	printf("%10d ", "debug3");
	for (int i = 2; i < sqrt(n); i++)	// göra om den till en array med blandade värden för att sedan skriva ut primtal
	{
		printf("%10d ", "debug4");
		if (bool_array[i] == 1)
		{
			printf("%10d ", "debug5");
			int y = 0;
			for (double x =( pow(i,2)+y*i) ; y < n; y++)
			{
				printf("%10d ", "debug6");
				bool_array[i] = 0;
			}
		}
		
	}
	printf("%10d ", "debug7");
	for (int i = 0; i < n; i++)
	{
		printf("%10d ", "debug8");
		if (bool_array[n] == 1)
		{
			printf("%10d ", "debug9");
			print_number((n+1));
		}
		
	}
}


// grund funktionen för att fråga till vilket tal som primtal ska listas
// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]) {
	if (argc == 2)
		print_sieves(atoi(argv[1]));
	else
		printf("Please state an interger number.\n");
	return 0;
}