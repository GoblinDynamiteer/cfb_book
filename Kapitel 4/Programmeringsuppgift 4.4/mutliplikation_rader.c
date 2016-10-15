#include <stdio.h>

/*
Programmeringsuppgift 4.4, Sida 90

Skriv ett program som skriver ut en multiplikationstabell enligt: 
1
2		4
3		6		9
4		8		12	16
5		10	15	20	25

Antal rader matas in av anv�ndaren.
Tips: Mata in ett tal �ver 10000 f�r en fr�sig siffershow

*/

int main(){
	int rader;
	printf("Ange antal rader: ");
	scanf("%d", &rader);				 //anv�ndarinmatning av antal rader som ska visas
	for(int i=1;i<=rader;i++){  	//s� l�nge i �r mindre eller lika med antal inmatade rader s� k�rs for-loopen
		for(int s=1;s<=i;s++)  		//s� l�nge s �r mindre eller lika med i s� k�rs for-loopen (Loopen kommer k�ra lika m�nga g�nger som i �r stort)
			printf("%d\t", i*s);			//printf matar ut i*s som �r multiplikationstabellen f�r siffra i, s antal g�nger
		printf("\n");							//ny rad g�rs i f�rsta for-satsen efter att den n�stlade for-satsen k�rts klar.
	}
	return 0;
}