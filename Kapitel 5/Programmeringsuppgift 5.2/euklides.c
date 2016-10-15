/*
Programmeringsuppgift 5.2, Sida 99

Anv�nd pseudokoden p� s99 f�r att skriva ett program: 
ange tv� positiva heltal n och m. 
Ta reda p� den st�rsta gemensamma delaren. 

Euklides algoritm i pseudokod, sida 99:
- dividera m med n och beteckna resten av divisionen med r
- om r=0 s� �r ber�kningen klar och divisionen finns i n
- s�tt annars m till n och n till r och g� tillbaka till steg 1
*/

#include <stdio.h>

int main(){
	int m, n, r, start_m, start_n;
	printf("Ange ett positivt heltal f�r n: ");
	scanf("%d", &n);
	printf("Ange ett positivt heltal f�r m: ");
	scanf("%d", &m);
	start_m = m;
	start_n = n;
	while(1){
		//- dividera m med n och beteckna resten av divisionen med r
		r = m % n;
		//- om r=0 s� �r ber�kningen klar och divisionen finns i n
		if (r == 0){
			printf("St�rsta gemensamma delare f�r %d & %d �r %d", start_m, start_n, n);
			break;
		}
		//- s�tt annars m till n och n till r och g� tillbaka till steg 1
		else {
			m = n;
			n = r;
		}
	}
	return 0;
}
