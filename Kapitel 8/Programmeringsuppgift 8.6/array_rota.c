#include <stdio.h>

/*
Programmeringsuppgift 8.6, Sida 179
Skriv en funktion som roterar alla elementen i en heltalsarray ett steg �t h�ger

a[2] ska till a[3] osv!


Funktion rotation byter plats p� arrayens element, ett steg �t h�ger.
Initialt s�tts det sista elementet till en int variabel 'hallare'.
sedan k�rs en for-sats bakifr�n och ger elementet i, v�rdet f�r i-1.
Efter att loopen �r klar s�tts arrayens f�rsta element till hallare, som har 
arrayens sista v�rde.
*/
void rotation(int a[], int antal){
	int hallare = a[antal-1];
	for(int i=antal-1;i>=0;i--){
		a[i] = a[i-1];
	}
	a[0] = hallare;
}

int main(){
	int array[] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0}; //Array med testv�rden, f�r funktionen.
	//Skriver ut arrayen 100 g�nger, med anrop till funktionen rotera efter varje utskrift.
	int x=1;
	while(1){
		rotation(array, sizeof array/sizeof array[0]);
			for(int i=0;i<sizeof array/sizeof array[0];i++){
				printf("%d ", array[i]);
			}	
		printf("\n");
		x++;
		if(x==100){
			break;	
		}
	}
	return 0;
}