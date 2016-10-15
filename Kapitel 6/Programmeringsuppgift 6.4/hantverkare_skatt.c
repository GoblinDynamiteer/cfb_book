#include <stdio.h>
/*
Programmeringsuppgift 6.4

Skriv en funktion som r�knar ut hur mycket en hantverkare
m�ste beg�ra av en kund f�r att sj�lv f� ut ett visst belopp x
efter att skatter �r betalda.

parametrar f�r funktionen:
1 �nskat belopp: x
2 kommunal skattesats i proent
3 LAG/MEDEL/HOG - definierar skattesats

Villkor:
Du f�r inte anv�nda siffror ut�ver 1 - 0,01 - 100

Tips:
Ber�kna f�rst ut hur stor l�nen ska vara med
l�n = x/(1-0.01p) d�r p �r summan av procent-
satserna f�r statlig och kommunal skatt.

L�gg sedan till egenavgifterna som ber�knas
i procent av l�nen. L�gg slutligen till momsen
som ber�knas i procent p� totalbelopp (dvs. l�nen
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
	//IF-satser som s�tter den statliga skatteniv�n beroende p� anv�ndarens inmatning i main-funktionen:
	if (niva == LAG)
		skatt_stat = STAT_LAG;
	else if (niva == MEDEL)
		skatt_stat = STAT_MEDEL;
	else (niva == HOG)
		skatt_stat = STAT_HOG;
	//l�n = x/(1-0.01p) d�r p �r summan av procentsatserna f�r statlig och kommunal skatt
	lon = x / (1.0-0.01*(skatt_stat+kommunskatt)); 
	//L�gg sedan till egenavgifterna som ber�knas i procent av l�nen:
	lon += lon * (ARB_AVG/100.0); //Fungerar inte f�r mig om jag inte s�tter 100.0, dock �r detta emot uppgiftens villkor
	//L�gg slutligen till momsensom ber�knas i procent p� totalbelopp (dvs. l�nen plus egenavgifterna):
	return lon + lon * (MOMS/100.0);
}

int main(){
	double belopp, kommunskatt;
	int skatteniva; //F�r val av skatteniv�
	printf("Ange hur mycket du vill ha i belopp efter skatt: ");
	scanf("%lf", &belopp);
	printf("Ange kommunalskatt i procent: ");
	scanf("%lf", &kommunskatt);
	printf("Ange statlig skatteniv� 1: l�g, 2: medel, 3: h�g: ");
	scanf("%d", &skatteniva);
	printf("Du m�ste beg�ra %.2lf kr i pris f�r kunden f�r att f� ut beloppet %.2lf efter skatt!", rakna_pris(belopp, kommunskatt, skatteniva), belopp);
	return 0;
}