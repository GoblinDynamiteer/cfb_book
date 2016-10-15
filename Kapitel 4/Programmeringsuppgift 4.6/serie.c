#include <stdio.h>

/*
Programmeringsuppgift 4.6, sida 91
Räkna 1/1 - 1/2 + 1/3 -....osv 
OBS alternerar mellan plus/minus
serien ska avslutas när den sista termen har ett absolutbelopp > 0,00001

fabs(x) i math.h hade gett absolutvärdet av ett belopp, 
dock kommer vi inte ha några negativa värden i denna serie

Jag använder 1.0 vid delningar, annars får man heltalsdivision (sant?)
i = 2970
1.0/i = 0.000337 
1/i = 0.000000
*/

int main(){
	double summa = 0;
	for(int i=1;1.0/i>0.00001;i++){
		summa -= (1.0/i); 		// x-=y betyder x=x-y    x+=y betyder x=x+y
		if (1.0/i+1<0.00001) 	//Osnygg lösning kanske, men så som jag har gjort for-satsen, så skulle 'i' kunna bli en för mycket i nästa steg (tror jag), och forsatsen skulle inte bryta
			break; 
		summa += (1.0/++i); 	//prefix ++i innebär värdet på i EFTER ökning, i++ ger värdet INNAN ökning (s85)
	//printf("\ni: %d summa: %lf", i, summa); //Avkommentera för att printa ut värde på i / summa i varje for-varv
	};
	printf("Summan blir: %lf", summa); //Jag vet inte om resultatet (-0.693142) stämmer, jag har inte orkat göra en koll i Excel
	return 0;
}

