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

// kilistazza a rekordok folderben a fajlokat kiveve a "." es ".." 
void fajlkilistaz() {
  DIR *folder;
  struct dirent *entry;
  int files = 0;
  folder = opendir("rekordok");
  if(folder == NULL)
  {
    perror("Nem lehet a foldert olvasni");
    exit(0);
  }
  while( (entry=readdir(folder)) )
  {
    files++;
    if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0) {
      printf("Esemenyek %2d: %s\n",files - 2,entry->d_name);
    }
  }
  printf("Ennyi esemeny talalhato: %d\n",files-2);
  closedir(folder);
}