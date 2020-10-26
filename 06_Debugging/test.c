#include <stdio.h>
#include <stdlib.h>

int main() {
  int *x = malloc(sizeof(int)*5);
  free(x);
  free(x);
  return 0;
}