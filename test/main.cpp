#include <gtest/gtest.h>

extern "C" {
#include "task.h"
}


//* First test
int *FIRST_INPUT_ARR = NULL;
const size_t FIRST_INPUT_ARR_LEN = 0;
const size_t FIRST_CORRECT_RESULT_LEN = 0;

//* Second test
int SECOND_INPUT_ARR[] = {6, 5, 1, 2, 3, 4, 5, 10};
const size_t SECOND_INPUT_ARR_LEN = 8;
const size_t SECOND_CORRECT_RESULT_LEN = 5;

//* Third test
int THIRD_INPUT_ARR[] = {1, 2, 3, 5};
const size_t THIRD_INPUT_ARR_LEN = 4;
const size_t THIRD_CORRECT_RESULT_LEN = 3;

//* Fourth test
int FOURTH_INPUT_ARR[] = {1, 8, 3, 5, 2};
const size_t FOURTH_INPUT_ARR_LEN = 5;
const size_t FOURTH_CORRECT_RESULT_LEN = 0;


TEST(TASK_TEST, HANDLE_EMPTY_ARRAY) {
  int *start = NULL;
  size_t res = find_max_arithmetic_seq(FIRST_INPUT_ARR, FIRST_INPUT_ARR_LEN, &start);

  EXPECT_EQ(res, FIRST_CORRECT_RESULT_LEN);
}

TEST(TASK, HANDLE_ARRAY_WITH_SEQ) {
  int *start = NULL;
  size_t res = find_max_arithmetic_seq(SECOND_INPUT_ARR, SECOND_INPUT_ARR_LEN, &start);

  EXPECT_EQ(res, SECOND_CORRECT_RESULT_LEN);
  EXPECT_EQ(start, SECOND_INPUT_ARR + 2);
}

TEST(TASK, HANDLE_ARRAY_WITH_SMALL_SEQ) {
  int *start = NULL;
  size_t res = find_max_arithmetic_seq(THIRD_INPUT_ARR, THIRD_INPUT_ARR_LEN, &start);

  EXPECT_EQ(res, THIRD_CORRECT_RESULT_LEN);
  EXPECT_EQ(start, THIRD_INPUT_ARR);
}

TEST(TASK, HANDLE_ARRAY_WITH_NO_SEQ) {
  int *start = NULL;
  size_t res = find_max_arithmetic_seq(FOURTH_INPUT_ARR, FOURTH_INPUT_ARR_LEN, &start);

  EXPECT_EQ(res, FOURTH_CORRECT_RESULT_LEN);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
