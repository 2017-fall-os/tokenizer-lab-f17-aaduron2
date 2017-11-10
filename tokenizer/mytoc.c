/* 
 * Description: This source file parses the string inputted by the user
 *
 * Author: Duron, Andrew
 * Date: September 11, 2017
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

char ** mytoc(char *str, char delim) {
  
  char *pStr, *copy, *pCopy, copyByte;
  size_t len;
  int noTokens = 0, tokNum = 0, bytes = 0, index = 0, start = 0;

  /* Copy the *str so as to parse through the copy and not the original */
  for (pStr = str; *pStr; pStr++);
  len = pStr - str + 1;

  copy = pCopy = (char *)malloc(len);
  for (pStr = str; *pStr; pStr++)
    *(pCopy++) = *pStr;

  pCopy = 0;

  char prevChar;

  /* Traverse through the string and count the no. of tokens */
  while(1) {
    if (copy[index] == delim && prevChar != delim) {
      noTokens++;
    }
    else if (copy[index] == '\0') {
      noTokens++;
      break;
    }
    prevChar = copy[index];
    index++;
  }

  /* Allocate memory for token vector */
  char **tokenVec = (char **)calloc(noTokens, sizeof(char *));

  tokenVec[noTokens-1] = '\0';
  
  copy = pCopy = (char *)malloc(len);
  for (pStr = str; *pStr; pStr++)
    *(pCopy++) = *pStr;

  pCopy = 0;

  prevChar = 0;

  /* Parse through the characters for each word */
  index = 0;
  while (1) {
    int cStart = start;
    if (copy[index] == delim && prevChar != delim) {
      bytes = (index - start) + 1;
      tokenVec[tokNum] = (char *)malloc(bytes);
      for (int i = 0; i < (bytes-1); i++) {
	tokenVec[tokNum][i] = copy[cStart];
	cStart++;
      }
      tokenVec[tokNum][bytes-1] = '\0';
      start = index + 1;
      tokNum++;
    }
    else if (copy[index] == '\0') {
      bytes = (index - start) + 1;
      tokenVec[tokNum] = (char *)malloc(bytes);
      for (int i = 0; i < (bytes-1); i++) {
	tokenVec[tokNum][i] = copy[cStart];
	cStart++;
      }
      tokenVec[tokNum][bytes-1] = '\0';
      break;
    }
    if (copy[index] == delim && prevChar == delim)
      start = index + 1;
    prevChar = copy[index];
    index++;
  }
    
  return tokenVec;
}
