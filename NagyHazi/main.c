#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"
#include "folder.h"
#include "listaz.h"
#include "modosit.h"
#include "keres.h"

int main(void) {
  while(true) {              /* while ciklusban van,                */
    menu();                  /* azert, hogy a program futtatas utan */
    system("cls || clear");  /* ne lepjen ki magatol                */
  }
  return 0;
}