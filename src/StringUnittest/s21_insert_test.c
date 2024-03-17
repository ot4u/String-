#include "s21_tests.h"

START_TEST(test_insert_basic)  //вставка строки в начало другой строки
{
  const char *src = "world";
  const char *str = "hello ";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "hello world");
  free(result);
}
END_TEST

START_TEST(test_insert_middle)  //Вставка строки в середину другой строки
{
  const char *src = "Good!";
  const char *str = " job";
  size_t start_index = 4;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Good job!");
  free(result);
}
END_TEST

START_TEST(test_insert_end)  //Вставка строки в конец другой строки
{
  const char *src = "Have a ";
  const char *str = "nice day";
  size_t start_index = 7;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Have a nice day");
  free(result);
}
END_TEST

START_TEST(test_insert_null_str)  //Обработка случая, когда вставляемая строка
                                  //равна NULL
{
  const char *src = "world";
  const char *str = "";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, src);
}
END_TEST

Suite *suite_insert(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("insert");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_insert_basic);
  tcase_add_test(tc_core, test_insert_middle);
  tcase_add_test(tc_core, test_insert_end);
  tcase_add_test(tc_core, test_insert_null_str);

  suite_add_tcase(suite, tc_core);

  return suite;
}