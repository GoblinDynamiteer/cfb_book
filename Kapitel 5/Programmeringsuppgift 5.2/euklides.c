/*
Programmeringsuppgift 5.2, Sida 99

Använd pseudokoden på s99 för att skriva ett program: 
ange två positiva heltal n och m. 
Ta reda på den största gemensamma delaren. 

Euklides algoritm i pseudokod, sida 99:
- dividera m med n och beteckna resten av divisionen med r
- om r=0 så är beräkningen klar och divisionen finns i n
- sätt annars m till n och n till r och gå tillbaka till steg 1
*/

#include <stdio.h>

int main(){
	int m, n, r, start_m, start_n;
	printf("Ange ett positivt heltal för n: ");
	scanf("%d", &n);
	printf("Ange ett positivt heltal för m: ");
	scanf("%d", &m);
	start_m = m;
	start_n = n;
	while(1){
		//- dividera m med n och beteckna resten av divisionen med r
		r = m % n;
		//- om r=0 så är beräkningen klar och divisionen finns i n
		if (r == 0){
			printf("Största gemensamma delare för %d & %d är %d", start_m, start_n, n);
			break;
		}
		//- sätt annars m till n och n till r och gå tillbaka till steg 1
		else {
			m = n;
			n = r;
		}
	}
	return 0;
}
