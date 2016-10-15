#include <stdio.h>
#include "area.h"
#include <math.h>

/*
Programmeringsuppgift 7.3, Sida 147

Konstruera ett funktionsbibliotek 'area' som ber�knar
area f�r cirklar, trianglar och rektanglar

Tips: Placera definition av konstanten PI i area.h s� blir den allm�nt tillg�nglig
(On�digt, M_PI finns i math.h)

Acirkel = pi r^2
Atriangel = b*h/2

*/


//Funktioner f�r att ber�kna area f�r rektangel, cirkel och triangel
double area_rektangel(double bredd, double hojd){
	return bredd*hojd;
}

double area_cirkel(double radie){
	return M_PI*radie*radie;
}

double area_triangel(double bas, double hojd){
	return bas*hojd/2;
}