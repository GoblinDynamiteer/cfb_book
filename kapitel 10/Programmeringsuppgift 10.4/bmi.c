#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "strings_text_v1.h" //eget funktionsbibliotek
#define N 100

/* Programmeringsuppgift 10.4, Sida 237

Man har i en textfil samlat uppgifer om ett antal personer.
För varje peron finns två rader:
	Namn och adress
	Ålder, Längd (cm), Vikt (kg)

För en medicinsk studie av överviktiga personer:
Skriv ett program som läser filen med uppgifter och
skapa en ny textfil med personer med ett BMI över
30. 

Filernas namn ska läsas in från kommandofönstret

Info: 
BMI beräknas med m/h^2   
m = vikt i kg
h = längd i meter

persondata.txt
Hephaestus Cheshire 	7 Lilac Ave. Greenfield, IN 46140
175 75
Zacharie Fujita		2 Gonzales Street Medina, OH 4425631
180 96
Kentigern Kunkel	4th Ave. Chattanooga, TN 37421
159 120
Ladislas Filipovic	77 Delaware Street Manitowoc, WI 54220
201 110
Trey Aartsma		77 Tailwater Ave. Endicott, NY 13760
187 66
Metushelach Michelakis	54 S. Shore St. Middletown, CT 06457
182 87
Kurou Naggia		64 3rd Street Cherry Hill, NJ 08003
165 122
Crispinus Vives		48 West Blue Spring Street King Of Prussia, PA 19406
198 78
Haruka Janson		8734 Smith Store Ave. Toledo, OH 43612
174 66
Zaki Hayward		7124 Wellington Dr. Fort Dodge, IA 50501
160 60
Phrixos Schuchardt	564 Fieldstone Street Pewaukee, WI 53072
187 79
Yosef Causey		23 Tailwater St. Simpsonville, SC 29680
194 63
Anzo Lakatos		7 NE. Pierce Avenue Reno, NV 89523
157 69
Milada North		9497 Branch Dr. Calumet City, IL 60409
185 68
Eudocia Hampson		9209 Argyle Dr. Pittsford, NY 14534
203 132
Quintina Rowntree	800 S. Manchester Court Alliance, OH 44601s
159 54
*/
	
int main(){
	char fil_personer[N], fil_bmi30[N], s[N], person_rad[N];
	int vikt, langd;
	double bmi;
	_Bool BMIover30;
	printf("Ange filnamn med persondata: ");
	radInput(fil_personer, N);
	printf("Ange filnamn för utskrift av personer med högt BMI: ");
	radInput(fil_bmi30, N);
	FILE * infil = fopen(fil_personer, "r");
	FILE * utfil = fopen(fil_bmi30, "w");
	while(textfilTillString(s, N, infil)){
		BMIover30 = 0;
		if(!isdigit(s[0])){
			//printf("While-loop: s[0] = är !siffra | s: %s\n",s);
			strncpy(person_rad, s, strlen(s));
			person_rad[strlen(s)] = '\0';
		}
		else{
			sscanf(s, "%d%d", &langd, &vikt);
			bmi = vikt / pow(((double)langd/100),2);
			printf("%s\nBMI: %lf\n", person_rad, bmi);
			if(bmi>30){
				fprintf(utfil, "%s\n%d %d\n", person_rad, langd, vikt);
			}
		}
	}
}



