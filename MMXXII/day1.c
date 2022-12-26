#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define FILE_NAME "data.txt"
#define NMAX 10
#define NR_MAXIS 3

void shift(int arr[], int n, int from) {
  for (int i = n - 2; i >= from; i--) {
    arr[i + 1] = arr[i];
  }
}

void changeMaxis(int maxis[], int n, int newElem) {
  for (int i = 0; i < n; i++) {
    if (maxis[i] < newElem) {
      shift(maxis, n, i);
      maxis[i] = newElem;
      break;
    }
  }
}

int elemsSum(const int arr[], const int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

int main(void) {
  static char s[NMAX + 3];
  FILE *file = fopen(FILE_NAME, "r");
  if (file == NULL) {
    perror("");
    exit(EXIT_FAILURE);
  }

  int currCals = 0, maxis[NR_MAXIS] = {};
  while (fgets(s, NMAX, file)) {
    if (*s != '\n') {
      currCals += strtol(s, NULL, 10);
    } else {
      changeMaxis(maxis, NR_MAXIS, currCals);
      currCals = 0;
    }//*/
  }
  changeMaxis(maxis, NR_MAXIS, currCals);
  printf("answer: %d\n", elemsSum(maxis, NR_MAXIS));
  if (fclose(file) == EOF) {
    perror("");
  }
  return 0;
}
