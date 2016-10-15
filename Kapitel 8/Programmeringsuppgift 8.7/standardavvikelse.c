#include <stdio.h>
#include <math.h> //för pow(x,y) och sqrt(x)
/*
Programmeringsuppgift 8.7, Sida 179
Skapa en funktion som beräknar standardavikelsen av talen från en array.
Värdena ska ha dataypen double.

Jag använder ett annat sätt än författaren:
https://www.wikiwand.com/sv/Standardavvikelse
x = enstaka tal i arrayen
m = medelvärde av talen i arrayen

Summera alla (x-m)^2
alltså:
(a[0]-m)^2   + (a[1]-m)^2 .... osv

sedan medelvärdet av denna summa (i boken är delas värdet med antal-1)
Till sist dras kvadratroten ur summan.

Tester från
http://www.matteboken.se/lektioner/matte-2/statistik/standardavvikelse

1,4,3,15,72,41,30,27,72,8,42,36,33,46,44
Ska bli 21,9

30,31,33,34,35,34,28,34,33,34,36,35,32,31,32
ska bli 2,1

OBS dessa beräknas inte med x/n-1 utan med x/n
*/

double sav(double a[], int antal){
	double medelvarde = 0, summa = 0;
	for(int i=0;i<antal;i++){
		medelvarde += a[i];
	}
	medelvarde /= antal;
	for(int i=0;i<antal;i++){
		summa += pow((a[i]-medelvarde),2);
	}
	summa /= (antal-1);
	return sqrt(summa);
}

int main(){
	double tal[]={1,4,3,15,72,41,30,27,72,8,42,36,33,46,44};
	printf("Standardavvikelsen är: %.1f", sav(tal, sizeof tal/sizeof tal[0]));
	return 0;
}