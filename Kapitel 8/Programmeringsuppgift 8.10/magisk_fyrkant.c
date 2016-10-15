#include <stdio.h>

/*
Programmeringsuppgift 8.10, Sida 180

En "magisk fyrkant" �r en talupps�ttning med lika m�nga rader
som kolumner. Summorna av v�rdena i varje rad, kolumn, och diagonal
�r lika.

Skriv en funktion som avg�r om en talupps�ttning �r en magisk fyrkant eller inte
Funktionen ska vara av booleansk typ och f�r en tv�dimensionell array som
parameter.

Det g�r att anv�nda samma inmatning f�r arrayen, som i uppgift 8.9

Ex:
16	9		2		7		=34
6		3		12	13	=34
11	14	5		4		=34
1		8		15	10	=34
=34	=34	=34	=34
*/


#define R 4
#define K 4

//Funktion som returnerar 1 om en tv�dimensionell array �r en magisk fyrkant, annars 0
_Bool magisk(int a[0][K]){
	int summa = 0, checkR,checkK;
	/*
	Initialt s�tts variabeln summa till den totala summan av v�rdena i f�rsta raden, 
	denna summa �r det v�rde summan av alla rader och kolumner i arrayen m�ste
	vara f�r att den ska vara en magisk fyrkant.
	*/
	for(int i=0;i<K;i++){
		summa += a[i][0];
	}
	/*
	variablerna checkK och checkR summerar v�rdena i arrayens rader och kolumner, en rad/kolumn i taget
	och v�rdet j�mf�rs med summan som sattes ovan.
	*/
	for(int i=0;i<K;i++){
		checkK = 0;
		checkR = 0;
		for(int j=0;j<K;j++){
			checkR += a[i][j];
			checkK += a[i][j];
			
		}
		if((summa != checkR) || (summa !=checkK)){
			return 0; //funktionen avslutas n�r ett v�rde har returnerats.
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
	if (magisk(array)){
		puts("Det �r en magisk fyrkant!");	
	}
	else	{
		puts("Det �r inte en magisk fyrkant!");
	};
	return 0;
}