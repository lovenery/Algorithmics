#include <stdio.h>

int main() {

  char *ppp = "xdb";

  printf("ppp[0]=%c\n", ppp[0]);
  printf("*ppp=%c\n", *ppp);
  printf("ppp[1]=%c\n", ppp[1]);
  printf("*(ppp+1)=%c\n", *(ppp+1));
  printf("ppp[2]=%c\n", ppp[2]);
  printf("*(ppp+2)=%c\n", *(ppp+2));
  printf("ppp=%s\n", ppp);

  return 0;
}

/*
output:

 */
