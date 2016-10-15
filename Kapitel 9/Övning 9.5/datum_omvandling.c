#include <stdio.h>

/*
Övning 9.5, Sida 201

Skriv ett program som omvandlar ett svenskt datum till amerikanskt format

Amerikanskt: 	MM/DD/ÅÅÅÅ
Svenskt:			ÅÅÅÅ-MM-DD

Ex 
2016-09-13 -> 
09/13/2016

*/

int main(){
	char datum_sv[12];
	char datum_us[12] ="MM/DD/ÅÅÅÅ";
	printf("Ange svenskt datum som ÅÅÅÅ-MM-DD: ");
	scanf("%s", datum_sv);
	//char-arrays börjar också på 0
	//MM Månad:
	datum_us[0] = datum_sv[5];
	datum_us[1] = datum_sv[6];
	//DD Dag:
	datum_us[3] = datum_sv[8];
	datum_us[4] = datum_sv[9];
	//ÅÅÅÅ År:
	datum_us[6] = datum_sv[0];
	datum_us[7] = datum_sv[1];
	datum_us[8] = datum_sv[2];
	datum_us[9] = datum_sv[3];
	printf("Svensk datum: %s\nAmerikanskt datum: %s", datum_sv, datum_us);
	return 0;
	
	/*
	12 	/ 	45	/789
	MM	/	DD	/ÅÅÅÅ
	ÅÅÅÅ	-	MM	-	DD
	1234		-	67	-	9
	*/
} 