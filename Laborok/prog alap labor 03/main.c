#include <stdio.h>
#include <stdbool.h>

// 2. Fuggvenyek alapok

int kob(int n) {
  return n * n * n;
}

int abszolut(int n) {
  if (n < 0) {
    return n * -1;
  } else {
    return n;
  }
}

// 3. Madarnyelv

bool maganhangzo(char c) {
  if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
    return true;
  } else {
    return false;
  }
}

// 4. Osszetett adatszerkezet

typedef struct Datum {
    int ev, ho, nap;
} Datum;
 
typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d) {
  printf("%d.%d.%d\n",d.ev,d.ho,d.nap);
}
 
void versenyzo_kiir(Versenyzo v) {
    printf("Nev: %s Szuletes: %d.%d.%d. Helyezes: %d\n",v.nev,v.szuletes.ev,v.szuletes.ho,v.szuletes.nap,v.helyezes);
}

// 5. Menuvezerelt program

int alapertek(int n) {
  return 1;
}

int hozzaad(int n) {
  return n = n + 1;
}

int fordit(int n) {
  return n * -1;
}

int szorzketto(int n) {
  return n * 2;
}


int main(void) {

  // 1. Tombok frissito
  double tomb[10] = {10,-4,5.6,7.9,999.1,-0.19,-45,34,-66,12};
  int osszegzo = 0;

  for(int i = 0; i < 10; i++) {
    printf("[%d]= %.1lf ", i, tomb[i]);
  }

  int indextomb[10] = {0};
  printf("\n");
  printf("Indexeik: ");
  for(int i = 0; i < 10; i++) {
    if(tomb[i] < 0) {
      osszegzo++;
      indextomb[i] = i;
      printf("[%d]= %.1lf  ",indextomb[i],tomb[i]);
    } 
  }
  printf("\nEbbol %d szam negativ.\n", osszegzo);

  /*

  char c;
  while (scanf("%c", &c) != EOF) {
      if(maganhangzo(c))
        if(c >= 'A'&& c <= 'Z') {
          printf("%cv%c", c, tolower(c));  
        } else {
          printf("%cv%c", c, c);
        }
      else
        printf("%c", c);
  }

  maganhangzo(c);

  */

 Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };
 
  /* 0-s versenyző neve - printf %s */
  printf("%s \n",versenyzok[0].nev);
  /* 2-es versenyző helyezése */
  printf("%d \n",versenyzok[2].helyezes);
  /* 4-es versenyző születési dátumát (írd meg a datum_kiir függvényt!) */
  datum_kiir(versenyzok[4].szuletes);
  /* 1-es versenyző nevének kezdőbetűjét (ne feledd, a sztring karaktertömb) */
  printf("%c \n",versenyzok[1].nev[0]);
  /* az 1-es versenyző dobogós-e? igen/nem, akár ?: operátorral, de egy printf-fel */
  char dobogos[] = "Dobogos";
  char ndobogos[] = "Nem dobogos";
  printf("%s \n",versenyzok[1].helyezes < 4?dobogos:ndobogos);
  /* az 4-es versenyző gyorsabb-e, mint a 3-as versenyző? */
  char gyorsabbnegy[] = "4-es gyorsabb";
  char gyorsabbharom[] = "3-as gyorsabb";
  printf("%s \n",versenyzok[4].helyezes < versenyzok[3].helyezes?gyorsabbnegy:gyorsabbharom);
  /* az 1-es versenyző ugyanabban az évben született-e, mint a 2-es? */
  char ugyanabban[] = "Ugyanabban szulettek";
  char nemugyanabban[] = "Nem ugyanabban szulettek";
  printf("%s \n",versenyzok[1].szuletes.ev == versenyzok[2].helyezes?ugyanabban:nemugyanabban);
  /* egészítsd ki a versenyzo_kiir() függvényt,
  /* aztán írd ki az 1-es versenyző összes adatát */
  versenyzo_kiir(versenyzok[1]);
  /* végül listázd ki az összes versenyzőt sorszámozva, összes adatukkal. */
  for(int i = 0; i < 5; i++) {
    printf("%d. ",i);
    versenyzo_kiir(versenyzok[i]);
  }


  int valasz;
  int a = 1;
  do {
    printf("\n\na = %d \n\n",a);
    printf("0. Alapertek visszaallitasa (a = 1)\n"
         "1. Hozzaad 1-et\n"
         "2. Megforditja az elojelet\n"
         "3. Szorozza 2-vel\n"
         "9. Kilepes\n");
    scanf(" %d", &valasz);
    switch(valasz) {
      case 0:
        a = alapertek(a);
        break;
      case 1:
        a = hozzaad(a);
        break;
      case 2:
        a = fordit(a);
        break;
      case 3:
        a = szorzketto(a);
        break;
      case 9:
        return 1;
        break;
      default:
        printf("Ervenytelen valasz!\n");
        break;
    }

  }while(valasz == 0 || valasz == 1 || valasz == 2 || valasz == 3 || valasz == 9);
  
  return 0;
}