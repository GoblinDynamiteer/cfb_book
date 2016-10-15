#include <stdio.h>
#include <limits.h> //F�r konstanten INT_MAX

/*
Programmeringsuppgift 6.7, Sida 122

Du har vunnit p� Lotto! Du s�tter in pengarna
p� banken. 

Skriv en funktion som ber�knar hur l�nge pengarna
r�cker om du vill ta ut en viss summa varje �r.

Funktionen ska ha parametrarna: 
vinstumma, r�ntesats och belopp som man vill ta ut

om r�ntan g�r s� att du inte g�r back efter varje �r
(allts� att pengarna r�cker f�r evigt), s� ska funktionen
ge svar INT_MAX, som finns i limits.h

INT_MAX �r en konstant f�r det st�rsta v�rde int kan ha.

*/

//funktion f�r att ber�kna hur l�nge lottovinsten r�cker, med bankr�nta och �rliga uttag
int lotto(double s, double r,  double u){ //s= saldo, r = r�nta, u = uttag
	int ar = 0; //�r
	//OM r�ntan f�r saldot p� kontot (vinstumman vid start) �r st�rre �n eller lika med uttag:
	if (s*r/100 >= u){ 
		//printf("Jag triggade (INT_MAX!)";
		return INT_MAX;
		}
	while(1){
		s = (s + (s*(r/100))) - u;
		//printf("�r: %d - saldo efter r�nta och uttag: %lf\n", ar, saldo);
		ar++;
		if (s<0) //om pengarna har tagit slut p� kontot (negativt v�rde p� saldot) returneras �r
			return ar;
	}
}


int main(){
	double vinstsumma, ranta, uttag;
	printf("Ange vinstumma: ");
	scanf("%lf", &vinstsumma);
	printf("Ange �rsr�nta hos banken: ");
	scanf("%lf", &ranta);
	printf("Ange hur stort uttag du vill g�ra varje �r: ");
	scanf("%lf", &uttag);
	printf("Dina pengar r�cker i %d �r!", lotto(vinstsumma,ranta,uttag));
	return 0;
}