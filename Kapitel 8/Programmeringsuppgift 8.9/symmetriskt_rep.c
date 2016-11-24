/* Programmeringsuppgift 8.9, Sida 180

En array är symmetrisk om den har lika många rader som kolumner
och om det för varje i och j gäller att a[i][j] == a[j][i].
Skriv en funktion med namnet 'symmetrisk' som får en tvådimensionell
array med radlängden 4. Funktionen ska vara booleansk och ange 
1 om arrayen är symmetrisk, annars 0

Skriv sedan ett program där användaren får mata in fyra rader med 
fyra heltal i varje, separerat med mellanslag. Dessa ska sättas till
en array som har fyra rader och fyra kolumner.

Använd sedan funktionen för att se om arrayen är symmetrisk.

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
	printf("Slå in 4x4 heltal: ");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Utskrift för test:\n");
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	if(symmetrisk(a)){
		printf("Arrayen är symmetrisk!");
	}
	else{
		printf("Arrayen är INTE symmetrisk!");
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