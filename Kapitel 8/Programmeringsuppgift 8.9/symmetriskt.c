#include <stdio.h>

/*
Programmeringsuppgift 8.9, Sida 170

En array är symmetrisk om den har lika många rader som kolumner
och om det för varje i och j gäller att a[i][j] == a[j][i].
Skriv en funktion med namnet 'symmetrisk' som får en tvådimensionell
array med radlängden 4. Funktionen ska vara booleansk och ange 
1 om arrayen är symmetrisk, annars 0

Skriv sedan ett program där användaren får mata in fyra rader med 
fyra heltal i varje, separerat med mellanslag. Dessa ska sättas till
en array som har fyra rader och fyra kolumner.

Använd sedan funktionen för att se om arrayen är symmetrisk.
*/
#define R 4
#define K 4

//Funktion som returnerar 1 om en tvådimensionell array är symmetrisk, annars 0
_Bool symmetrisk(int a[0][K]){
	_Bool symmetriskt = 1;
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			//printf("a[i]: %d a[j]: %d\n");
			if(a[i][j] != a[j][i]){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int array[R][K], ett, tva, tre, fyra, rad=0;
	while(rad<sizeof array/sizeof array[0]){
		printf("Ange fyra heltal med mellanslag mellan varje tal: ");
		//Man kan använda scanf för att låta användaren slå in flera värden i samma rad
		scanf("%d %d %d %d", &ett, &tva, &tre, &fyra);
		array[rad][0] = ett;
		array[rad][1] = tva;
		array[rad][2] = tre;
		array[rad][3] = fyra;
		rad++;
	}
	if (symmetrisk(array)){
		puts("Arrayen är symmetrisk!");	
	}
	else	{
		puts("Arrayen är inte symmetrisk!");
	};
	return 0;
}
