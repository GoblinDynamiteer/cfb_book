#include <stdio.h>

/*
L�s in pris f�r �rskort, pris f�r biljett och antal planerade bes�k p� ett �r hos ett gym. 
Ange om det �r l�nsamt att k�pa �rskort.
*/

int main()
{
	//Variabler f�r Pris �rskort, Pris Biljett och antal planerade bes�k f�r ett �r.
	int kort, biljett, besok; 
	printf("Ange pris f�r �rskort: ");
	//Anv�ndarinmatning f�r variabler:
	scanf("%d", &kort);
	printf("Ange pris f�r eng�ngsbiljett: ");
	scanf("%d", &biljett);
	printf("Ange antal planerade bes�k f�r ett �r: ");
	scanf("%d", &besok);
	//J�mf�r om eng�ngsbiljett g�nger antal bes�k �r l�gre �n v�rdet f�r ett �rskort
	if (biljett * besok < kort) {
		printf("Det l�nar sig inte att k�pa ett �rskort!");
	}
	else {
		printf("Det l�nar sig att k�pa ett �rskort!");
	}
	return 0;
}