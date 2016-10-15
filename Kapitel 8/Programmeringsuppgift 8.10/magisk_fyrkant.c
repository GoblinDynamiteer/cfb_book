#include <stdio.h>

/*
Programmeringsuppgift 8.10, Sida 180

En "magisk fyrkant" är en taluppsättning med lika många rader
som kolumner. Summorna av värdena i varje rad, kolumn, och diagonal
är lika.

Skriv en funktion som avgör om en taluppsättning är en magisk fyrkant eller inte
Funktionen ska vara av booleansk typ och får en tvådimensionell array som
parameter.

Det går att använda samma inmatning för arrayen, som i uppgift 8.9

Ex:
16	9		2		7		=34
6		3		12	13	=34
11	14	5		4		=34
1		8		15	10	=34
=34	=34	=34	=34
*/


#define R 4
#define K 4

//Funktion som returnerar 1 om en tvådimensionell array är en magisk fyrkant, annars 0
_Bool magisk(int a[0][K]){
	int summa = 0, checkR,checkK;
	/*
	Initialt sätts variabeln summa till den totala summan av värdena i första raden, 
	denna summa är det värde summan av alla rader och kolumner i arrayen måste
	vara för att den ska vara en magisk fyrkant.
	*/
	for(int i=0;i<K;i++){
		summa += a[i][0];
	}
	/*
	variablerna checkK och checkR summerar värdena i arrayens rader och kolumner, en rad/kolumn i taget
	och värdet jämförs med summan som sattes ovan.
	*/
	for(int i=0;i<K;i++){
		checkK = 0;
		checkR = 0;
		for(int j=0;j<K;j++){
			checkR += a[i][j];
			checkK += a[i][j];
			
		}
		if((summa != checkR) || (summa !=checkK)){
			return 0; //funktionen avslutas när ett värde har returnerats.
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
	if (magisk(array)){
		puts("Det är en magisk fyrkant!");	
	}
	else	{
		puts("Det är inte en magisk fyrkant!");
	};
	return 0;
}