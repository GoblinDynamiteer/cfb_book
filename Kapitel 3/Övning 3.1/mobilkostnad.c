#include <stdio.h>

/*
Beräkna månadskostnad för samtal med mobiltelefon. 
Användaren anger antal minuter och kostnad per minut. 
Om totalkostnad är över 1000 kr får man 10% rabatt
*/

int main()
{
	int minuter; //Variabel för antal minuter samtalstid för en månad
	float kostnad, rabatt = 1.0; //variabel, samt variabel för eventuell rabatt
	printf("Ange samtalstid: ");
	scanf("%d", &minuter);
	printf("Ange kostnad per minut: ");
	scanf("%f", &kostnad);
	if (kostnad*minuter >= 1000){ //om totalkostnad är lika med eller över 1000 kr sätts rabatten till 10%
		rabatt = 0.9; 
		}
	//Skriver ut total månadskostnad, inklusive eventuell rabatt:
	printf("Din månadskostnad är %0.2f kr", kostnad*minuter*rabatt);
	return 0;
}