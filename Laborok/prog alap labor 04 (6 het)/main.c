#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void kocka(double p, double *t, double *f) {
  double tempterfogat = pow(p, 3);
  double tempfelulet = 6 * pow(p, 2);
  *t = tempterfogat;
  *f = tempfelulet;
}

int kereses(int tomb[], double szam, int meret) {
  for(int i = 0; i < meret; i++) {
    if(tomb[i] == szam) {
      return i;
    } 
  }
  
  printf("Nincs talalat\n");
  return -1;
}

int kereses2(int tomb[], double szam, int meret) {
  int *p;
  for(int i = 0; i < meret; i++) {
    if(tomb[i] == szam) {
      p = &i;
      return p;
    } 
  }
  
  printf("Nincs talalat\n");
  return -1;
}

double *hol_van(double *tomb, int meret, double keresett) {
    for (int idx = 0; idx < meret; ++idx)
        if (tomb[idx] == keresett)
            return &tomb[idx];
    return NULL;
}

void trim(char *str, char *cel) {
    int szam = 0;
 
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            cel[szam++] = str[i];

    str[szam] = '\0';
  }

int main(void) {

  // 3. Kocka – cím szerinti paraméterátadás
  double oldalhossz = 2.7;
  double terfogat = 0;
  double felulet = 0;
  kocka(oldalhossz, &terfogat, &felulet);
  printf("%lf\n%lf\n", terfogat, felulet);

  //4. Tömb és függvény
  int tb[10] = {112,34,6,8,65,2,12,222,99,0};
  printf("%d\n",kereses(tb,0,10));
  printf("%p\n",kereses2(tb,2,10));

  double szamok[5] = { 4.5, 9.2, 7.1, -6.9, 8 };
 
    double *ptr = hol_van(szamok, 5, -6.9);
    if (ptr != NULL) {
        printf("%p helyen, erteke: %f\n", ptr, *ptr); 
        *ptr *= -1;
    } else {
        printf("Nincs benne ilyen.\n");
    }

  //5. Függőlegesen
  char c;
  while(c != 10) { // ez az ENTER gomb ASCII kódja ezelott a while(true)-val csinaltam
    c = getchar();
    printf("\n");
    putchar(c);
  }

  //6. Trimmer
  char tomb[] = "  hello, mizu?   ";
  printf("%s\n",tomb);
  char cel[20];
  trim(tomb,cel);
  printf("%s",cel);

  return 0;
}