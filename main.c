#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "./euclid.c"

int32_t getRandom(int32_t min, int32_t max, int limit) {
  int32_t* val = (int32_t*) malloc(sizeof(int32_t)); 
  srandom(limit * 2802 * time(NULL)); //limit * 2802 is here just to make sure that both values will be different, as using srand(time(NULL)) in the same second gives the same results
  *val = floor(random() % (max - min + 1)) + min ;
  return *val;
}

//this code contains my version of an euclid's algorithm. Made just to test my logic.
int main(int argc, char *argv[]) {
  printf("This is the euclidean algorithm, it is used to find the greatest common divisor (GDC) of two numbers.\n");
  printf("There are two modes for this program: Input mode and Random mode.\n");
  printf("Input mode allows you to input the two numbers, while random mode takes two random numbers, within a range that the user may define\n");

  int32_t x;
  int32_t y;
  int32_t range_min;
  int32_t range_lim;
  char mode[4];

  range_min = -250;
  range_lim = 250;

  printf("Select the mode. Press:\n r ) to select random values within the predefined range;\n rmd) to select the minumum value for the range (right now, the value is %d);\n rld) to select the limit value of the range (right now, the value is %d);\n i ) select the two values.\n When you are done, type in \'ext\' to exit the program\n", range_min, range_lim);
  scanf("%3s", mode);

  while (1) {
    if (strcmp("ext", mode) == 0) {
      printf("\nexecution ended");
      break;
    } 

    if (strcmp("rmd", mode) == 0) {
      printf("Type in the new minimum value of the range\n");
      int32_t* newval = (int32_t*) malloc(sizeof(int32_t));
      scanf("%d", newval);
      range_min = *newval;
      printf("Range right now: %d <-> %d\n", range_min, range_lim);
    }

    if (strcmp("rld", mode) == 0) {
      printf("Type in the new maximum value of the range\n");
      int32_t* newval = (int32_t*) malloc(sizeof(int32_t));
      scanf("%d", newval);
      range_lim = *newval;
      free(newval);
      printf("Range right now: %d <-> %d\n", range_min, range_lim);
    }
    
    if (strcmp("r", mode) == 0) {
      printf("Selected random values operation. Range now: %d <-> %d\n", range_min, range_lim);
      x = getRandom(range_min, range_lim, range_min);
      y = getRandom(range_min, range_lim, range_lim);
      printf("Random Values:\nx = %d\ny = %d\n", x, y);
      
      int32_t gdc = euclid(x, y); 
      printf("GDC: %d\n", gdc);  
    }

    if (strcmp("i", mode) == 0) {
      printf("Type in the first value\n");
      scanf("%d", &x);
      printf("Type in the second value\n");
      scanf("%d", &y);
      
      int32_t gdc = euclid(x, y); 
      printf("GDC: %d\n", gdc);  
    }

    printf("\nType in the next operation type. (ext / i / r / rmd / rld)\n");
    scanf("%3s", mode);
  }

  return EXIT_SUCCESS;
}
