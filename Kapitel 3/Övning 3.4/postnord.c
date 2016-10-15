#include <stdio.h>

/*
�vning 3.4
Sida 68 - Logiska uttryck

Ange om ett paket som ska skickas med Postnord har till�tna m�tt. 
L�ngdMax=600mm
L�ngdMin=140mm
TjocklekMax=100mm 
BreddMin=90mm
Bredd+L�ngd+Tjocklek Max=900mm

Skriv ut texten "M�tten OK", eller "Felaktiga m�tt"
*/

int main()
{
	int l,b,t; //Variabler f�r paketets L�ngd, Bredd och Tjocklek
	//L�s in data f�r variabler:
	printf("Ange paketets l�ngd: ");
	scanf("%d", &l);
	printf("Ange paketets bredd: ");
	scanf("%d", &b);
	printf("Ange paketets tjocklek: ");
	scanf("%d", &t);
	//Testar om m�tten uppfyller de satta kraven f�r att f� skicka paketet
	if (l >= 140 && l <= 600 && t <= 100 && b >= 90 && b + l + t <= 900)
		printf("M�tten OK");
	else
		printf("Felaktiga m�tt");
	return 0;
}