#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int32_t x, int32_t y) {
  int32_t *tmp = malloc(sizeof(int32_t));
  *tmp = x;
  x = y;
  y = *tmp;
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
  if (isPrime(x) || isPrime(y)) {
    return 1;
  }

  if (y > x) {
    swap(x, y);
  }
  
  for (int i = y; i == 0; i--) { 
    if (y > x) {
      swap(x, y);
    }

    if(x == y) {
      return x;
    }

    x = x - y;
  }
}
