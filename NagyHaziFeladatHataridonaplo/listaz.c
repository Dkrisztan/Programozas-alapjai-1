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

// Datum alapjan megmondja, hogy a het melyik napja (Hetfo: 1) 
int hetnap(int y, int m, int d) {
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

// reszstringet hoz letre
char *reszsztring(char const *eredeti, int mettol, int meddig) {
  int regihossz = strlen(eredeti);
  if (mettol < 0)
    mettol = 0;
  if (meddig > regihossz)
    meddig = regihossz;
  
  int ujhossz = meddig - mettol;
  char *ujsztring = (char*) malloc((ujhossz + 1) * sizeof(char));
  if (ujsztring == NULL)
    return NULL;
  
  memcpy(ujsztring, eredeti + mettol, ujhossz * sizeof(char));
  ujsztring[ujhossz] = '\0';
  return ujsztring;
}

// ugyanaz a honap
void honap(char *s) {
  Rekord rek;  
  DIR *folder;
  FILE *fp;
  struct dirent *entry;
  int files = 0;
  folder = opendir("rekordok");
  while( (entry=readdir(folder)) )
  {
    files++;
    if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0) {

      char *seged;
      seged = (char*) malloc((strlen(entry->d_name) + 10) * sizeof(char));
      strcpy(seged,"rekordok/");
      strcat(seged,entry->d_name);

      fp = fopen(seged, "r");
      rek.nev = (char*) malloc(strlen(entry->d_name) * 50);
      rek.helyszin = (char*) malloc(strlen(entry->d_name) * 50);
      rek.megjegyzes = (char*) malloc(strlen(entry->d_name) * 50);
      rek.datum = (char*) malloc(strlen(entry->d_name) * 50);

      fscanf(fp,"%s\n", rek.nev);
      fscanf(fp,"%s\n", rek.helyszin);
      fscanf(fp,"%s\n", rek.megjegyzes);
      fscanf(fp,"%s\n", rek.datum);

      char *honap = reszsztring(rek.datum, 0, 7);
      char *ujhonap = reszsztring(s, 0, 7);

      //! Ugyanaz honap logika
      if(strcmp(honap, ujhonap) == 0) {
        printf("%s\n", entry->d_name);
      } else {
        printf(" ");
      }

      fclose(fp);
      free(seged);
      free(honap);
      free(ujhonap);
      RekordFree(rek);
    }
  }
}

// ugyanaz a nap
void nap(char *s) {
  Rekord rek;  
  DIR *folder;
  FILE *fp;
  struct dirent *entry;
  int files = 0;
  folder = opendir("rekordok");
  while( (entry=readdir(folder)) )
  {
    files++;
    if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0) {

      char *seged;
      seged = (char*) malloc((strlen(entry->d_name) + 10) * sizeof(char));
      strcpy(seged,"rekordok/");
      strcat(seged,entry->d_name);

      fp = fopen(seged, "r");
      rek.nev = (char*) malloc(strlen(entry->d_name) * 50);
      rek.helyszin = (char*) malloc(strlen(entry->d_name) * 50);
      rek.megjegyzes = (char*) malloc(strlen(entry->d_name) * 50);
      rek.datum = (char*) malloc(strlen(entry->d_name) * 50);

      fscanf(fp,"%s\n", rek.nev);
      fscanf(fp,"%s\n", rek.helyszin);
      fscanf(fp,"%s\n", rek.megjegyzes);
      fscanf(fp,"%s\n", rek.datum);

      //! Ugyanaz honap logika
      if(strcmp(s, rek.datum) == 0) {
        printf("%s\n", entry->d_name);
      } else {
        printf(" ");
      }

      fclose(fp);
      free(seged);
      RekordFree(rek);
    }
  }
}

// ugyanaz a het
void het(char *s) {
  Rekord rek;  
  DIR *folder;
  FILE *fp;
  struct dirent *entry;
  int files = 0;
  folder = opendir("rekordok");
  while( (entry=readdir(folder)) ) {
    files++;
    if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0) {
    char *seged;
    seged = (char*) malloc((strlen(entry->d_name) + 10) * sizeof(char));
    strcpy(seged,"rekordok/");
    strcat(seged,entry->d_name);
    fp = fopen(seged, "r");
    rek.nev = (char*) malloc(strlen(entry->d_name) * 50);
    rek.helyszin = (char*) malloc(strlen(entry->d_name) * 50);
    rek.megjegyzes = (char*) malloc(strlen(entry->d_name) * 50);
    rek.datum = (char*) malloc(strlen(entry->d_name) * 50);

    fscanf(fp,"%s\n", rek.nev);
    fscanf(fp,"%s\n", rek.helyszin);
    fscanf(fp,"%s\n", rek.megjegyzes);
    fscanf(fp,"%s\n", rek.datum);

    //! regi datum [ev,honap,nap]
    char *regiev = reszsztring(rek.datum, 0, 4);
    char *regihonap = reszsztring(rek.datum, 5, 7);
    char *reginap = reszsztring(rek.datum, 8, 10);

    int intregiev = atoi(regiev);
    int intregihonap = atoi(regihonap);
    int intreginap = atoi(reginap);
    int regidatumnap = hetnap(intregiev, intregihonap, intreginap);


    char *ujev = reszsztring(s, 0, 4);
    char *ujhonap = reszsztring(s, 5, 7);
    char *ujnap = reszsztring(s, 8, 10);

    int intujev = atoi(ujev);
    int intujhonap = atoi(ujhonap);
    int intujnap = atoi(ujnap);
    int ujdatumnap = hetnap(intujev, intujhonap, intujnap);
    

    //! Ugyanaz het logika
    if(intreginap - regidatumnap < intujnap && intujnap < intreginap + 8 - regidatumnap && intujhonap == intregihonap && intujev == intregiev) {
      printf("%s\n", entry->d_name);
    } else if(ujdatumnap == regidatumnap) {
      printf("%s\n", entry->d_name);
    } else {
      printf(" ");
    }

    fclose(fp);
    free(seged);
    free(regiev);
    free(regihonap);
    free(reginap);
    free(ujev);
    free(ujhonap);
    free(ujnap);
    RekordFree(rek);
    }
  }
}

//  kiirja az esemenyeket a talalt datumon, annak a heten, illetve honapjan
void kilistaz(char *s) {
  Rekord rek;  
  DIR *folder;
  FILE *fp;
  struct dirent *entry;
  int files = 0;
  folder = opendir("rekordok");
  if(folder == NULL)
  {
    perror("Nem lehet a foldert olvasni");
    exit(0);
  }

  printf("\nEzek az esemenyek vannak ugyan ezen a napon: \n");
  nap(s);

  printf("\nEzek az esemenyek vannak ugyan ebben a honapban: \n");
  honap(s);

  printf("\nEzek az esemenyek vannak ugyan ezen a heten: \n");
  het(s);

  closedir(folder);
}