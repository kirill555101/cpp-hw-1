#include "task.h"

#define MIN_ARITHMETIC_SEQ_LEN 3

static int is_arithmetic_seq(int *arr, size_t len) {
  if (arr == NULL || len == 0) {
    return 0;
  }

  int res = 1;

  for (size_t i = 1; i < len - 1; ++i) {
    if ((arr[i] - arr[i - 1]) == (arr[i + 1] - arr[i])) {
      continue;
    }

    res = 0;
    break;
  }

  return res;
}

size_t find_max_arithmetic_seq(int *arr, size_t len, int **start) {
  if (arr == NULL || len == 0 || start == NULL) {
    return 0;
  }

  int *max_seq_start = NULL, *curr_seq_start = arr;
  size_t max_seq_len = 0, curr_seq_len = MIN_ARITHMETIC_SEQ_LEN;

  while ((size_t)(curr_seq_start - arr) != len) {
    if (is_arithmetic_seq(curr_seq_start, curr_seq_len) == 1) {
      if (curr_seq_len > max_seq_len) {
        max_seq_start = curr_seq_start;
        max_seq_len = curr_seq_len;
      }

      ++curr_seq_len;
    } else {
      ++curr_seq_start;
      curr_seq_len = MIN_ARITHMETIC_SEQ_LEN;
    }
  }

  *start = max_seq_start;

  return max_seq_len;
}
