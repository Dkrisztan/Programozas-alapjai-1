// Hasznalt oldalak: https://www.dcode.fr/brainfuck-language
//                   https://infoc.eet.bme.hu/


#include <stdio.h>

int main(void) {

  char programkod[] = ">++++++++[>++++<-]>.<<[->+<]+>[->++++++++++<<+>]>.[-]>]]+<<<[-[->+<]+>[-<+>>>-[->+<]++>[-<->]<<<]<<<<]++++++++++.+++.[-]<]++++";
  char szalag[32768] = {0};

  char *mutato = szalag;
  char karakter;
  int i = 0;
  char *beolvasott;
  int ciklus = 0;

  while(programkod[i] != 0) {

    karakter = programkod[i];

    if (karakter == '>') {
        ++mutato;
    } else if (karakter == '<') {
        --mutato;
    } else if (karakter == '+') {
        ++*mutato;
    } else if (karakter == '-') {
        --*mutato;
    } else if (karakter == '.' ) {
        printf("%c", *mutato);
    } else if (karakter == ',') {
        *mutato = scanf("%c", &beolvasott);
    } else if (karakter == ']' && *mutato) {
        ciklus = 1;
        while (ciklus > 0) {
            karakter = programkod[--i];
            if (karakter == '[') {
                ciklus--;
            } else if (karakter == ']') {
                ciklus++;
            }
        }
    } else  {
      continue;
    }
    i++;
  }
  
  return 0;
}