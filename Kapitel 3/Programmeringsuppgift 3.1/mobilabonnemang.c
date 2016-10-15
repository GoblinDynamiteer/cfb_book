#include <stdio.h>
/*
Programmeringsuppgift 3.1
Sida 72

En operat�r har tre abbonemang f�r telefoni: Kontant, Normal & Plus. 

Kontant l�nar sig om man ringer h�gst 33 min/m�nad 
Normal l�nar sig om man ringer mellan 33 - 66 min/m�nad
Plus l�nar sig om man ringer �ver 66 min/m�nad

L�s in uppskattat antal minuter man kommer anv�nda p� en m�nad
och ange vilket alternativ som passar b�st
*/

int main()
{
	//Deklarerar och l�ser in data f�r variabel min, antal minuter
	int min;
	printf("Ange antal minuter du uppskattar att ringa f�r under en m�nad: ");
	scanf("%d", &min);
	//Best�mmer vilket abonnemang som l�mpar sig b�st och skriver ut dess namn
	if (min <= 33)
		printf("Det l�nar sig b�st med abonnemanget \"Kontant\""); //citationstecken (hartassar, "") skrivs ut i printf med \"
	else if (min > 33 && min <= 66)
		printf("Det l�nar sig b�st med abonnemanget \"Normal\"");
	else 
		printf("Det l�nar sig b�st med abonnemanget \"Plus\"");
	return 0;
}
