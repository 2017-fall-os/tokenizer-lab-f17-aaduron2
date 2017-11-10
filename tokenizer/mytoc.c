/* 
 * Description: This source file parses the string inputted by the user
 *
 * Author: Duron, Andrew
 * Date: Novembr 10, 2017
 * Availability: github repository
 *
 *
 * Based on
 * ---------
 * Title: strcopy.c
 * Author: Freudenthal, Eric
 * Availability: github repository
 *
 */

#include <stdio.h>
#include <stdlib.h>

int noTokens;

char ** mytoc(char *str, char delim) {

  char *pStr, *copy, *pCopy;
  size_t len;
  int tokNum = 0, bytes = 0, index = 0, start = 0;

  for (pStr = str; *pStr; pStr++)
    len = pStr - str + 1;

  copy = pCopy = (char *)malloc(len);
  for (pStr = str; *pStr; pStr++)
    *(pCopy++) = *pStr;

  pCopy = 0;

  noTokens = 0;
  
  /* Traverse through the string and count the no. of tokens */
  while(1) {
    if (copy[index] != delim) {
      if (copy[index] == '\0') {
	noTokens++;
	break;
      }
      bytes++;
      index++;
    } else {
      if (bytes != 0) { 
	bytes = 0;
	noTokens++;
      }
      index++;
    }
  }

  /* Allocate memory for token vector */
  char **tokenVec = (char **)calloc(noTokens, sizeof(char*));

  index = 0;
  int cStart = 0;  //Start of string
  
  /* Parse through the characters for each word */
  while (copy[index] != '\0') {
    if (copy[index] != delim) {
      cStart = index;
      while (copy[index] != delim && copy[index] != '\0') {
	index++;
      }
      int length = index - cStart; 
      tokenVec[tokNum] = (char *)malloc(length+1);
      for (int i = 0; i < length; i++) {
	tokenVec[tokNum][i] = str[cStart+i];
      }
      tokNum++;
    }
    else {
      index++;
    }
  }
  
  free(copy);

  return tokenVec;
}

void print_vector(char **vector) {
  int i;
  
  for (i = 0; i < noTokens; i++) {
    printf("%s\n", vector[i]);
    fflush(stdout);
  }
}

void free_vector(char **vector) {
  int i = 0;
  for (int i = 0; i <= noTokens; i++) {
    free(vector[i]);
    i++;
  }
  free(vector);
}

int exit_loop(char *string) {
  if (string[0] == 'e') {
    if (string[1] == 'x') {
      if (string[2] == 'i') {
	if (string[3] == 't') {
	    return 1;
	}
      }
    }
  }
  return 0;
}
