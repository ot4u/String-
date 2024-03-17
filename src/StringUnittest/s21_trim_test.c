#include "s21_tests.h"

START_TEST(trim_null) {
  char s21_src[] = "Hi";
  char* s21_trim_chars = s21_NULL;
  void* res = s21_trim(s21_src, s21_trim_chars);
  ck_assert_pstr_eq(res, s21_NULL);
  free(res);
}
END_TEST

START_TEST(trim_in_end) {
  char s21_src[] = "Hi    ";
  char* s21_trim_chars = " ";
  void* res = s21_trim(s21_src, s21_trim_chars);
  ck_assert_pstr_eq(res, "Hi");
  free(res);
}
END_TEST

START_TEST(trim_in_start_and_end) {
  char s21_src[] = "  Hi    ";
  char* s21_trim_chars = " ";
  void* res = s21_trim(s21_src, s21_trim_chars);
  ck_assert_pstr_eq(res, "Hi");
  free(res);
}
END_TEST

START_TEST(simple_trim) {
  char s21_src[] = "Hello Peer";
  char* s21_trim_chars = "Hel";
  void* res = s21_trim(s21_src, s21_trim_chars);
  ck_assert_pstr_eq(res, "o Peer");
  free(res);
}
END_TEST

START_TEST(trim_all) {
  char s21_src[] = "Adventure";
  char* s21_trim_chars = "Adventure";
  void* res = s21_trim(s21_src, s21_trim_chars);
  ck_assert_pstr_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_in_null) {
  char* s21_src = s21_NULL;
  char* s21_trim_chars = " ";
  void* res = s21_trim(s21_src, s21_trim_chars);
  ck_assert_pstr_eq(res, s21_NULL);
  free(res);
}
END_TEST

START_TEST(non_existent_trim) {
  char s21_src[] = "Hello";
  char* s21_trim_chars = "m";
  void* res = s21_trim(s21_src, s21_trim_chars);
  ck_assert_pstr_eq(res, "Hello");
  free(res);
}
END_TEST

Suite* suite_trim() {
  Suite* suite = suite_create("trim_suite");
  TCase* tcase_core = tcase_create("trim_tc");

  tcase_add_test(tcase_core, trim_null);
  tcase_add_test(tcase_core, trim_in_end);
  tcase_add_test(tcase_core, trim_in_start_and_end);
  tcase_add_test(tcase_core, simple_trim);
  tcase_add_test(tcase_core, trim_all);
  tcase_add_test(tcase_core, trim_in_null);
  tcase_add_test(tcase_core, non_existent_trim);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
