#include <stdio.h>
#define MOMS 25.0
#define EGEN_AVG 28.97
#define STAT_LAG 0.0
#define STAT_MEDEL 20.0
#define STAT_HOG 20.0
#define LAG 1
#define MEDEL 2
#define HOG 3

double pris(double x, double kommunal, int niva) {
  // beräkna skatteprocenten p
  double p;
    if (niva == LAG)
      p = kommunal + STAT_LAG;
    else if (niva == MEDEL) 
      p = kommunal + STAT_MEDEL;
    else  // antag hög niva
      p = kommunal + STAT_HOG;	  
    // beräkna lonen före skatt
    double lon = x/(1-0.01*p);
    // lägg till egenavgifter   
    double tot = lon + lon*0.01*EGEN_AVG;
    // lägg till moms
    double inklMoms = tot + tot*0.01*MOMS;
    return inklMoms;
  }

  
int main() {
  double kom;
  printf("Kommunalskatt i procent? "); 
  scanf("%lf", &kom);
  int niv;
  printf("Inkomstnivå (1, 2 eller 3)? "); 
  scanf("%d", &niv);
  while (1) {
    printf("Önskat belopp? ");
    double bel;
    if (scanf("%lf" ,&bel) != 1)
      break;
    printf("Pris: %.2f\n" , pris(bel, kom, niv));
  }
}