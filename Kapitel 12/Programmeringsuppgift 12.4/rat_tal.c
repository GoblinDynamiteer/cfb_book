#include <stdio.h>

/* Programmeringsuppgift 12.4, Sida 311

Ett rationellt tal t/n �r ett tal som kan skrivas som kvoten
mellan tv� heltal, en t�ljare och en n�mnare.

ex: 5/9, 1/3, 7/12

Anv�nd programmet i uppgift 5.2 p� sida 99 f�r att
skriva en funktion som f�r en pekare till en struct
'rat_tal'. F�renkla talet s� l�ngd det g�r med minsta
gemensamma delare.

Testa funktionen genom att l�gga till ytterliggare 
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
	//Variabler s�tts till t�ljare och n�mnare fr�n stuct, r=rest
	int t = tal -> taljare,n = tal -> namnare, r;
	while(1){
		//s�tter rest av modulusdivision mellan n�mnare/t�ljare
/* 	Exempel f�rlopp f�r: 28/48
		r = n % t - 20 = 48 % 28
		n (48) s�tts till t(28)
		t (28) s�tts till r(20)
		r = n % t - 8 = 28 % 20
		n (28) s�tts till t(20)
		t (20) s�tts till r(8)
		r = n % t - 4 = 20 % 8
		n (20) s�tts till t(8)
		t (8) s�tts till r(4)
		r = n % t - 0 = 8 % 4 */
		r = n % t; // ex 6%66  --> r = 66%6 = 0
		//printf("r = n %% t - %d = %d %% %d\n", r, n, t);
		if (!r){ //!0 = 1)
			printf("St�rsta gemensamma delare f�r %d & %d �r %d\n", tal -> taljare, tal -> namnare, t);
			tal -> taljare = tal -> taljare / t;
			tal -> namnare = tal -> namnare / t;
			break;
		}
		//printf("n (%d) s�tts till t(%d)\n", n, t);
		n = t;
		//printf("t (%d) s�tts till r(%d)\n", t, r);
		t = r;
		
	}
};

//Programmeringsuppgift 5.2, Sida 99:
/* int main(){
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
} */
