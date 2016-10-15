#include <stdio.h>

/*
Programmeringsuppgift 4.6, sida 91
R�kna 1/1 - 1/2 + 1/3 -....osv 
OBS alternerar mellan plus/minus
serien ska avslutas n�r den sista termen har ett absolutbelopp > 0,00001

fabs(x) i math.h hade gett absolutv�rdet av ett belopp, 
dock kommer vi inte ha n�gra negativa v�rden i denna serie

Jag anv�nder 1.0 vid delningar, annars f�r man heltalsdivision (sant?)
i = 2970
1.0/i = 0.000337 
1/i = 0.000000
*/

int main(){
	double summa = 0;
	for(int i=1;1.0/i>0.00001;i++){
		summa -= (1.0/i); 		// x-=y betyder x=x-y    x+=y betyder x=x+y
		if (1.0/i+1<0.00001) 	//Osnygg l�sning kanske, men s� som jag har gjort for-satsen, s� skulle 'i' kunna bli en f�r mycket i n�sta steg (tror jag), och forsatsen skulle inte bryta
			break; 
		summa += (1.0/++i); 	//prefix ++i inneb�r v�rdet p� i EFTER �kning, i++ ger v�rdet INNAN �kning (s85)
	//printf("\ni: %d summa: %lf", i, summa); //Avkommentera f�r att printa ut v�rde p� i / summa i varje for-varv
	};
	printf("Summan blir: %lf", summa); //Jag vet inte om resultatet (-0.693142) st�mmer, jag har inte orkat g�ra en koll i Excel
	return 0;
}

