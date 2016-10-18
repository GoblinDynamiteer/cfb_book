#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "strings_text_v1.h"
#include "abonnemang.h"
#define N 100

//Från sida 307+

int main(){
	struct abonnemang b;
	FILE *f = fopen("mobildata.dat", "ab");
	while(1){
		printf("Ange abonnemangets namn: ");
		if (!radInput(b.namn, ABNAMN_LANGD)){
			break;
		}
		printf("Ange data för %s\n", b.namn);
		scanf("%lf%d%lf%lf%lf",
			&b.per_manad,
			&b.fria_min,
			&b.extra_min,
			&b.fria_gb,
			&b.extra_gb);
		clearBuffer();
		fwrite(&b, sizeof(struct abonnemang), 1, f);
	}
	fclose(f);
}