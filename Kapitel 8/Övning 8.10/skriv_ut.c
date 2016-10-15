#include <stdio.h>
/*
�vning 8.10, Sida 177

Skriv en funktion 'skriv_ut'
den ska som enda parameter f� en tv�dimensionell int array, med radl�ngd 5
funktion ska skriva ut arrayen i kommandof�nstret, s� att varje rad skrivs p�
en egen rad. Tab ( \t ) ska anv�ndas mellan tecknen.

Skriv sedan ett program som testar funktionen 'skriv_ut' samt funktionen 'aendra' 
fr�n sida 177.

Skapa f�rst en array a, med 10 rader och 5 kolumner. Anropa f�rst funktionen 'aendra' 
och sedan funktionen 'skriv_ut'



funktionen 'aendra' fr�n sida 177, �ndrar alla element i arrayen
s� att de kommer att ineh�lla summan av sitt radnummer och
sitt kolumnnummer
*/
void aendra(int f[][5], int antal_rader){
	for(int i=0;i<antal_rader;i++){
		for(int j=0;j<5;j++){
			f[i][j] = i+j;
		}
	}
}

//funktion skriv_ut, skriver ut v�rdena fr�n en array till kommandof�nstret
void skriv_ut(int array[0][5]){
	//n�stlade for-satser som skriver ut 10 rader ut arrayen, i 5 kolumner.
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
	aendra(a, 10);	//Anropar funktionen aendra, med argumentet f�r antal rader = 10
	skriv_ut(a);
	return 0;
}