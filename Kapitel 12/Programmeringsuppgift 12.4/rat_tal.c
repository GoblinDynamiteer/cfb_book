#include <stdio.h>

/* Programmeringsuppgift 12.4, Sida 311

Ett rationellt tal t/n är ett tal som kan skrivas som kvoten
mellan två heltal, en täljare och en nämnare.

ex: 5/9, 1/3, 7/12

Använd programmet i uppgift 5.2 på sida 99 för att
skriva en funktion som får en pekare till en struct
'rat_tal'. Förenkla talet så långd det går med minsta
gemensamma delare.

Testa funktionen genom att lägga till ytterliggare 
rationella tal!

ex: 5/9, 1/3, 7/12 (*4) 
-->  20/36, 4/12, 28/48

+ 88/120, 4/55, 7/66, 6/66

*/

//Deklaration av struct
struct rat_tal{
	int taljare, namnare;
};

void minstaGemensammaDelare(struct rat_tal *tal);

int main(){
	struct rat_tal tal[11] = {
		{5,9},
		{1,3},
		{7,12},
		{20,36},
		{4,12}, //12/4 = 3 (minsta gemensamma delare 3)
		{28,48},
		{88,120},
		{4,55},
		{7,66},
		{6,66}, //66/6 = 11 (minsta gemensamma delare 6)
		{100,5} //20/1  = 20 (minsta gemensamma delare 5)
	};
	//sizeof(tal) / sizeof(struct rat_tal) antal medlemmar? i structen
	for (int i=0;i<sizeof(tal) / sizeof(struct rat_tal);i++){
		minstaGemensammaDelare(&tal[i]);
		printf("Delat: %d/%d \n", tal[i].taljare, tal[i].namnare);
	}
	return 0;
}

void minstaGemensammaDelare(struct rat_tal *tal){
	//Variabler sätts till täljare och nämnare från stuct, r=rest
	int t = tal -> taljare,n = tal -> namnare, r;
	while(1){
		//sätter rest av modulusdivision mellan nämnare/täljare
/* 	Exempel förlopp för: 28/48
		r = n % t - 20 = 48 % 28
		n (48) sätts till t(28)
		t (28) sätts till r(20)
		r = n % t - 8 = 28 % 20
		n (28) sätts till t(20)
		t (20) sätts till r(8)
		r = n % t - 4 = 20 % 8
		n (20) sätts till t(8)
		t (8) sätts till r(4)
		r = n % t - 0 = 8 % 4 */
		r = n % t; // ex 6%66  --> r = 66%6 = 0
		//printf("r = n %% t - %d = %d %% %d\n", r, n, t);
		if (!r){ //!0 = 1)
			printf("Största gemensamma delare för %d & %d är %d\n", tal -> taljare, tal -> namnare, t);
			tal -> taljare = tal -> taljare / t;
			tal -> namnare = tal -> namnare / t;
			break;
		}
		//printf("n (%d) sätts till t(%d)\n", n, t);
		n = t;
		//printf("t (%d) sätts till r(%d)\n", t, r);
		t = r;
		
	}
};

//Programmeringsuppgift 5.2, Sida 99:
/* int main(){
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
} */
