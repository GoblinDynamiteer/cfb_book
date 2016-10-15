#include <stdio.h>

/*
Programmeringsuppgift 6.5, Sida 121

Skriv en funktion som får ett heltal i intervallet 1-10
som parameter. Funktionen ska skriva ut en multi-
plikationstabell för det angivna talet.

Exempel:
Om 6 matas in:
Rad 1: 	1 	6
Rad 2:	2	12
Rad 3: 	3	18
Rad 4	4	24
...
Rad 10:10	60

*/

void multiplikationstabell(int rader){
	//printf("jag funkar!");
	for(int i =1;i<=10;i++)
		printf("%d\t\t%d\n",i,i*rader);
};

int main(){
	int rader;
	printf("Ange antal rader för tabell: ");
	scanf("%d", &rader);
	multiplikationstabell(rader);
	return 0;
}