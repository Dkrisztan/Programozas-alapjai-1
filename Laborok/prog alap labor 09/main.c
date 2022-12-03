#include <stdio.h>
#include <stdlib.h>
 
typedef struct BiFa {
  int ertek;
  struct BiFa *bal, *jobb;
} BiFa;
 
BiFa *beszur(BiFa *gyoker, int ertek) {
  if (gyoker == NULL) {
    BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
    uj->ertek = ertek;
    uj->bal = uj->jobb = NULL;
    return uj;
  }
  if (ertek < gyoker->ertek) {        /* balra szur */
    gyoker->bal = beszur(gyoker->bal, ertek);
  }
  else if (ertek > gyoker->ertek) {   /* jobbra szur */
    gyoker->jobb = beszur(gyoker->jobb, ertek);
  }
  else {
    /* mar benne van */
  }
  return gyoker;
}
 
// 2-es feladat
void inorder_bejaras(BiFa *gyoker) {
  if (gyoker == NULL)
     return;
  inorder_bejaras(gyoker->bal);    
  printf("%d ",gyoker->ertek);   
  inorder_bejaras(gyoker->jobb); 
}

void torol(BiFa *gyoker) {
  if (gyoker == NULL)
    return;

  torol(gyoker->bal);    
  torol(gyoker->jobb);      
  free(gyoker);                 
}

// 3-as feladat
int elemszam(BiFa *gyoker) {
  if (gyoker == NULL) return 0;
  return elemszam(gyoker->bal) + elemszam(gyoker->jobb) + 1;                     
}

int elemszam_osszeg(BiFa *gyoker) {
  if (gyoker == NULL) return 0;
  return elemszam_osszeg(gyoker->bal) + elemszam_osszeg(gyoker->jobb) + gyoker->ertek;                     
}

// 4-es feladat
BiFa *keres(BiFa *gyoker, int mit) {
  BiFa *mozgo = gyoker;
  while (mozgo != NULL && mozgo->ertek != mit) {
   if (mit < mozgo->ertek) mozgo = mozgo->bal;
   else mozgo = mozgo->jobb;
  }
  return mozgo;
}

// 5-os feladat
void negal(BiFa *gyoker) {
  if (gyoker == NULL) return 0;
  negal(gyoker->bal);    
  printf("%d ", (-1) * gyoker->ertek);   
  negal(gyoker->jobb);      
}

// 6-os feladat
void tukroz(struct BiFa *gyoker)
{
  if (gyoker == NULL)
    return;
  else
  {
    BiFa *temp;
  
    tukroz(gyoker->bal);
    tukroz(gyoker->jobb);
    temp = gyoker->bal;
    gyoker->bal = gyoker->jobb;
    gyoker->jobb = temp;
  }
}
 
int main(void) {
  int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
  BiFa *gyoker = NULL;
  BiFa *kereses;
  for (int i = 0; minta[i] > 0; i++)
    gyoker = beszur(gyoker, minta[i]);

  inorder_bejaras(gyoker);
  printf("\n%d",elemszam(gyoker));
  printf("\n%d",elemszam_osszeg(gyoker));
  kereses = keres(gyoker,10);
  printf("\n%d\n",kereses->ertek);
  negal(gyoker);
  printf("\n");
  tukroz(gyoker);
  inorder_bejaras(gyoker);
  torol(gyoker);
  

  return 0;
}