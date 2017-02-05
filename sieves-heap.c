// program for geting prime numbers using sieves
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6	// bestämer hur många columner det ska listas i



int calc = 0;
void print_number(int n)
{
	//printf("debug10");
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
	//double &n_h[n]; // bool_array är bytt mot n_h!!!!!
	int *n_h = malloc(n*sizeof(int));
	//printf("debug1");
	for (int i = 0; i < n; i++)	// skapa en array med bara 1:or
	{
		n_h[i] = 1;

		//printf("debug2");
	}
	//printf("debug3");
	double condition_varible = sqrt(n);
	for (int i = 2; i <= condition_varible; i++)	// göra om den till en array med blandade värden för att sedan skriva ut primtal
	{
		//printf("debug4");
		if (n_h[i] == 1)
		{
			//printf("debug5");
			double sieves_counter = (i);
			double j = 0;
			double y = 0;
			int j_int = 0;

			while ( j < n)
			{
				j = ((sieves_counter*sieves_counter) + (y*sieves_counter));
				y++;
				j_int = (int)j;
				//printf("%10d ", j);
				//printf("debug6");
				//printf("%10d ", n);
				n_h[j_int] = 0;

			}
		}

	}
	//printf("debug7");
	for (int i = 2; i < n; i++)
	{
		//printf("debug8");
		if (n_h[i] == 1)
		{
			//printf("debug9");
			int print_variable = (i);
			print_number(print_variable);
		}

	}
			free(n_h);
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
