#include <stdio.h>

/*
�vning 8.1
Skapa tv� f�lt:
Det ena ska ha fyra element av typen double, samtliga ska ha v�rdet 0
Det andra ska ha v�rdena av euro-sedlarna, 5, 10, 20, 50, 100, 200, 500

Programmet ska skriva ut v�rdena f�r elementen i de tv� f�lten.
*/

int main(){
	double noll[4] = {0,0,0,0};
	int euro[7] = {5,10,20,50,100,200,500};
	printf("Arrays/f�lt:\nNollor: ");
	for (int i=0;i<sizeof noll/sizeof noll[0];i++){	//sizeof x/sizeof x[0]	 -- ger antalet element i en variabel
		printf("%.2f\t", noll[i]);
	}
	printf("\nSedlar: ");
	for (int i=0;i<sizeof euro/sizeof euro[0];i++){
		printf("%d\t", euro[i]);
	}
	printf("\n");
}