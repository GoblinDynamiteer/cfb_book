#include <stdio.h>

/*
�vning 9.5, Sida 201

Skriv ett program som omvandlar ett svenskt datum till amerikanskt format

Amerikanskt: 	MM/DD/����
Svenskt:			����-MM-DD

Ex 
2016-09-13 -> 
09/13/2016

*/

int main(){
	char datum_sv[12];
	char datum_us[12] ="MM/DD/����";
	printf("Ange svenskt datum som ����-MM-DD: ");
	scanf("%s", datum_sv);
	//char-arrays b�rjar ocks� p� 0
	//MM M�nad:
	datum_us[0] = datum_sv[5];
	datum_us[1] = datum_sv[6];
	//DD Dag:
	datum_us[3] = datum_sv[8];
	datum_us[4] = datum_sv[9];
	//���� �r:
	datum_us[6] = datum_sv[0];
	datum_us[7] = datum_sv[1];
	datum_us[8] = datum_sv[2];
	datum_us[9] = datum_sv[3];
	printf("Svensk datum: %s\nAmerikanskt datum: %s", datum_sv, datum_us);
	return 0;
	
	/*
	12 	/ 	45	/789
	MM	/	DD	/����
	����	-	MM	-	DD
	1234		-	67	-	9
	*/
} 