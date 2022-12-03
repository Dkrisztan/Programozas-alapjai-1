#include <stdio.h>

int main(void) {

  // 3 szamok szorzata
  int n;
  int szorzat = 1;
  for(n = 1; n <= 8; n++) {
    szorzat *= n;
  }
  printf("%d \n", szorzat);

  // 6-os feladat legkisebb
  int tomb[10] = {12,14,2,7,8,0,11,1111,232,69};
  for(int i = 0; i < 10; i++) {
    printf("%d ", tomb[i]);
  }
  printf("\n");

  for(int i = 0; i < 10; i++) {
    printf("[%d]=%d ",i,tomb[i]);
  }

  printf("\n");

  int legkisebb = tomb[0];
  int minhely = 0;
  for(int i = 0; i < 10; i++) {
    printf("[%d]=%d ",i,tomb[i]);
    if(tomb[i] < legkisebb) {
      legkisebb = tomb[i];
      minhely = i;
    }
  }
  printf("\n");
  printf("A legkisebb szam: %d \n", legkisebb);
  printf("A legkisebb szam indexe: %d", minhely);
  printf("\n");

  for(int i = 0; i < 10; i++) {
    if(tomb[i] == legkisebb){
      printf("%d[MIN] ",legkisebb);
    } else {
      printf("%d ", tomb[i]);
    }
  }

  printf("\n");

  char kartomb[10] = {'P', 'i', 't', 'a', 'g', 'o', 'r', 'a', 's', 'z'};
  char seged;
  for(int k = 0; k < 10; k++) {
    for(int i = 0; i < 10; i++) {
      printf("%c ", kartomb[i]);
    }
    printf("\n");
    seged = kartomb[0];
    for(int j = 0; j < 9; j++) {
      kartomb[j] = kartomb[j+1];
    }
    kartomb[9] = seged;
}

    return 0;
}