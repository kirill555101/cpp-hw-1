#include "menu.h"

#include <stdio.h>
#include <malloc.h>

#include "task.h"

int execute() {
  size_t len;
  printf("Input array length: ");
  scanf("%zu", &len);

  int *arr = malloc(len * sizeof(int));
  if (arr == NULL) {
    fprintf(stderr, "Can't allocate such long memory");
    return 0;
  }

  printf("Input array elements: ");
  for (size_t i = 0; i < len; ++i) {
    scanf("%d", &arr[i]);
  }

  int *start = NULL;
  size_t max_seq_len = find_max_arithmetic_seq(arr, len, &start);

  if (max_seq_len == 0) {
    printf("There is no max sequence!\n");
    free(arr);
    return 0;
  }

  printf("Max sequence: ");
  for (size_t i = 0; i < max_seq_len; ++i)
  {
    printf("%d ", start[i]);
  }
  printf("\n");

  free(arr);

  return 0;
}
