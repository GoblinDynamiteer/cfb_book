#include <stdio.h>

/*
Ber�kna m�nadskostnad f�r samtal med mobiltelefon. 
Anv�ndaren anger antal minuter och kostnad per minut. 
Om totalkostnad �r �ver 1000 kr f�r man 10% rabatt
*/

int main()
{
	int minuter; //Variabel f�r antal minuter samtalstid f�r en m�nad
	float kostnad, rabatt = 1.0; //variabel, samt variabel f�r eventuell rabatt
	printf("Ange samtalstid: ");
	scanf("%d", &minuter);
	printf("Ange kostnad per minut: ");
	scanf("%f", &kostnad);
	if (kostnad*minuter >= 1000){ //om totalkostnad �r lika med eller �ver 1000 kr s�tts rabatten till 10%
		rabatt = 0.9; 
		}
	//Skriver ut total m�nadskostnad, inklusive eventuell rabatt:
	printf("Din m�nadskostnad �r %0.2f kr", kostnad*minuter*rabatt);
	return 0;
}