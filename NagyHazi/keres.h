#ifndef KERES_H
#define KERES_H

typedef struct SzoLista {
  char *szo;
  struct SzoLista *kov;
} SzoLista;

SzoLista *ujegyszavas(char const *szo);
SzoLista *keres(SzoLista *l, char *mit);
void lista_free(SzoLista *lista);
void EsemenyKeres(char *s);

#endif