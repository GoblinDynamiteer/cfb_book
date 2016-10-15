#include <stdio.h>
#include <string.h>

/*
�vning 9.6, Sida 203

G�r om �vning 9.5, fast anv�nd funktionen strncpy
*/


int main(){
	char datum_sv[12];
	char datum_us[12] ="MM/DD/����";
	printf("Ange svenskt datum som ����-MM-DD: ");
	scanf("%s", datum_sv);
	//char-arrays b�rjar ocks� p� 0
	/*
	
	strncpy anv�nds f�r att kopiera tecken fr�n en char array till en annan
	
	strncpy(x,y,n)
	x �r arrayen man vill kopiera till
	y �r arrayen man vill kopiera fr�n
	n �r antal tecken
	
	f�r att b�rja p� olika element i arrayen kan man skriva exempelvis
	x+1 y+5
	
	*/
	//MM M�nad:
	strncpy(datum_us+0, datum_sv+5, 2);
	//datum_us[0] = datum_sv[5];
	//datum_us[1] = datum_sv[6];
	//DD Dag:
	strncpy(datum_us+3, datum_sv+8, 2);
	//datum_us[3] = datum_sv[8];
	//datum_us[4] = datum_sv[9];
	//���� �r:
	strncpy(datum_us+6, datum_sv+0, 4);
	/*datum_us[6] = datum_sv[0];
	datum_us[7] = datum_sv[1];
	datum_us[8] = datum_sv[2];
	datum_us[9] = datum_sv[3];*/
	printf("Svensk datum: %s\nAmerikanskt datum: %s", datum_sv, datum_us);
	return 0;
}