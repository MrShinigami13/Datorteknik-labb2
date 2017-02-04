// program for geting prime numbers using sieves
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6	// bestämer hur många columner det ska listas i



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

void print_sieves(int n)
{
	print_number(n);
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