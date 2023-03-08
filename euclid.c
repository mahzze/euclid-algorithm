#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void swap(int32_t *x, int32_t *y) {
  int32_t *tmp = (int32_t*) malloc(sizeof(int32_t));
  *tmp = *x;
  *x = *y;
  *y = *tmp;
  free(tmp);
}

bool isPrime(int32_t n) {
  for (int i = 2; i <= n/2; ++i) {
    if (n % i == 0) { 
      return true;
    }
  }
  return false;
}

int32_t euclid(int x, int y) {

  if (x < 0){
    x = x*(-1);
  }  

  if (y < 0){
    y = y*(-1);
  } 

  if (y > x) {
    swap(&x, &y);
  }

  if (x == (y+1)) {
    return 1;
  }
  
  while(x > 0 && y > 0) { 
    if (x < y) {
      swap(&x, &y);
    }

   if (x == y) {
     return x;
   }

    x = x - y;
  }
  return x;
}
