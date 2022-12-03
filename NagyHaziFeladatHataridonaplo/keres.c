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

// egyszavas lancolt lista letrehozasa
SzoLista *ujegyszavas(char const *szo) {
  SzoLista *uj;
  uj = (SzoLista*) malloc(sizeof(SzoLista));
  uj->kov = NULL;
  uj->szo = (char*) malloc(sizeof(char)*(strlen(szo)+1));
  strcpy(uj->szo, szo);

  return uj;
}

// listaban valo kereses
SzoLista *keres(SzoLista *l, char *mit) {
  SzoLista *p;
  for (p = l; p != NULL; p = p->kov) {
    if (strcmp(p->szo, mit) == 0) {
      return p;
    }
  }
  return NULL;
}

// lista felszabaditasa
void lista_free(SzoLista *lista) {
  while (lista != NULL) {
    SzoLista *temp = lista->kov;
    free(lista->szo);
    free(lista);
    lista = temp;
  }
}

// Esemeny keresese nev szerint
void EsemenyKeres(char *s) {

  SzoLista *lista, *tal;
  FILE *fp;

  DIR *folder;
  struct dirent *entry;
  folder = opendir("rekordok");
  if(folder == NULL)
  {
    perror("Nem lehet a foldert olvasni");
    exit(0);
  }
  while(entry = readdir(folder)){
    if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0) {
      lista = ujegyszavas(entry->d_name);
      tal = keres(lista, s);
      if (tal != NULL) {
        if(tal != NULL) {
          printf("\n** Van ilyen talalat: %s **\n", tal->szo);

          char seged[] = "rekordok/";
          char nev[1000];
          char helyszin[1000];
          char megjegyzes[1000];
          char datum[20];
          int ora, perc;

          strcat(seged,tal->szo);

          fp = fopen(seged, "r");

          fscanf(fp,"%[^\n]\n", nev);
          fscanf(fp,"%[^\n]\n", helyszin);
          fscanf(fp,"%[^\n]\n", megjegyzes);
          fscanf(fp,"%[^\n]\n", datum);
          fscanf(fp,"%d:", &ora);
          fscanf(fp,"%d", &perc);
          printf("Az esemeny neve: %s\n", nev);
          printf("Az esemeny helyszine: %s\n", helyszin);
          printf("Az esemeny megjegyzese: %s\n", megjegyzes);
          printf("Az esemeny datuma: %s\n", datum);
          printf("Az esemeny pontos ideje: %d:%d\n", ora, perc);
          printf("\nNyomd meg az Enter-t a tovabblepeshez");
          fclose(fp);
        }
      }
      lista_free(lista);
    }
  }
  closedir(folder);
}