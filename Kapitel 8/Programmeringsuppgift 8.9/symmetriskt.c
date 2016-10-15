#include <stdio.h>

/*
Programmeringsuppgift 8.9, Sida 170

En array �r symmetrisk om den har lika m�nga rader som kolumner
och om det f�r varje i och j g�ller att a[i][j] == a[j][i].
Skriv en funktion med namnet 'symmetrisk' som f�r en tv�dimensionell
array med radl�ngden 4. Funktionen ska vara booleansk och ange 
1 om arrayen �r symmetrisk, annars 0

Skriv sedan ett program d�r anv�ndaren f�r mata in fyra rader med 
fyra heltal i varje, separerat med mellanslag. Dessa ska s�ttas till
en array som har fyra rader och fyra kolumner.

Anv�nd sedan funktionen f�r att se om arrayen �r symmetrisk.
*/
#define R 4
#define K 4

//Funktion som returnerar 1 om en tv�dimensionell array �r symmetrisk, annars 0
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
		//Man kan anv�nda scanf f�r att l�ta anv�ndaren sl� in flera v�rden i samma rad
		scanf("%d %d %d %d", &ett, &tva, &tre, &fyra);
		array[rad][0] = ett;
		array[rad][1] = tva;
		array[rad][2] = tre;
		array[rad][3] = fyra;
		rad++;
	}
	if (symmetrisk(array)){
		puts("Arrayen �r symmetrisk!");	
	}
	else	{
		puts("Arrayen �r inte symmetrisk!");
	};
	return 0;
}
