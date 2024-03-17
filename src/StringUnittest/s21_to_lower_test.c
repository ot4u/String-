#include "s21_tests.h"

START_TEST(simple_lower_case) {
  const char s21_str[] = "ABC";
  void* res = s21_to_lower(s21_str);
  ck_assert_str_eq(res, "abc");
  free(res);
}
END_TEST

START_TEST(letters_and_numbers) {
  char s21_str[] = "ABC123ABC";
  void* res = s21_to_lower(s21_str);
  ck_assert_str_eq(res, "abc123abc");
  free(res);
}
END_TEST

START_TEST(lowercase) {
  char s21_str[] = "abc";
  void* res = s21_to_lower(s21_str);
  ck_assert_str_eq(res, "abc");
  free(res);
}
END_TEST

Suite* suite_to_lower() {
  Suite* suite = suite_create("to_lower_suite");
  TCase* tcase_core = tcase_create("to_lower_tc");

  tcase_add_test(tcase_core, simple_lower_case);
  tcase_add_test(tcase_core, letters_and_numbers);
  tcase_add_test(tcase_core, lowercase);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
