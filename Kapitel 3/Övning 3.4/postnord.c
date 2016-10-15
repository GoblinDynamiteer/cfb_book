#include <stdio.h>

/*
Övning 3.4
Sida 68 - Logiska uttryck

Ange om ett paket som ska skickas med Postnord har tillåtna mått. 
LängdMax=600mm
LängdMin=140mm
TjocklekMax=100mm 
BreddMin=90mm
Bredd+Längd+Tjocklek Max=900mm

Skriv ut texten "Måtten OK", eller "Felaktiga mått"
*/

int main()
{
	int l,b,t; //Variabler för paketets Längd, Bredd och Tjocklek
	//Läs in data för variabler:
	printf("Ange paketets längd: ");
	scanf("%d", &l);
	printf("Ange paketets bredd: ");
	scanf("%d", &b);
	printf("Ange paketets tjocklek: ");
	scanf("%d", &t);
	//Testar om måtten uppfyller de satta kraven för att få skicka paketet
	if (l >= 140 && l <= 600 && t <= 100 && b >= 90 && b + l + t <= 900)
		printf("Måtten OK");
	else
		printf("Felaktiga mått");
	return 0;
}