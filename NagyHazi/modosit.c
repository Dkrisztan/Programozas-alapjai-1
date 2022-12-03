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

// modositas opciok
void modmenuop() {
  printf("\n");
  printf("  Mit szeretnel modositani?\n");
  printf("  | \u2192 Nev        (1)\n");
  printf("  | \u2192 Helyszin   (2)\n");
  printf("  | \u2192 Megjegyzes (3)\n");
  printf("  | \u2192 Datum      (4)\n");
  printf("  | \u2192 Ido        (5)\n");
  printf("  | \u25B3 Kilepes    (0)\n");
  printf("\n");
  printf("      Add meg a valasztasod: ");
}

// visszaterit egy strukturat, egy fajlbol kiolvasott adatokkal
Rekord fileertek(char *s) {
  Rekord rekord;
  FILE *fp;
  char *seged = (char*) malloc((strlen(s) + 10) * sizeof(char));
  strcpy(seged,"rekordok/");
  strcat(seged,s);
  fp = fopen(seged,"r");
  rekord.nev = (char*) malloc(strlen(s) * 50);
  rekord.helyszin = (char*) malloc(strlen(s) * 50);
  rekord.megjegyzes = (char*) malloc(strlen(s) * 50);
  rekord.datum = (char*) malloc(strlen(s) * 50);

  fscanf(fp,"%[^\n]\n", rekord.nev);
  fscanf(fp,"%[^\n]\n", rekord.helyszin);
  fscanf(fp,"%[^\n]\n", rekord.megjegyzes);
  fscanf(fp,"%[^\n]\n", rekord.datum);
  fscanf(fp,"%d:", &rekord.ora);
  fscanf(fp,"%d", &rekord.perc);

  free(seged);
  fclose(fp);
  return rekord;
}

// modositas menu es fuggvenyek hivasa
void modmenu(char *s) {
  modmenuop();
  int valasztas;
  scanf("%d", &valasztas);
  getchar();
  if(valasztas >= 0 && valasztas <= 5) {
    switch(valasztas) {
      case 0:
        system("cls || clear");
        break;

      case 1:
        printf("Add meg az uj nevet az esemenynek: ");
        Rekord rekord = fileertek(s);

        //! FILE kezeles
        char *nevseged = (char*) malloc((strlen(s) + 10) * sizeof(char));
        strcpy(nevseged,"rekordok/");
        strcat(nevseged,s);

        FILE *fp;
        fp = fopen(nevseged, "w+");

        char *ujnev = dintext();
        
        char *ujnevseged = (char*) malloc((strlen(ujnev) + 10) * sizeof(char));
        strcpy(ujnevseged,"rekordok/");
        strcat(ujnevseged,ujnev);

        fprintf(fp, "%s\n", ujnev);
        fprintf(fp, "%s\n", rekord.helyszin);
        fprintf(fp, "%s\n", rekord.megjegyzes);
        fprintf(fp, "%s\n", rekord.datum);
        fprintf(fp, "%d:%d", rekord.ora, rekord.perc);

        fclose(fp); //! fontos a hierarchia a free-k miatt es az fclose miatt
        RekordFree(rekord);
        free(ujnev);
        rename(nevseged, ujnevseged);
        remove(nevseged);
        free(nevseged);
        free(ujnevseged);
        break;

      case 2:
        printf("Add meg az uj helyszinet az esemenynek: ");
        Rekord rekord1 = fileertek(s);

        //! FILE kezeles
        char *nevseged1 = (char*) malloc((strlen(s) + 10) * sizeof(char));
        strcpy(nevseged1,"rekordok/");
        strcat(nevseged1,s);

        FILE *fp1;
        fp1 = fopen(nevseged1, "w+");

        char *ujhelyszin = dintext();

        fprintf(fp1, "%s\n", rekord1.nev);
        fprintf(fp1, "%s\n", ujhelyszin);
        fprintf(fp1, "%s\n", rekord1.megjegyzes);
        fprintf(fp1, "%s\n", rekord1.datum);
        fprintf(fp1, "%d:%d", rekord1.ora, rekord1.perc);

        fclose(fp1); //! fontos a hierarchia a free-k miatt es az fclose miatt
        RekordFree(rekord1);
        free(ujhelyszin);
        free(nevseged1);
        break;

      case 3:
        printf("Add meg az uj megjegyzeset az esemenynek: ");
        Rekord rekord2 = fileertek(s);

        //! FILE kezeles
        char *nevseged2 = (char*) malloc((strlen(s) + 10) * sizeof(char));
        strcpy(nevseged2,"rekordok/");
        strcat(nevseged2,s);

        FILE *fp2;
        fp2 = fopen(nevseged2, "w+");

        char *ujmegjegyzes = dintext();

        fprintf(fp2, "%s\n", rekord2.nev);
        fprintf(fp2, "%s\n", rekord2.helyszin);
        fprintf(fp2, "%s\n", ujmegjegyzes);
        fprintf(fp2, "%s\n", rekord2.datum);
        fprintf(fp2, "%d:%d", rekord2.ora, rekord2.perc);

        fclose(fp2); //! fontos a hierarchia a free-k miatt es az fclose miatt
        RekordFree(rekord2);
        free(ujmegjegyzes);
        free(nevseged2);
        break;

      case 4:
        printf("Add meg az uj datumat az esemenynek [yyyy-mm-dd] : ");
        Rekord rekord3 = fileertek(s);

        //! FILE kezeles
        char *nevseged3 = (char*) malloc((strlen(s) + 10) * sizeof(char));
        strcpy(nevseged3,"rekordok/");
        strcat(nevseged3,s);

        FILE *fp3;
        fp3 = fopen(nevseged3, "w+");

        char *ujdatum = dintext();

        fprintf(fp3, "%s\n", rekord3.nev);
        fprintf(fp3, "%s\n", rekord3.helyszin);
        fprintf(fp3, "%s\n", rekord3.megjegyzes);
        fprintf(fp3, "%s\n", ujdatum);
        fprintf(fp3, "%d:%d", rekord3.ora, rekord3.perc);

        fclose(fp3); //! fontos a hierarchia a free-k miatt es az fclose miatt
        RekordFree(rekord3);
        free(ujdatum);
        free(nevseged3);
        break;

      case 5:
        printf("Add meg az uj idejet az esemenynek : -al elvalasztva : ");
        Rekord rekord4 = fileertek(s);

        //! FILE kezeles
        char *nevseged4 = (char*) malloc((strlen(s) + 10) * sizeof(char));
        strcpy(nevseged4,"rekordok/");
        strcat(nevseged4,s);

        FILE *fp4;
        fp4 = fopen(nevseged4, "w+");

        int ora, perc;
        scanf("%d:%d", &ora, &perc);

        fprintf(fp4, "%s\n", rekord4.nev);
        fprintf(fp4, "%s\n", rekord4.helyszin);
        fprintf(fp4, "%s\n", rekord4.megjegyzes);
        fprintf(fp4, "%s\n", rekord4.datum);
        fprintf(fp4, "%d:%d", ora, perc);

        fclose(fp4); //! fontos a hierarchia a free-k miatt es az fclose miatt
        RekordFree(rekord4);
        free(nevseged4);
        break;
      
      default:
        printf("Rossz valasztas\n");
    }
  } else {
    printf("Rossz valasztas! Probald ujra!\n");
    sleep(2);
    system("cls || clear");
    modmenu(s);
  }
}