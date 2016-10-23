#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FRO "\033[91m" 	//Röd textformatering (31 är mörk)
#define FGR "\033[32m" 	//Grön textformatering
#define FGU "\033[33m" 	//Gul textformatering
#define FBL "\033[94m" 	//Blå textformatering (34 är väldigt mörk)
#define FCY "\033[36m" 	//Cyan (Ungefär ljusblå) textformatering
#define TSU "\033[4m" 		//Understruken textformatering
#define FR "\033[0m" 		//Återställer textformatering
#define L "\n-----------------------------------------------------------------\n" //För utskrift av linjer med printf

//Funktionsdeklarationer
_Bool removeNewLine(char[]);
void clearBuffer(void);
void clearBufferFil(FILE *f);
_Bool radInput(char[], int);
_Bool textfilTillString(char[], int, FILE *f);
_Bool TTS(char *a, int n, FILE *f);