// Hurtony Tamas ETT V1C 007
// +3614634268

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

  // Tartalyfestes
  
  printf("4. Tartaly Festese\n");

  double magassag, atmero;
  double pi = 3.14159265358979323846;

  printf("Milyen magas?: ");
  scanf("%lf", &magassag);
  printf("Mennyi az atmeroje?: ");
  scanf("%lf", &atmero);
  double eredmeny = 2 * pi * pow(atmero/2,2) + 2 * atmero/2 * pi * magassag;
  printf("%f doboz festek kell.\n", eredmeny/2);

  

  // 5. feladat masodfoku egyenlet
  
  printf("5. Masodfoku egyenlet diszkutalasa\n");
  double a,b,c,x1,x2;

  printf("Add meg sorbba a masodfoku egyutthatoit: ax2 + bx + c, add meg a,b,c-t:");
  scanf("%lf", &a);
  scanf("%lf", &b);
  scanf("%lf", &c);

  x1 = (-b + sqrt(pow(b,2) - 4 * a * c) ) / (2 * a);
  x2 = (-b - sqrt(pow(b,2) - 4 * a * c) ) / (2 * a);

  if(pow(b,2) - (4 * a * c) < 0) {
    printf("Nincs valos megoldasa a fuggvenynek :(( \n");
  }

  if(pow(b,2) - (4 * a * c) > 0) {
    printf("2 megoldasa van a fuggvenynek \n");
  }

  if(pow(b,2) - (4 * a * c) == 0) {
    printf("1 megoldasa van a fuggvenynek \n");
  }
  

  //6 - os feladat szam kiiratas
  
  printf("6-os feladat");
  int i = 1;
  while(i <= 20) {
    printf("%4d", i);
    i++;
  }
  for(int i = 1; i <= 20; i++) {
    printf("%4d", i);
  }
  printf("\n");
  

  // 7-es feladat vonalrajzolos
  printf("7-es feladat\n");
  int meret;
  printf("Mekkora legyen a szakasz: ");
  scanf("%d", &meret);
  printf("+");
  for(int i = 1; i <= meret; i++) {
    printf("-");
  }
  printf("+ \n");

  // 8-as feladat masodfoku megoldasa
  printf("8-as feladat masodfoku megoldasa");
  double a1,b1,c1,x3,x4;

  printf("Add meg sorbba a masodfoku egyutthatoit: ax2 + bx + c, add meg a,b,c-t:");
  scanf("%lf", &a1);
  scanf("%lf", &b1);
  scanf("%lf", &c1);

  x3 = (-b1 + sqrt(pow(b1,2) - 4 * a1 * c1) ) / (2 * a1);
  x4 = (-b1 - sqrt(pow(b1,2) - 4 * a1 * c1) ) / (2 * a1);

  if(pow(b1,2) - (4 * a1 * c1) < 0) {
    printf("Nincs valos megoldasa a fuggvenynek :(( \n");
  }

  printf("%f %f", x3, x4);
  return 0;
}
