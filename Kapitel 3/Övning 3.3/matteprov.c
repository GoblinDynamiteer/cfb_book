#include <stdio.h>

/*
Skriv ett program som visar vilket betyg en elev har fått på ett matteprov. 
Max: 50P, E:25, D:30, C:35, B:40, A:45

Poäng matas in av användaren.
*/

int main()
{
	int poang; //variabel för poäng
	printf("Ange poäng som eleven har fått på matteprovet: ");
	
	//inmatning av poäng
	scanf("%d", &poang);
	//Skriver ut det betyg eleven har fått, om under 25 poäng är eleven underkänd
	if (poang < 25)
		printf("Eleven har blivit underkänd på matteprovet!");
	
	else if (poang < 30)
		printf("Eleven har fått betyget E på matteprovet!");
	
	else if (poang < 35)
		printf("Eleven har fått betyget D på matteprovet!");

	else if (poang < 40)
		printf("Eleven har fått betyget C på matteprovet!");
	
	else if (poang < 45)
		printf("Eleven har fått betyget B på matteprovet!");
	
	else
		printf("Eleven har fått betyget A på matteprovet!");
	
	return 0;
}