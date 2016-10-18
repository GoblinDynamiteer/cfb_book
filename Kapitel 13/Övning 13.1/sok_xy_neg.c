#include <stdio.h>
#include "strings_text_v1.h"
#define N 100

/* Övning 13.1, Sida 316

Skapa ett fält med punkter (se sida 301)
Läs in textfilen 'kurva.txt' efter till fältet.

Sök och leta efter det första punkten vars
båda koordinater är negativa.

Anta att det finns max 100 rader i filen. */

//Från sida 301
struct punkt{
	double x;
	double y;
};

int main(){
	struct punkt p[N];
	FILE *fil = fopen("kurva.txt", "r");
	char rad[N];
	int i = 0;
	while(TTS(rad, N, fil)){
		sscanf(rad, "%lf %lf", &p[i].x, &p[i].y);
		//printf("Punkt  x: %.1f y:%.1f\n", p[i].x, p[i].y);
		if(p[i].x<0 && p[i].y <0){
			printf("Hittade punkt med negativa koordinater på rad %d. x: %.1f y:%.1f", i+1, p[i].x, p[i].y);
			break;
		 }
		i++;
	}
	return 0;
}