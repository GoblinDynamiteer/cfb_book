#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

_Bool removeNewLine(char[]);
void clearBuffer(void);
void clearBufferFil(FILE *f);
_Bool radInput(char[], int);
_Bool textfilTillString(char[], int, FILE *f);