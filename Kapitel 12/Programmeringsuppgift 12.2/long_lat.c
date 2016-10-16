#include <stdio.h>

/* Programmeringsuppgift 12.2, Sida 310

Skriv en struct f�r h�llande av positionering
Longitud = v�st/�st 
Latitud  = nord/syd
grader mellan 0 och 180
delar av grader anges i minuter och sekunder - 1 grad = 60min

Exempel:
Landvetter flygplats ligger p� (ca):
latitud 57� 39' 36 N,  longitud 12� 17' 28 �

Skapa tv� structvariabler, en f�r Landvetter, och en egen.

Tips: Anv�nd _Bool f�r att h�lla reda p� v�derstreck */


struct position{
	int lat_grad, lat_min, lat_sek;
	_Bool lat_ns; //N = 0, S = 1
	int long_grad, long_min, long_sek;
	_Bool long_ov; //� = 0, V = 1
	};
	
void skrivPos(struct position *pos);

int main(){
	struct position landvetter_flygplats = {57, 39, 36, 0, 12, 17 ,28 ,0};
	struct position svalbard_flygplats = {78, 14 ,46, 0, 15, 27 ,56, 0};
	printf("Landvetter:\n");
	skrivPos(&landvetter_flygplats);
	printf("\n\nSvalbard:\n");
	skrivPos(&svalbard_flygplats);
}

void skrivPos(struct position *pos){
	printf("Latitud %d� %d' %d ", pos-> lat_grad, pos-> lat_min, pos-> lat_sek);
	if(pos -> lat_ns){
		printf("S, ");
	}
	else {
		printf("N, ");
	}
	printf("Longitud %d� %d' %d ", pos-> long_grad, pos-> long_min, pos-> long_sek);
	if(pos -> long_ov){
		printf("V");
	}
	else {
		printf("�");
	}
}