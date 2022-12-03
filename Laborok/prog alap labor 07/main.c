#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "debugmalloc.h"

//* 3-as feladat
//! A fuggveny hasznalata: egy sztringet kell atadni a fuggvenynek amelyet lehet elore definialni vagy egybol a fuggveny parameterebe beleirni

char *masolat(char *s) {
  char *masolatoof = (char*) malloc((strlen(s)+1) * sizeof(char));
  int i;
  for(i = 0; s[i] != '\0'; ++i) {
    masolatoof[i] = s[i];
  }
  masolatoof[i] = '\0';
  return masolatoof;
}

//* 4-es feladat
//! A fuggveny hasznalata: Az elso parameter egy dinamikusan foglalt string kell legyen, ezzel ellentetben a masodik parameter lehet egy helyben megadott string is

char *hozzafuz(char *x, char *y) {
  char *atmasol = (char*) malloc((strlen(x) + strlen(y) + 1) * sizeof(char));
  int xhatar;
  int yhatar;
  for(xhatar = 0; x[xhatar] != '\0'; ++xhatar) {
    atmasol[xhatar] = x[xhatar];
  }
  for(yhatar = strlen(x); y[yhatar - strlen(x)] != '\0'; ++yhatar) {
    atmasol[yhatar] = y[yhatar - strlen(x)];
  }
  atmasol[yhatar] = '\0';
  return atmasol;
}

//* 5-os feladat
//! A fuggveny hasznalata: string megadasa illetve egy also es felso korlat megadasa, lehetoleg az also ne legyen kisebb 0-nal illetve a felso ne legyen nagyobb a string hosszanal

char *kivag(char *s, int min, int max) {
  char *atmasol = (char*) malloc((max - min + 1) * sizeof(char));
  if(min < 0) {
    min = 0;
  }
  if(max > strlen(s)) {
    max = strlen(s);
  }
  int i;
  for(i = min; i < max; ++i) {
    atmasol[i - min] = s[i];
  }
  atmasol[max] = '\0';
  return atmasol;
}

//* 6-os feladat
//! A fuggveny hasznalata: parameterkent kap egy stringet es ugyancsak egy felso es also korlatot

char *korbevag(char *s, int min, int max) {
  char *atmasol = (char*) malloc((max - min) * sizeof(char));
  char *atmasol2 = (char*) malloc((strlen(s) - max + min) * sizeof(char));
  if(max > strlen(s)) {
    max = 0;
  }
  if(min < 0) {
    min = strlen(s);
  }
  int i;
  for(i = 0; i < min; ++i) {
    atmasol[i] = s[i];
  }
  atmasol[i] = '\0';
  for(int i = max; s[i] != '\0'; ++i) {
    atmasol2[i - min] = s[i];
  }
  atmasol = strcat(atmasol,atmasol2);
  return atmasol;
}

//* 7-es feladat
//! A fuggveny hasznalata: parameterkent kap ket stringet es egy szamot ahova beszurja a masodik stringet

char *beszur(char *s, int hova, char *m) {
  char *atmasol = (char*) malloc((strlen(s) + strlen(m)) * sizeof(char));
  for(int i = 0; i <= hova; ++i) {
    atmasol[i] = s[i];
  }
  for(int i = 0; m[i]!= '\0'; ++i) {
    atmasol[hova + i + 1] = m[i];
  }
  int i;
  for(i = hova + 1; s[i] != '\0'; ++i) {
    atmasol[i + strlen(m)] = s[i];
  }

  return atmasol;
}

int main(void) {
    //* 2-es feladat
    /* char txt[6] = "hello";
    char *p = (char*)malloc(strlen(txt) * sizeof(char));
    strcpy(p, txt);
    printf("TXT: %s\n", p);
    free(p); */
  char *m;
  m = masolat("alma");
  printf("%s\n",m);
  free(m);

  char *a = "ok";
  char *b = "nemok";
  a = hozzafuz(a,b);
  printf("%s\n",a);
  free(a);

  char *o;
  o = kivag("hellovilagasdasd",3,6);
  printf("%s\n",o);
  free(o);

  char *k;
  k = korbevag("hello, vilag",4,8);
  printf("%s\n",k);
  free(k);

  char *g;
  g = beszur("hello",3,"vilag");
  printf("%s\n",g);
  free(b);
  return 0;
}
