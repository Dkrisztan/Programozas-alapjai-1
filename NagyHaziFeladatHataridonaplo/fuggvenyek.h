#ifndef FUGGVENYEK_H
#define FUGGVENYEK_H

typedef struct Rekord {
  char *nev;
  char *helyszin; 
  char *megjegyzes; 
  char *datum;  
  int ora, perc;
} Rekord;

void menuopciok();
void menu();
char *dintext();
void esemenyFeltolt();
void RekordFree(Rekord r);
void torol(char *s);
void nevkiir(FILE *fptr);

#endif