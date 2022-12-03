#include <stdio.h>
#include <stdlib.h>

// 3-as feladat
/*
          l             y                   egyeb
alap   ->l-volt         -                     -
l_volt -> ll_volt      sz+=1,->alap           -> alap
ll_volt   -            sz+=2,->alap           ->alap
*/

// 4-es feladat
int main(void) {
  
  typedef enum LyAllapot {
      alap, l_volt, ll_volt
  } LyAllapot;
  LyAllapot all;
  int c;

  all = alap;
  while ((c = getchar()) != EOF) {
      switch (all) {
        case alap:
          if (c == 'l') all = l_volt;
          break;

        case l_volt:
          switch (c) {
              case 'l': all = ll_volt; break;
              case 'y': putchar("j"); all = alap; break;
              default: all = alap; break;
          }
          break;

        case ll_volt:
          switch (c) {
            case 'l': break;
            case 'y': putchar("jj"); all = alap; break;
            default: all = alap; break;
          }
          break;
      }
  }
  return 0;
}