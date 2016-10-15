#include "kolapp.h"

static int sist = 0;
static int betjanad = 0;

int ta_lapp(void){
	return ++sist;
}

int betjana_kund(void){
	if (betjanad == sist)
		return -1;
	else 
		return ++betjanad;
}

//funktion som �terst�ller variablerna sist och betjanad
void init(void){
	sist = 0;
	betjanad = 0;
}

//talar om vilken som var den senaste kunden som senast var betj�nad
int betjanas(void){
	return betjanad; //ger senaste kunden som �r betj�nad
}