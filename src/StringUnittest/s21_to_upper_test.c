#include "s21_tests.h"

START_TEST(simple_upper_case) {
  const char s21_str[] = "abc";
  void* res = s21_to_upper(s21_str);
  ck_assert_str_eq(res, "ABC");
  free(res);
}
END_TEST

START_TEST(letters_and_numbers) {
  char s21_str[] = "abc123abc";
  void* res = s21_to_upper(s21_str);
  ck_assert_str_eq(res, "ABC123ABC");
  free(res);
}
END_TEST

START_TEST(uppercase) {
  char s21_str[] = "ABC";
  void* res = s21_to_upper(s21_str);
  ck_assert_str_eq(res, "ABC");
  free(res);
}
END_TEST

Suite* suite_to_upper() {
  Suite* suite = suite_create("to_upper_suite");
  TCase* tcase_core = tcase_create("to_upper_tc");

  tcase_add_test(tcase_core, simple_upper_case);
  tcase_add_test(tcase_core, letters_and_numbers);
  tcase_add_test(tcase_core, uppercase);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
