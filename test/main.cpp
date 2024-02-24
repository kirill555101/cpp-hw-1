#include <gtest/gtest.h>

extern "C" {
#include "task.h"
}

TEST(TASK_TEST, HANDLE_EMPTY_ARRAY) {
  const size_t CORRECT_RESULT_LEN = 0;

  int *start = NULL;
  size_t res = find_max_arithmetic_seq(NULL, 0, &start);

  EXPECT_EQ(res, CORRECT_RESULT_LEN);
}

TEST(TASK_TEST, HANDLE_ARRAY_WITH_SEQ) {
  const size_t CORRECT_RESULT_LEN = 5;

  int arr[] = {6, 5, 1, 2, 3, 4, 5};
  size_t len = 9;

  int *start = NULL;
  size_t res = find_max_arithmetic_seq(arr, len, &start);

  EXPECT_EQ(res, CORRECT_RESULT_LEN);
  EXPECT_EQ(start, arr + 2);
}

TEST(TASK_TEST, HANDLE_ARRAY_WITH_SMALL_SEQ) {
  const size_t CORRECT_RESULT_LEN = 3;

  int arr[] = {1, 2, 3, 5};
  size_t len = 3;

  int *start = NULL;
  size_t res = find_max_arithmetic_seq(arr, len, &start);

  EXPECT_EQ(res, CORRECT_RESULT_LEN);
  EXPECT_EQ(start, arr);
}

TEST(TASK_TEST, HANDLE_ARRAY_WITH_NO_SEQ) {
  const size_t CORRECT_RESULT_LEN = 0;

  int arr[] = {1, 8, 3, 5, 2};
  size_t len = 5;

  int *start = NULL;
  size_t res = find_max_arithmetic_seq(arr, len, &start);

  EXPECT_EQ(res, CORRECT_RESULT_LEN);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
