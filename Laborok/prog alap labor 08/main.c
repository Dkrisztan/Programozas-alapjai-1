#include <stdio.h>
#include <stdlib.h>
 
typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;
 

// 3-as feladat: Lista hossza
int listahossz(ListaElem *s) {
  int osszeg = 0;
  ListaElem *mozgo;
  for (mozgo = s; mozgo != NULL; mozgo = mozgo->kov) {
    osszeg += 1;
  }
  return osszeg;
}

// 4-es feladat: Lista felszabaditasa
void listaszabadit(ListaElem *eleje) {
  ListaElem *mozgo;
  mozgo = eleje;
  while (mozgo != NULL) {
    ListaElem *kov = mozgo->kov;
    free(mozgo);
    mozgo = kov;
  }
}

// 5-os feladat: Lista elem beszurasa elore
ListaElem *elore_beszur(ListaElem *eleje, int adat) {
   ListaElem *uj;
   uj = (ListaElem*) malloc(sizeof(ListaElem));
   uj->adat = adat;
   uj->kov = eleje;
   return uj;
}

// 6-os feladat: Lista elem hatulra szurasa
ListaElem *hatulraszur(ListaElem *eleje, int adat) {
  ListaElem *uj;
  uj = (ListaElem*) malloc(sizeof(ListaElem));
  uj->adat = adat;
  uj->kov = NULL;
 
  if (eleje == NULL) {
     eleje = uj;
  } else {
   ListaElem *mozgo = eleje;
   while (mozgo->kov != NULL)
      mozgo = mozgo->kov;
   mozgo->kov = uj;
  }
  return eleje;
}

// 7-es feladat: Kereses a listaban
ListaElem *keres(ListaElem *s, int keres) {
  ListaElem *p;
  for (p = s; p != NULL; p = p->kov) {
    if (p->adat == keres) {
      return p;
    }
  }
  return NULL;
}

/* létrehoz egy listát, benne egy csomó számmal */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2, 15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;
 
    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}
 
int main(void) {
  ListaElem *eleje;
  
  eleje = lista_letrehoz();
  
  // 2-es feladat: Lista kiirasa
  ListaElem *mozgo;
  for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
    printf("%3d", mozgo->adat);
  }

  printf("\n");

  // 3-as feladat: Lista hossza
  printf("%d\n",listahossz(eleje));

  // 4-es feladat: Lista felszabaditasa
  //listaszabadit(eleje);

  // 5-os feladat: Lista eleme beszurasa elore
  eleje = elore_beszur(eleje,20);
  for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
    printf("%3d", mozgo->adat);
  }
  printf("\n");

  // 6-os feladat: Lista hatulra szurasa
  eleje = hatulraszur(eleje,1);
  for (mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov) {
    printf("%3d", mozgo->adat);
  }
  printf("\n");

  // 7-es feladat: Listaban kereses;
  mozgo = keres(eleje, 3);
  if(mozgo != NULL) {
    printf("%d\n", mozgo->adat);
  } else {
    printf("Nincs talalat\n");
  }

  return 0;   
}