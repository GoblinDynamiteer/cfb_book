/* Programmeringsuppgift 8.9, Sida 180

En array �r symmetrisk om den har lika m�nga rader som kolumner
och om det f�r varje i och j g�ller att a[i][j] == a[j][i].
Skriv en funktion med namnet 'symmetrisk' som f�r en tv�dimensionell
array med radl�ngden 4. Funktionen ska vara booleansk och ange 
1 om arrayen �r symmetrisk, annars 0

Skriv sedan ett program d�r anv�ndaren f�r mata in fyra rader med 
fyra heltal i varje, separerat med mellanslag. Dessa ska s�ttas till
en array som har fyra rader och fyra kolumner.

Anv�nd sedan funktionen f�r att se om arrayen �r symmetrisk.

SYMMETRISK ARRAY
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
*/

#include <stdio.h>
#include <stdbool.h>

#define R 4
#define K 4

bool symmetrisk(int a[R][K]);

int main(){
	int a[R][K];
	printf("Sl� in 4x4 heltal: ");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Utskrift f�r test:\n");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	if(symmetrisk(a)){
		printf("Arrayen �r symmetrisk!");
	}
	else{
		printf("Arrayen �r INTE symmetrisk!");
	}
	return 0;
}

bool symmetrisk(int a[R][K]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a[i][j] != a[j][i]){
				return false;
			}
		}
	}
	return true;
}