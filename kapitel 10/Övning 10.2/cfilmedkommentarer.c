#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
string-funktioner

<ctype.h>
*/

int main(){
	char test_a = 'a';
	char test_space = ' ';
	char *string = "asd asd asd asd asd";
	if (isspace(test_space)){	//kollar om char är ett vittecken (space, tab etc)
		printf("%c är space\n", test_space);
	}
	printf("string är %d lång\n", strlen(string));
	int raknare = 0;
	for(int i=0;i<=strlen(string);i++){
		if (isspace(string[i])){		//räknar mellanslag
			raknare++;
		}
	}
	printf("string innehåller %d space\n", raknare);
	if(string[4] == test_a){			//jämför string[i] mot char
		printf("%c == %c\n", string[4], test_a);
	}
	const char haystack[20] = "EttTvåTRE";
	const char needle[10] = "Två";
	char *ret;

	ret = strstr(haystack, needle);	//returnerar substring efter needle hittad i haystack

	printf("The substring is: %s\n", ret);
	
	char string1[30] = "NY NY NY NY ";
	char string2[30] = "AA AA AA AA ";
	//char måste vara sträng[xx], *sträng funkar inte för sträng[xx]=sträng[xx] annars
	
	
	for(int i =0;string2[i] != '\0';i++){
		if(isspace(string1[i])){
			string2[i-1] = tolower(string1[i-1]);   //NY NY NY NY   ->  AA AA AA AA  -> Ay Ay Ay Ay
		}
	}
	printf("%s\n", string2);
	char string3[30] = "HEJ JAG HETER KALLE!";
	char string4[30] = "HEJ JAG HETER KALLE!";
	for(int i =0;string3[i] != '\0';i++){
		if(!isspace(string3[i])){	//skriver HEJJAGHETERKALLE
				printf("%c", string3[i]);
			}
		if(!isspace(string3[i])){	//gör om till Hej Jag Heter Kalle!
			string4[i+1] = tolower(string3[i+1]);
		}
	}
	printf("\n%s\n", string4);
	
	//TEST text till int
	puts("TEST text till int:");
	char klockslag[10] = "12:30";
	printf("Slå in ett klockslag (xx:xx):");
	//fgets(klockslag,10,stdin);
	char timme_hallare[3],minut_hallare[3];
	int timme, minut;
	strncpy(timme_hallare, klockslag, 2);
	strncpy(minut_hallare, klockslag+3, 2);
	sscanf(timme_hallare, "%d", &timme);
	sscanf(minut_hallare, "%d", &minut);
	printf("\nInt: %d:%d", timme, minut);
	puts("\n----------------------------------");
	//test strstr
	//https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm
	char search_for[10] = "Sökefter";
	char search_in[100] = "AAAAAAA AAaa  Sökefter aaa aAAAAA";
	printf("\n%s", strstr(search_in, search_for));
	strcpy(search_for, "skaejhittas");
	printf("\nJag ska bli null: %s - %s finns ej i search_in", strstr(search_in, search_for),search_for);
}