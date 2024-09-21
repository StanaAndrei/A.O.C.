#define __STDC_FORMAT_MACROS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#define SIGMA ('Z' - 'A' + 1)
#define MAX_LINE_SIZE 100
#define FILE_NAME "data.txt"
#define GR_SIZE 3

int getPriority(char ch) {
  return islower(ch) ? ch - 'a' + 1 : ch - 'A' + SIGMA + 1;
}

void rtrim(char s[]) {
  int n = strlen(s), i;
  for (i = n - 1; !isalpha(s[i]); i--);
  s[i + 1] = 0;
}

bool readGroup(FILE *file, char s[GR_SIZE][MAX_LINE_SIZE]) {
  for (int i = 0; i < GR_SIZE; i++) {
    if (!fgets(s[i], MAX_LINE_SIZE, file)) {
      return false;
    }
    rtrim(s[i]);
  }
  return true;
}

char findInCommon(char low, char high, int fr[][SIGMA * 2]) {
  char common = 0;
  for (char ch = low; ch <= high && !common; ch++) {
    const int priority = getPriority(ch);
    bool inAll = true;

    for (int i = 0; i < GR_SIZE; i++) {
      inAll &= (fr[i][priority] > 0);
    }

    if (inAll) {
      common = ch;
      break;
    }
  }
  return common;
}

int main(int argc, char **argv) {
  FILE *file = fopen(FILE_NAME, "r");
  if (file == NULL) {
    perror("");
    exit(EXIT_FAILURE);
  }

  uint64_t sum = 0;
  char s[GR_SIZE][MAX_LINE_SIZE];
  while (readGroup(file, s)) {
    int fr[GR_SIZE][SIGMA * 2] = {};
    for (int i = 0; i < GR_SIZE; i++) {
      for (int j = 0; s[i][j]; j++) {
	fr[i][getPriority(s[i][j])]++;
      }
    }

    char common = 0;
    common = findInCommon('a', 'z', fr);
    if (!common) {
      common = findInCommon('A', 'Z', fr);
    }
    sum += getPriority(common);
  }
  
  printf("answer: %" PRIu64 "\n", sum);
  if (fclose(file) == EOF) {
    perror("");
  }
  return 0;
}
