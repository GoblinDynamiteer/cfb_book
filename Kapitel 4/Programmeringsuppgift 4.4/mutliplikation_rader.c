#include <stdio.h>

/*
Programmeringsuppgift 4.4, Sida 90

Skriv ett program som skriver ut en multiplikationstabell enligt: 
1
2		4
3		6		9
4		8		12	16
5		10	15	20	25

Antal rader matas in av användaren.
Tips: Mata in ett tal över 10000 för en fräsig siffershow

*/

int main(){
	int rader;
	printf("Ange antal rader: ");
	scanf("%d", &rader);				 //användarinmatning av antal rader som ska visas
	for(int i=1;i<=rader;i++){  	//så länge i är mindre eller lika med antal inmatade rader så körs for-loopen
		for(int s=1;s<=i;s++)  		//så länge s är mindre eller lika med i så körs for-loopen (Loopen kommer köra lika många gånger som i är stort)
			printf("%d\t", i*s);			//printf matar ut i*s som är multiplikationstabellen för siffra i, s antal gånger
		printf("\n");							//ny rad görs i första for-satsen efter att den nästlade for-satsen körts klar.
	}
	return 0;
}