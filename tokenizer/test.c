#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mytoc.h"

#define INBUFLEN 1024

int main (void) {
  char line[INBUFLEN], **vector, delim[1], delimiter = ' ';
  int loop = 1;
  /*
  write(1, "Enter delimiter value: ", 23);
  read(0, delim, 1);

  if (delim[0] == '\0')
    delimiter = ' ';
  else
    delimiter = delim[0];
  */
  while(1) {
    write(1, "$ ", 2);
    read(0, line, INBUFLEN);
    vector = mytoc(line, delimiter);
    if (exit_loop(vector[0])) {
      free_vector(vector);
      return 0;
    }
    print_vector(vector);
    free_vector(vector);
  }
  
  return 0;
}
