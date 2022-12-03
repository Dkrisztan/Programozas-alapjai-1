#include <stdio.h>

void iterativelore(int t[], int meret) {
  for(int i = 0; i < meret; i++) {
    printf("%3d",t[i]);
  }
}

void iterativhatra(int t[], int meret) {
  for(int i = meret - 1; i != -1; i--) {
    printf("%3d",t[i]);
  }
}

void rekurzivelore(int t[], int meret) {
  if(meret > 0) {
    printf("%3d",t[0]);
    rekurzivelore(t + 1, meret - 1);
  }
}

void rekurzivhatra(int t[], int meret) {
  if(meret > 0) {
    rekurzivhatra(t + 1, meret - 1);
    printf("%3d",t[0]);
  }
}

int main(void) {

  int tomb[5] = {1,2,3,4,5};
  int tombx[10] = {1,2,3,4,5,6,7,8,9,10};

  iterativelore(tomb,5);
  printf("\n");
  iterativelore(tombx,10);
  printf("\n");
  iterativhatra(tomb,5);
  printf("\n");
  iterativhatra(tombx,10);
  printf("\n");
  rekurzivelore(tomb,5);
  printf("\n");
  rekurzivelore(tombx,10);
  printf("\n");
  rekurzivhatra(tomb,5);
  printf("\n");
  rekurzivhatra(tombx,10);

  return 0;
}