#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mytoc.h"

int main (void) {
  char *str = NULL, *exit = "EXIT";
  int loop = 1;

  while(1) {
    printf("$ ");
    scanf("%m[^\n]%*c", &str);
    mytoc(str, ' ');
    if (str) free (str);
  }
  
  return 0;
}
