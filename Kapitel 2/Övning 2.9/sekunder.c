#include <stdio.h>

int main()
{
	int tid, tim, min, sek; //Deklarerar variabler f�r tid=totalt antal sekunder, timmar, minuter och sekunder.
	printf("Ange (ett stort antal) sekunder: ");
	scanf("%d", &tid); //Anv�ndarinput f�r att s�tta ett heltalsv�rde till var tid
	//Ber�knar hur m�nga timmar det g�r p� det sekund-v�rde som finns i var tid. en timme �r 60 * 60 sekunder
	//Eftersom tid inneh�ller heltal, och 60 * 60 �r heltal, s� blir det en heltalsdivision, hur m�nga g�nger 3600 f�r plats i "tid", utan decimal
	tim = tid / (60 * 60); 
	//% �r restoperator, den ber�knar hur mycket som "blir �ver" efter en heltalsdivision. 
	//ex: 13 % 5 = 3. 5 g�r 2 g�nger i 13, och det blir 2 �ver.
	//variabeln min s�tts till att vara en heltalsdivision med 60 (minut i sekunder) av resten av de sekunder som blev �ver fr�n timme-ber�kningen
	min = (tid % (60 * 60)) / 60;
	//det v�rde som blir �ver efter en heltalsdivision med 60 p� var tid �r �terst�ende sekunder.
	sek = tid % 60;
	//skriver ut hur m�nga timmar, minuter och sekunder det g�r p� inputv�rdet till variabeln tid.
	printf("Det g�r %d timmar, %d minuter och %d sekunder p� %d sekunder", tim, min, sek, tid);
	return 0;
}