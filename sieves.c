// program for geting prime numbers using sieves
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6	// bestämer hur många columner det ska listas i



int calc = 1;
void print_number(int n)
{
	printf("debug10");
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
	double bool_array[n];
	printf("debug1");
	for (int i = 0; i < n; i++)	// skapa en array med bara 1:or
	{
		bool_array[i] = 1;
		printf("debug2");
	}
	printf("debug3");
	double condition_varible = sqrt(n);
	for (int i = 1; i < condition_varible; i++)	// göra om den till en array med blandade värden för att sedan skriva ut primtal
	{
		printf("debug4");
		if (bool_array[i] == 1)
		{
			printf("debug5");
			double sieves_counter = (i + 1);
			double x = 0;
			int	z = 0;
			
			for (int y = 0; z < n; y++)
			{
				x = ((sieves_counter*sieves_counter) + (y*sieves_counter)); //#FIXME bara fel med matten här ni
				z = (int)x;
				printf("%10d ", z);
				printf("debug6");
				printf("%10d ", n);
				bool_array[z] = 0;
			}
		}
		
	}
	printf("debug7");
	for (int i = 0; i < n; i++)
	{
		printf("debug8");
		if (bool_array[n] == 1)
		{
			printf("debug9");
			int print_variable = (i + 1);
			print_number(print_variable);
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