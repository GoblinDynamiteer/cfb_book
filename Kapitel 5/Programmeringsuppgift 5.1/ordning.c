/*
Programmeringsuppgift 5.1, Sida 99
Skriv i pseudokod: 
L�s in ett antal tal, unders�k om de har skrivits in i storleksordning eller inte

PSEUDOKOD:
ange en array kallad tal
ange n och s�tt till 1
ange stege_upp och stege_ner
upprepa f�ljande ett  godtyckligt antal g�nger
	l�s in ett tal till tal arrayplats n, bryt om anv�ndaren vill
	�ka n med 1
upprepa f�ljande n g�nger
	j�mf�r v�rden i arrayen med varandra i ordning, �r de i stigande ordning, och steg_upp inte �r 0, s�tt stege_upp till 1
	annars s�tt stege_upp till 0
	j�mf�r v�rden i arrayen med varandra i ordning, �r de i fallande ordning, och steg_ner inte �r 0 s�tt stege_ner till 1
	annars s�tt stege_ner till 0
om stege_ner eller stege_upp �r 1, skriv ut att talen �r i ordning
annars skriv ut att talen ej �r i ordning

KOD + PSEUDOKOD:
*/

#include <stdio.h>

int main(){
	/*
	ange en array kallad tal
	ange n och s�tt till 1
	ange stege_upp och stege_ner
	*/
	int tal[100], stege_upp, stege_ner, n=1;
	/*
	upprepa f�ljande ett  godtyckligt antal g�nger
	l�s in ett tal till tal arrayplats n, bryt om anv�ndaren vill
	�ka n med 1
	*/
	while(1){
		printf("Ange tal: ");
		if (scanf("%d", &tal[n]) != 1)
			break;
		n++;
	}
	/*
	upprepa f�ljande n g�nger
	j�mf�r v�rden i arrayen med varandra i ordning, �r de i stigande ordning, och steg_upp inte �r 0, s�tt stege_upp till 1
	annars s�tt stege_upp till 0
	j�mf�r v�rden i arrayen med varandra i ordning, �r de i fallande ordning, och steg_ner inte �r 0 s�tt stege_ner till 1
	annars s�tt stege_ner till 0
	*/
	for (int i=1;i!=n-1;i++){
		if (tal[i] < tal[i+1] && stege_upp != 0)
			stege_upp = 1;
		else
			stege_upp = 0;
		if (tal[i] > tal[i+1] && stege_ner != 0)
			stege_ner = 1;
		else 
			stege_ner = 0;
	}
	/*
	om stege_ner eller stege_upp �r 1, skriv ut att talen �r i ordning
	annars skriv ut att talen ej �r i ordning
	*/
	if (stege_ner == 1 || stege_upp == 1)
		printf("\nTalen �r i storleksordning");
	else
		printf("\nTalen �r ej i storleksordning");
	return 0;
}