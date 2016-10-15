#include <stdio.h>
/*
Övning 8.10, Sida 177

Skriv en funktion 'skriv_ut'
den ska som enda parameter få en tvådimensionell int array, med radlängd 5
funktion ska skriva ut arrayen i kommandofönstret, så att varje rad skrivs på
en egen rad. Tab ( \t ) ska användas mellan tecknen.

Skriv sedan ett program som testar funktionen 'skriv_ut' samt funktionen 'aendra' 
från sida 177.

Skapa först en array a, med 10 rader och 5 kolumner. Anropa först funktionen 'aendra' 
och sedan funktionen 'skriv_ut'



funktionen 'aendra' från sida 177, ändrar alla element i arrayen
så att de kommer att inehålla summan av sitt radnummer och
sitt kolumnnummer
*/
void aendra(int f[][5], int antal_rader){
	for(int i=0;i<antal_rader;i++){
		for(int j=0;j<5;j++){
			f[i][j] = i+j;
		}
	}
}

//funktion skriv_ut, skriver ut värdena från en array till kommandofönstret
void skriv_ut(int array[0][5]){
	//nästlade for-satser som skriver ut 10 rader ut arrayen, i 5 kolumner.
	for(int i=0;i<10;i++){
		for(int j=0;j<5;j++){
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}

int main(){
	printf("\t\tArray a\n\t\tKolumn\n1\t2\t3\t4\t5\n-------------------------------------\n");
	int a[10][5]; 	//Array med 10 rader och 5 kolumner
	aendra(a, 10);	//Anropar funktionen aendra, med argumentet för antal rader = 10
	skriv_ut(a);
	return 0;
}