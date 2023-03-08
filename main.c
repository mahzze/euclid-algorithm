#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./euclid.c"

//this code contains my version of an euclid's algorithm. Made just to test my logic.
int main(int argc, char *argv[]) {
  printf("This is the euclidean algorithm, it is used to find the greatest common divisor (GDC) of two numbers.\n");
  printf("There are two modes for this program: Input mode and Random mode.\n");
  printf("THE PROGRAM ONLY ACCEPTS INTEGER VALUES");
  printf("Input mode allows you to input the two numbers, while random mode takes two random numbers, within a range that the user may define\n");

  int32_t x;
  int32_t y;
  int32_t range_min;
  int32_t range_lim;
  char mode[4];

  range_min = 0;
  range_lim = 250;

  printf("Select the mode. Press:\n r ) to select random values within the predefined range;\n rmd) to select the minumum value for the range (right now, the value is %d);\n rld) to select the limit value of the range (right now, the value is %d);\n i ) select the two values.\n When you are done, type in \'ext\' to exit the program\n", range_min, range_lim);
  scanf("%3s", mode);

  while (strcmp("ext", mode) == 23) {
    if (strcmp("rmd", mode)) {
      printf("Type in the new minimum value of the range\n");
      int32_t newval;
      scanf("%d", &newval);
      range_min = newval;
    }
    if (strcmp("rld", mode)) {
      printf("Type in the new maximum value of the range\n");
      int32_t newval;
      scanf("%d", &newval);
      range_min = newval;
    }
    if (strcmp("r", mode)) {
      printf("Type in the new maximum value of the range\n");
      int32_t newval;
      scanf("%d", &newval);
      range_min = newval;
    }
    if (strcmp("i", mode)) {
      printf("Type in the first value\n");
      scanf("%d", &x);
      printf("Type in the second value\n");
      scanf("%d", &y);
      int32_t gdc = euclid(x, y); 
      
      if (gdc == 1) {
        printf("Result: 1. That's because either because both numbers are 1, or\nbecause one of them is a prime number. In this case, the only GDC is one.");
      }
      
      printf("Result: %d", gdc);
    }
  }

  return EXIT_SUCCESS;
}
