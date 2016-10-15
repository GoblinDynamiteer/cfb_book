#include <stdio.h>
/*
Programmeringsuppgift 3.1
Sida 72

En operatör har tre abbonemang för telefoni: Kontant, Normal & Plus. 

Kontant lönar sig om man ringer högst 33 min/månad 
Normal lönar sig om man ringer mellan 33 - 66 min/månad
Plus lönar sig om man ringer över 66 min/månad

Läs in uppskattat antal minuter man kommer använda på en månad
och ange vilket alternativ som passar bäst
*/

int main()
{
	//Deklarerar och läser in data för variabel min, antal minuter
	int min;
	printf("Ange antal minuter du uppskattar att ringa för under en månad: ");
	scanf("%d", &min);
	//Bestämmer vilket abonnemang som lämpar sig bäst och skriver ut dess namn
	if (min <= 33)
		printf("Det lönar sig bäst med abonnemanget \"Kontant\""); //citationstecken (hartassar, "") skrivs ut i printf med \"
	else if (min > 33 && min <= 66)
		printf("Det lönar sig bäst med abonnemanget \"Normal\"");
	else 
		printf("Det lönar sig bäst med abonnemanget \"Plus\"");
	return 0;
}
