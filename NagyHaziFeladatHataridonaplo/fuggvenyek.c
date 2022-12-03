#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"
#include "folder.h"
#include "listaz.h"
#include "modosit.h"
#include "keres.h"

// a program mukodosere jelentektelen, csak design szempontbol fontos
void nevkiir(FILE *fptr) {
  char string[128];
  while(fgets(string,sizeof(string),fptr) != NULL) {
    printf("%s",string);
  }
}

// struktura minden tagjanak felszabaditasa
void RekordFree(Rekord r) {
  free(r.nev);
  free(r.helyszin);
  free(r.megjegyzes);
  free(r.datum);
}

// dinamikus tomb foglalo stringeknek
char *dintext() {
  int db = 0;
  char *sor = (char*) malloc(sizeof(char) * 1);
  sor[0] = '\0';
  char ujkar;
  while (scanf("%c", &ujkar) == 1 && ujkar != '\n') {
    char *ujtomb = (char*) malloc(sizeof(char) * (db+1+1));
    for (int i = 0; i < db; ++i) {
      ujtomb[i] = sor[i];
    }
    free(sor);
    sor = ujtomb;
    ujtomb[db] = ujkar;
    ujtomb[db+1] = '\0';
    ++db;
  }
  return sor;
}

// esemeny parametereit keri be es fajlba irja oket
void esemenyFeltolt() {
  printf("Add meg az esemeny nevet: ");
  char *s;
  s = dintext();

  char *seged;
  seged = (char*) malloc((strlen(s) + 10) * sizeof(char));
  strcpy(seged,"rekordok/");
  Rekord r;
  FILE *fp;
  strcat(seged,s);
  fp  = fopen(seged, "w+");

  //! Nev feltoltese
  r.nev = (char*) malloc((strlen(s) + 1 ) * sizeof(char));
  strcpy(r.nev,s);
  fprintf(fp,"%s\n",r.nev);

  //! Helyszin feltoltese
  printf("Add meg az esemeny helyszinet: ");
  r.helyszin = dintext();
  fprintf(fp,"%s\n",r.helyszin);

  //! Megjegyzes feltoltese
  printf("Adj meg egy megjegyzest: ");
  r.megjegyzes = dintext();
  fprintf(fp,"%s\n",r.megjegyzes);

  //! Datum feltoltese
  printf("Adj meg egy datumot [yyyy-mm-dd] : ");
  r.datum = dintext();
  fprintf(fp,"%s\n",r.datum);

  //! Ido feltoltese
  int ora, perc;
  printf("Add meg a pontos idejet az esemenynek : -al elvalasztva: ");
  scanf("%d:%d",&ora,&perc);
  r.ora = ora;
  r.perc = perc;
  fprintf(fp,"%d:",ora);
  fprintf(fp,"%d",perc);

  fclose(fp);
  RekordFree(r); //* felszabaditjuk a struktura osszes dinamikusan foglalt tombjet

  printf("** Esemeny sikeresen letrehozva! **");
  free(s);
  free(seged);
  sleep(3);
  fflush(stdout);
  system("cls || clear");
  menu();
}

// esemenyt torol nev alapjan
void torol(char *s) {
  char *seged;
  seged = (char*) malloc((strlen(s) + 10) * sizeof(char));
  strcpy(seged,"rekordok/");
  strcat(seged,s);
  if (remove(seged) == 0) {
        printf(" ** Sikeresen toroltuk a rekordot. ** ");
    } else {
        printf(" ** A rekordot nem sikerult torolni. ** ");
    }
  sleep(3);
  free(seged);
}

// a fomenu opcioit irja ki
void menuopciok() {
  char *str = "image.txt";
  FILE *fptr = NULL;
  if((fptr = fopen(str,"r")) == NULL) {
    fprintf(stderr,"Nem sikerult megnyitani %s\n",str);
    exit(0);
  }
  nevkiir(fptr);
  printf("\n");
  fclose(fptr);
  printf("[1] Uj rekord letrehozasa\n");
  printf("[2] Rekord modositasa\n");
  printf("[3] Rekord torlese\n");
  printf("[4] Esemenyek idorendi kilistazasa\n");
  printf("[5] Esemeny keresese\n");
  printf("[6] Osszes esemeny kilistazasa\n");
  printf("[0] Kilepes a programbol\n");
  printf("Add meg a valasztasod egy fenti szammal: ");
}

// a program legfontosabb resze, itt hivodnak meg a fofuggvenyek
void menu() {
  menuopciok();
  int valasztas;
  scanf("%d", &valasztas);
  getchar();
  if(valasztas >= 0 && valasztas <= 6)
  {
    switch(valasztas) {
      case 1:
        //* Uj rekord letrehozasa
        esemenyFeltolt();
        break;

      case 2:
        printf("Add meg a modositando rekord nevet: ");
        char *mod = dintext();
        modmenu(mod);
        free(mod);
        system("cls || clear");
        menu();
        break;

      case 3:
        printf("Add meg a torlendo esemeny nevet: ");
        char *x = dintext();
        
        torol(x);
        free(x);
        system("cls || clear");
        menu();
        break;

      case 4:
      
        printf("Adj meg egy datumat ami alapjan az esemenyeket listazzuk ki [yyyy-mm-dd] : ");
        char *date = dintext();
        kilistaz(date);
        free(date);
        printf("\nNyomd meg az Enter-t a tovabblepeshez");
        if (getchar() == '\n') {
          system("cls || clear");
          menu();
        }
        break;

      case 5:
       
        printf("Add meg a keresendo esemeny nevet: ");
        char *keres = dintext();
        EsemenyKeres(keres);
        free(keres);
        if (getchar() == '\n') {
          system("cls || clear");
          menu();
        }
        break;

      case 6:
    
        while(true) {
          fajlkilistaz();
          printf("Nyomd meg az Enter-t a tovabblepeshez");
          if (getchar() == '\n') {
            break;
          }
        }
        system("cls || clear");
        menu();

      case 0:
        exit(0);

      default:
        printf("Rossz valasztas\n");
    }
  } else {
    printf("Rossz valasztas! Probald ujra!\n");
    sleep(2);
    system("cls || clear");
    menu();
  }
}