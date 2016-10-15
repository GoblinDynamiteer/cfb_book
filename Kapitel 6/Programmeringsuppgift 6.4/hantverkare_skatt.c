#include <stdio.h>
/*
Programmeringsuppgift 6.4

Skriv en funktion som räknar ut hur mycket en hantverkare
måste begära av en kund för att själv få ut ett visst belopp x
efter att skatter är betalda.

parametrar för funktionen:
1 önskat belopp: x
2 kommunal skattesats i proent
3 LAG/MEDEL/HOG - definierar skattesats

Villkor:
Du får inte använda siffror utöver 1 - 0,01 - 100

Tips:
Beräkna först ut hur stor lönen ska vara med
lön = x/(1-0.01p) där p är summan av procent-
satserna för statlig och kommunal skatt.

Lägg sedan till egenavgifterna som beräknas
i procent av lönen. Lägg slutligen till momsen
som beräknas i procent på totalbelopp (dvs. lönen
plus egenavgifterna)
*/

//Definitioner av konstanter enl. boken:
#define MOMS 25
#define ARB_AVG 28.97
#define STAT_LAG 0 
#define STAT_MEDEL 20
#define STAT_HOG 25
#define LAG 1 
#define MEDEL 2
#define HOG 3

double rakna_pris(double x, double kommunskatt, int niva){
	double lon, skatt_stat;
	//IF-satser som sätter den statliga skattenivån beroende på användarens inmatning i main-funktionen:
	if (niva == LAG)
		skatt_stat = STAT_LAG;
	else if (niva == MEDEL)
		skatt_stat = STAT_MEDEL;
	else (niva == HOG)
		skatt_stat = STAT_HOG;
	//lön = x/(1-0.01p) där p är summan av procentsatserna för statlig och kommunal skatt
	lon = x / (1.0-0.01*(skatt_stat+kommunskatt)); 
	//Lägg sedan till egenavgifterna som beräknas i procent av lönen:
	lon += lon * (ARB_AVG/100.0); //Fungerar inte för mig om jag inte sätter 100.0, dock är detta emot uppgiftens villkor
	//Lägg slutligen till momsensom beräknas i procent på totalbelopp (dvs. lönen plus egenavgifterna):
	return lon + lon * (MOMS/100.0);
}

int main(){
	double belopp, kommunskatt;
	int skatteniva; //För val av skattenivå
	printf("Ange hur mycket du vill ha i belopp efter skatt: ");
	scanf("%lf", &belopp);
	printf("Ange kommunalskatt i procent: ");
	scanf("%lf", &kommunskatt);
	printf("Ange statlig skattenivå 1: låg, 2: medel, 3: hög: ");
	scanf("%d", &skatteniva);
	printf("Du måste begära %.2lf kr i pris för kunden för att få ut beloppet %.2lf efter skatt!", rakna_pris(belopp, kommunskatt, skatteniva), belopp);
	return 0;
}