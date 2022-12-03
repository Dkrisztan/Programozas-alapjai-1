#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 4-es feladat
char *hosszu_sort_olvas() {

  char *s;
  char karakter;
  int szaml = 0;
  s = (char*) malloc(1 + sizeof(char));
  fflush(stdin);
  scanf("%c", &karakter);
  while(karakter != '\n') {
    s = (char*) realloc(s, 1 + sizeof(char));
    s[szaml] = karakter;
    scanf("%c", &karakter);    
    ++szaml;
  }

  return s;
}

int main(void) {
  // 1-es feladat 
  int n;
  printf("Hany szamot? ");
  scanf("%d", &n);

  double *tomb;
  tomb = (double*) malloc(n * sizeof(double));
  
  for(int i = 0; i < n; i++) {
    scanf("%lf", &tomb[i]);
  }

  for(int i = n - 1; i >= 0; i--) {
    printf(" %.1f", tomb[i]);
  }

  free(tomb);  

  printf("\n");

  // 2-es feladat
  double *t;
  double adat;
  int i = 0;
  t = (double*) malloc(1 + sizeof(double));

  scanf("%lf", &adat); 
  while(adat != -1) {
    t = (double*) realloc(t, 1 + sizeof(double));
    t[i] = adat;
    scanf("%lf", &adat);    
    ++i;
  }

  for(int j = i - 1; j >= 0; j--) {
    printf(" %.1f", t[j]);
  }

  free(t);

  printf("\n");

  // 3-as feladat
  char *s;
  char karakter;
  int szaml = 0;
  s = (char*) malloc(1 + sizeof(char));
  fflush(stdin);
  scanf("%c", &karakter);
  while(karakter != '\n') {
    s = (char*) realloc(s, 1 + sizeof(char));
    s[szaml] = karakter;
    scanf("%c", &karakter);    
    ++szaml;
  }

  printf("%s",s);

  free(s);

  printf("\n");
  fflush(stdin);
  
  // 4-es feladat

  char *a = hosszu_sort_olvas();

  printf("%s",a);

  free(a);

  return 0;
}
