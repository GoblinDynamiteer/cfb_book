#include <stdio.h>

/*
Övning 8.1
Skapa två fält:
Det ena ska ha fyra element av typen double, samtliga ska ha värdet 0
Det andra ska ha värdena av euro-sedlarna, 5, 10, 20, 50, 100, 200, 500

Programmet ska skriva ut värdena för elementen i de två fälten.
*/

int main(){
	double noll[4] = {0,0,0,0};
	int euro[7] = {5,10,20,50,100,200,500};
	printf("Arrays/fält:\nNollor: ");
	for (int i=0;i<sizeof noll/sizeof noll[0];i++){	//sizeof x/sizeof x[0]	 -- ger antalet element i en variabel
		printf("%.2f\t", noll[i]);
	}
	printf("\nSedlar: ");
	for (int i=0;i<sizeof euro/sizeof euro[0];i++){
		printf("%d\t", euro[i]);
	}
	printf("\n");
}