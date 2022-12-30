#define __STDC_FORMAT_MACROS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#define SIGMA ('Z' - 'A' + 1)
#define MAX_LINE_SIZE 100
#define FILE_NAME "data.txt"

int getPriority(char ch) {
  return islower(ch) ? ch - 'a' + 1 : ch - 'A' + SIGMA + 1;
}

void rtrim(char s[]) {
  int n = strlen(s), i;
  for (i = n - 1; !isalpha(s[i]); i--);
  s[i + 1] = 0;
}

int main(int argc, char **argv) {
  FILE *file = fopen(FILE_NAME, "r");
  if (file == NULL) {
    perror("");
    exit(EXIT_FAILURE);
  }

  uint64_t sum = 0;
  char line[MAX_LINE_SIZE];
  while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
    rtrim(line);
    int n = strlen(line), freq[SIGMA * 2 + 3] = {};
    assert(n % 2 == 0);
    for (int i = 0; i < n / 2; i++) {
      freq[getPriority(line[i])]++;
    }
    
    for (int i = n / 2; i < n; i++) {
      if (freq[getPriority(line[i])]) {
	sum += getPriority(line[i]);
	break;
      }
    }
  }

  printf("answer: %" PRIu64 "\n", sum);
  if (fclose(file) == EOF) {
    perror("");
  }
  return 0;
}
