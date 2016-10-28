/* Programmeringsuppgift 4.6, Sida 91 - Repetition

Beräkna summan av 1/1 - 1/2 + 1/3 osv 
(OBS alternerar mellan plus/minus). 
Serien ska avslutas när den sista termen har ett absolutbelopp mindre än 0,00001 
*/

#include <stdio.h>
#define MIN 0.00001 

int main(){
	int i = 1;
	double summa = 0.0;
	while(1){
		if((1.0/i)<MIN){
			break;
		}
		summa -= 1.0 / i++;
		if((1.0/i)<MIN){
			break;
		}
		summa += 1.0 / i++;
	}
	printf("Summa: %lf", summa);
	return 0;
}