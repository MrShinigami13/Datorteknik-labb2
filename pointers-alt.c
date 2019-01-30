

#include <stdlib.h>
#include <stdio.h>

#define SIZE 20

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";

//int* list1 = malloc(sizeof(int)*SIZE);
//int* list2 = malloc(sizeof(int)*SIZE);
int lst1[SIZE];
int lst2[SIZE];
int *list1 = lst1;
int *list2 = lst2;
char* count = 0;


void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

void copycodes(const char* txt, int* lst, char* c){
	while(*txt!=0){
		*lst = (int)*txt;
		txt++;
		lst++;
		*c = *c + 1;
	}
}


void work(){
	copycodes(text1, list1, (char*) &count);
	copycodes(text2, list2, (char*) &count);
}


int main(void){
  work();

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}
