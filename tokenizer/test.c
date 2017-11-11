#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mytoc.h"

#define INBUFLEN 1024

int main (void) {
  char **vector, delimiter = ' ';
  
  while(1) {
    char line[INBUFLEN];
    write(1, "$ ", 2);
    read(0, line, INBUFLEN);
    vector = mytoc(line, delimiter);
    if (exit_loop(vector[0], "exit")) {
      return 0;
    }
    print_vector(vector);
    free_vector(vector);
    for (int i = 0; i < sizeof(line); i++)
      line[i] = 0;
  }
  
  return 0;
}
