#include <stdio.h>

/*
Läs in pris för årskort, pris för biljett och antal planerade besök på ett år hos ett gym. 
Ange om det är lönsamt att köpa årskort.
*/

int main()
{
	//Variabler för Pris Årskort, Pris Biljett och antal planerade besök för ett år.
	int kort, biljett, besok; 
	printf("Ange pris för årskort: ");
	//Användarinmatning för variabler:
	scanf("%d", &kort);
	printf("Ange pris för engångsbiljett: ");
	scanf("%d", &biljett);
	printf("Ange antal planerade besök för ett år: ");
	scanf("%d", &besok);
	//Jämför om engångsbiljett gånger antal besök är lägre än värdet för ett årskort
	if (biljett * besok < kort) {
		printf("Det lönar sig inte att köpa ett årskort!");
	}
	else {
		printf("Det lönar sig att köpa ett årskort!");
	}
	return 0;
}