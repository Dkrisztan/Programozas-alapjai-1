#include <stdio.h>

// 1. Fibonacci feladat
// Eszreveheto hogy a program lefutása igencska lassú a nagyságtól függően
int fibonacci(int n) {
  while(n > 1) {
    return fibonacci(n-2) + fibonacci(n-1);  
  }
  if (n == 1){
    return 1;
  }
  if (n == 0){
    return 0;
  }
}

// 2. - es feladat, ugy gondolom, hogy az elso fuggveny gyorsabb a masodiknal mivel nem rekurzivan hivja meg onmagat hanem beepitett fuggvenyt hasznal

void sztringet_kiir_1(char *szoveg) {
    if (szoveg[0] == '\0')
        return;
    putchar(szoveg[0]);
    printf("%s\n", szoveg + 1); 
}
 
void sztringet_kiir_2(char *szoveg) {
    if (szoveg[0] == '\0')
        return;
    putchar(szoveg[0]);
    sztringet_kiir_2(szoveg + 1);
}

// 3. - as feladat tomb elore es hatra iterativ es rekurziv modon

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

// 4. szamrendszer valto

void szvalto(int szam, int valto) {
  if(szam / valto > 0) {
    szvalto(szam / valto, valto);
  }
  printf("%d", szam % valto);
}

// 5. szamjegyenkenti felosztas

void feloszt(int n) {
  if(n / 1000 > 0) { //vizsgaljuk hogy tobb mint 3 szamjegyu-e?
    feloszt(n/1000);
    printf(" %3d", n%1000);
  } else {
    printf("%d", n);
  }
}

int main(void) {

  int n = 40;
  for(int i = 0; i < n; i++) {
    printf("%d\n",fibonacci(i));
  }
  sztringet_kiir_2("alma");
  sztringet_kiir_1("alma");

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
  printf("\n");

  szvalto(17,2);
  printf("\n");

  feloszt(1234567890);
  return 0;
}