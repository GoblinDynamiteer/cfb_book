#include <stdio.h>

/*
Skriv ett program som visar vilket betyg en elev har f�tt p� ett matteprov. 
Max: 50P, E:25, D:30, C:35, B:40, A:45

Po�ng matas in av anv�ndaren.
*/

int main()
{
	int poang; //variabel f�r po�ng
	printf("Ange po�ng som eleven har f�tt p� matteprovet: ");
	
	//inmatning av po�ng
	scanf("%d", &poang);
	//Skriver ut det betyg eleven har f�tt, om under 25 po�ng �r eleven underk�nd
	if (poang < 25)
		printf("Eleven har blivit underk�nd p� matteprovet!");
	
	else if (poang < 30)
		printf("Eleven har f�tt betyget E p� matteprovet!");
	
	else if (poang < 35)
		printf("Eleven har f�tt betyget D p� matteprovet!");

	else if (poang < 40)
		printf("Eleven har f�tt betyget C p� matteprovet!");
	
	else if (poang < 45)
		printf("Eleven har f�tt betyget B p� matteprovet!");
	
	else
		printf("Eleven har f�tt betyget A p� matteprovet!");
	
	return 0;
}