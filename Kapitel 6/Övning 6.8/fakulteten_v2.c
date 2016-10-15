#include <stdio.h>

/*
�vning 6.8, Sida 119

Skriv om programmet i �vning 6.2, s� att funktionen nfak
ligger sist i programmet

Funktionen ska heta nfak
*/

//funktionen nfak deklareras innan main, s� att den kan hittas av kompilatorn
double nfak(double);

int main(){
	double tal;
	printf("Ange ett tal f�r att ber�kna dess fakultet: ");
	scanf("%lf", &tal);
	printf("Fakulteten f�r talet �r %.0lf", nfak(tal));
	return 0;
}

//funktion f�r att ber�kna fakulteten av ett tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}