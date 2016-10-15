#include <stdio.h>

/*
Övning 6.8, Sida 119

Skriv om programmet i övning 6.2, så att funktionen nfak
ligger sist i programmet

Funktionen ska heta nfak
*/

//funktionen nfak deklareras innan main, så att den kan hittas av kompilatorn
double nfak(double);

int main(){
	double tal;
	printf("Ange ett tal för att beräkna dess fakultet: ");
	scanf("%lf", &tal);
	printf("Fakulteten för talet är %.0lf", nfak(tal));
	return 0;
}

//funktion för att beräkna fakulteten av ett tal
double nfak(double n){
	double sum =1;
	for (int i=1; i<=n;i++)
		sum *= i;
	return sum;
}