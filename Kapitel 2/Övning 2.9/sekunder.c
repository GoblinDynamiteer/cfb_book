#include <stdio.h>

int main()
{
	int tid, tim, min, sek; //Deklarerar variabler för tid=totalt antal sekunder, timmar, minuter och sekunder.
	printf("Ange (ett stort antal) sekunder: ");
	scanf("%d", &tid); //Användarinput för att sätta ett heltalsvärde till var tid
	//Beräknar hur många timmar det går på det sekund-värde som finns i var tid. en timme är 60 * 60 sekunder
	//Eftersom tid innehåller heltal, och 60 * 60 är heltal, så blir det en heltalsdivision, hur många gånger 3600 får plats i "tid", utan decimal
	tim = tid / (60 * 60); 
	//% är restoperator, den beräknar hur mycket som "blir över" efter en heltalsdivision. 
	//ex: 13 % 5 = 3. 5 går 2 gånger i 13, och det blir 2 över.
	//variabeln min sätts till att vara en heltalsdivision med 60 (minut i sekunder) av resten av de sekunder som blev över från timme-beräkningen
	min = (tid % (60 * 60)) / 60;
	//det värde som blir över efter en heltalsdivision med 60 på var tid är återstående sekunder.
	sek = tid % 60;
	//skriver ut hur många timmar, minuter och sekunder det går på inputvärdet till variabeln tid.
	printf("Det går %d timmar, %d minuter och %d sekunder på %d sekunder", tim, min, sek, tid);
	return 0;
}