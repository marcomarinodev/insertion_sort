#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define DIM 100000

int main(void) {
  double time_spent = 0.0;

  clock_t begin = clock();

  int arr[DIM];

  srand(time(0));

  for (int i = 0; i < DIM; i++) {
    arr[i] = rand();
  }

  for (int i = 0; i < DIM; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j - 1;
    }
    arr[j+1] = key;
  }

  for (int i = 0; i < DIM; i++) {
    printf("ELEMENTO: %d\n", arr[i]);
  }

  clock_t end = clock();

  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time elpased is %f seconds", time_spent);

  return 0;
}
