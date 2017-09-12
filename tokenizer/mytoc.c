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
  
  char *pStr, *copy, *pCopy;
  size_t len;
  int noTokens = 1, tokNum = 0, bytes = 0, index = 0, copyIndex = 0, start = 0;

  /* Copy the *str so as to parse through the copy and not the original */
  for (pStr = str; *pStr; pStr++);
  len = pStr - str + 1;

  copy = pCopy = (char *)malloc(len);
  for (pStr = str; *pStr; pStr++)
    *(pCopy++) = *pStr;

  pCopy = 0;

  /* Traverse through the string and count the no. of tokens */
  while(*copy != '\0') {
    if (*copy == delim) {
      noTokens++;
    }
    copy++;
  }

  noTokens++;
  
  copy = pCopy = (char *)malloc(len);
  for (pStr = str; *pStr; pStr++)
    *(pCopy++) = *pStr;

  pCopy = 0;  

  /* Allocate memory for token vector */
  char **tokenVec = (char **)calloc(noTokens, sizeof(char *));

  /* Parse through the characters for each word */
  while (copy[index] != '\0') {
    if (copy[index] ==  delim) {
      bytes = index - start;
    }
    
    tokenVec[tokNum] = (char *)malloc(bytes + 1);

    /* Copy each character into an array */
    for (copyIndex = start; copyIndex < index; copyIndex++) {
      tokenVec[copyIndex] = &copy[copyIndex]; 
    }
    
    tokenVec[copyIndex] = '\0';
    start = index + 1;
    tokNum++;
    index++;
  }
  
  tokenVec[noTokens] = '\0';

  for (int j = 0; j < noTokens; j++)
    printf("%s\n", tokenVec[j]);
  return tokenVec;

}

