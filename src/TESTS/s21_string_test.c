
#include "../s21_string.h"

#include <check.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "../s21_sprintf.h"

START_TEST(S21_SPRINTF) {
  char MESSAGE_1[500] = "Hello, World!!";
  char MESSAGE_2[500] = "Hello, World!!";

  char TEST_c = '5';
  int TEST_d = -21475;
  int TEST_i = -50000;
  double TEST_e = -544123.43214;
  double TEST_E = -542314.4231;
  double TEST_f = -50.4324;
  double TEST_g = -1.1111149000;
  double TEST_G = -24324.3243000;
  int TEST_o = -775;
  char TEST_s[20] = "FLAMES";
  int TEST_u = -3857;
  int TEST_x = -9990000;
  int TEST_X = -998;
  void *TEST_p = (void *)0x999;
  int TEST_n_1 = -999;
  int TEST_n_2 = -999;
  sprintf(MESSAGE_1, "|%c|%d|%i|%e|%E|%f|%g|%G|%o|%s|%u|%x|%X|%p|%n|%%|",
          TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2, "|%c|%d|%i|%e|%E|%f|%g|%G|%o|%s|%u|%x|%X|%p|%n|%%|",
              TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_2);

  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #1.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #1.2 - FAILED!");

  sprintf(MESSAGE_1,
          "%-15c|%-15d|%-15i|%-15e|%-15E|%-15f|%-15g|%-15G|%-15o%-15s%-15u%-"
          "15x%-15X%-30p",
          TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p);
  s21_sprintf(MESSAGE_2,
              "%-15c|%-15d|%-15i|%-15e|%-15E|%-15f|%-15g|%-15G|%-15o%-15s%-15u%"
              "-15x%-15X%-30p",
              TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #2.1 - FAILED!");

  sprintf(MESSAGE_1, "|%c|%+d|%+i|%+e|%+E|%+f|%+g|%+G|%o|%s|%u|%x|%X|%p|%n|%%|",
          TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2,
              "|%c|%+d|%+i|%+e|%+E|%+f|%+g|%+G|%o|%s|%u|%x|%X|%p|%n|%%|",
              TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_2);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #3.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #3.2 - FAILED!");

  sprintf(MESSAGE_1, "|%c|% d|% i|% e|% E|% f|% g|% G|%o|%s|%u|%x|%X|%p|%n|%%|",
          TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2,
              "|%c|% d|% i|% e|% E|% f|% g|% G|%o|%s|%u|%x|%X|%p|%n|%%|",
              TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_2);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #4.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #4.2 - FAILED!");

  sprintf(MESSAGE_1,
          "|%c|%d|%i|%#e|%#E|%#f|%#g|%#G|%#o|%s|%u|%#x|%#X|%p|%n|%%|", TEST_c,
          TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G, TEST_o,
          TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2,
              "|%c|%d|%i|%#e|%#E|%#f|%#g|%#G|%#o|%s|%u|%#x|%#X|%p|%n|%%|",
              TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_2);

  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #5.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #5.2 - FAILED!");

  sprintf(MESSAGE_1,
          "|%c|%015d|%015i|%015e|%015E|%015f|%015g|%015G|%015o|%s|%015u|%015x|%"
          "015X|%p|",
          TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p);
  s21_sprintf(MESSAGE_2,
              "|%c|%015d|%015i|%015e|%015E|%015f|%015g|%015G|%015o|%s|%015u|%"
              "015x|%015X|%p|",
              TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #6.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #6.2 - FAILED!");

  int TEST_width = 15;
  sprintf(MESSAGE_1,
          "|%15c|%15d|%15i|%15e|%15E|%15f|%15g|%15G|%15o|%15s|%15u|%15x|%15X|%"
          "30p|%n|%%|",
          TEST_c, INT_MIN, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2,
              "|%15c|%15d|%15i|%*e|%15E|%15f|%15g|%15G|%15o|%15s|%15u|%15x|%"
              "15X|%30p|%n|%%|",
              TEST_c, INT_MIN, TEST_i, TEST_width, TEST_e, TEST_E, TEST_f,
              TEST_g, TEST_G, TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p,
              &TEST_n_2);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #7.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #7.2 - FAILED!");

  int TEST_accuracy = 2;
  sprintf(MESSAGE_1,
          "|%c|%.2d|%.2i|%.2e|%.2E|%.2f|%.2g|%.2G|%.2o|%.2s|%.2u|%.2x|%.2X|%p|%"
          "n|%%|",
          TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2,
              "|%c|%.2d|%.2i|%.*e|%.2E|%.2f|%.2g|%.2G|%.2o|%.2s|%.2u|%.2x|%.2X|"
              "%p|%n|%%|",
              TEST_c, TEST_d, TEST_i, TEST_accuracy, TEST_e, TEST_E, TEST_f,
              TEST_g, TEST_G, TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p,
              &TEST_n_2);

  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #8.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #8.2 - FAILED!");

  sprintf(MESSAGE_1,
          "|%c|%.15d|%.15i|%.15e|%.15E|%.15f|%.15g|%.15G|%.15o|%.15s|%.15u|%."
          "15x|%.15X",
          TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X);
  s21_sprintf(MESSAGE_2,
              "|%c|%.15d|%.15i|%.15e|%.15E|%.15f|%.15g|%.15G|%.15o|%.15s|%.15u|"
              "%.15x|%.15X",
              TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #9.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #9.2 - FAILED!");

  sprintf(MESSAGE_1,
          "|%c|%.d|%.i|%.e|%.E|%.f|%.g|%.G|%.o|%.s|%.u|%.x|%.X|%p|%n|%%|",
          TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2,
              "|%c|%.d|%.i|%.e|%.E|%.f|%.g|%.G|%.o|%.s|%.u|%.x|%.X|%p|%n|%%|",
              TEST_c, TEST_d, TEST_i, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_2);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #10.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #10.2 - FAILED!");

  short int TEST_ii = -10000;
  short int TEST_oo = -775;
  short int TEST_uu = -3857;
  short int TEST_xx = -10900;
  short int TEST_XX = -998;
  sprintf(MESSAGE_1, "|%c|%hd|%hi|%e|%E|%f|%g|%G|%ho|%s|%hu|%hx|%hX|%p|%n|%%|",
          TEST_c, SHRT_MIN, TEST_ii, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_oo, TEST_s, TEST_uu, TEST_xx, TEST_XX, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2,
              "|%c|%hd|%hi|%e|%E|%f|%g|%G|%ho|%s|%hu|%hx|%hX|%p|%n|%%|", TEST_c,
              SHRT_MIN, TEST_ii, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
              TEST_oo, TEST_s, TEST_uu, TEST_xx, TEST_XX, TEST_p, &TEST_n_2);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #11.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #11.2 - FAILED!");

  long int TEST_iii = -50000;
  long int TEST_ooo = -775;
  long int TEST_uuu = -3857;
  long int TEST_xxx = -9990000;
  long int TEST_XXX = -998;
  sprintf(MESSAGE_1, "|%c|%ld|%li|%e|%E|%f|%g|%G|%lo|%s|%lu|%lx|%lX|%p|%n|%%|",
          TEST_c, LONG_MIN, TEST_iii, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
          TEST_ooo, TEST_s, TEST_uuu, TEST_xxx, TEST_XXX, TEST_p, &TEST_n_1);
  s21_sprintf(
      MESSAGE_2, "|%c|%ld|%li|%e|%E|%f|%g|%G|%lo|%s|%lu|%lx|%lX|%p|%n|%%|",
      TEST_c, LONG_MIN, TEST_iii, TEST_e, TEST_E, TEST_f, TEST_g, TEST_G,
      TEST_ooo, TEST_s, TEST_uuu, TEST_xxx, TEST_XXX, TEST_p, &TEST_n_2);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #12.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #12.2 - FAILED!");

  long double TEST_ee = -544123.43214;
  long double TEST_EE = -542314.4231;
  long double TEST_ff = -50.4324;
  long double TEST_gg = -134323.32400;
  long double TEST_GG = -24324.3243000;
  sprintf(MESSAGE_1, "|%c|%d|%i|%Le|%LE|%Lf|%Lg|%LG|%o|%s|%u|%x|%X|%p|%n|%%|",
          TEST_c, TEST_d, TEST_i, TEST_ee, TEST_EE, TEST_ff, TEST_gg, TEST_GG,
          TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_1);
  s21_sprintf(MESSAGE_2,
              "|%c|%d|%i|%Le|%LE|%Lf|%Lg|%LG|%o|%s|%u|%x|%X|%p|%n|%%|", TEST_c,
              TEST_d, TEST_i, TEST_ee, TEST_EE, TEST_ff, TEST_gg, TEST_GG,
              TEST_o, TEST_s, TEST_u, TEST_x, TEST_X, TEST_p, &TEST_n_2);
  ck_assert_msg(strcmp(MESSAGE_1, MESSAGE_2) == 0, "TEST #13.1 - FAILED!");
  ck_assert_msg(TEST_n_1 == TEST_n_2, "TEST #13.2 - FAILED!");
}
END_TEST

START_TEST(test_memchr)  //проверяет работу функции для символа, который
                         //присутствует в строке
{
  const char str[] = "Example string";
  int c = 'p';
  size_t n = sizeof(str);

  const void *result_my = s21_memchr(str, c, n);
  const void *result_std = memchr(str, c, n);

  ck_assert_msg(result_my == result_std, "Expected: %p, Got: %p", result_std,
                result_my);
}
END_TEST

START_TEST(test_memchr_null)  //проверяет работу функции, когда искомый символ
                              //отсутствует в строке
{
  const char str[] = "Example string";
  int c = 'z';
  size_t n = sizeof(str);

  const void *result_my = s21_memchr(str, c, n);
  const void *result_std = memchr(str, c, n);

  ck_assert_msg(result_my == result_std, "Expected: %p, Got: %p", result_std,
                result_my);
}
END_TEST

START_TEST(test_memchr_first_occurrence)  //проверяет, что функция возвращает
                                          //правильный указатель для первого
                                          //вхождения символа в строку
{
  const char str[] = "Example string";
  int c = 's';
  size_t n = sizeof(str);

  const void *result_my = s21_memchr(str, c, n);
  const void *result_std = memchr(str, c, n);

  ck_assert_msg(result_my == result_std, "Expected: %p, Got: %p", result_std,
                result_my);
}

END_TEST

START_TEST(test_memchr_last_occurrence)  //проверяет, что функция возвращает
                                         //правильный указатель для последнего
                                         //вхождения символа в строку
{
  const char str[] = "Example string";
  int c = 'g';
  size_t n = sizeof(str);

  const void *result_my = s21_memchr(str, c, n);
  const void *result_std = memchr(str, c, n);

  ck_assert_msg(result_my == result_std, "Expected: %p, Got: %p", result_std,
                result_my);
}

END_TEST

START_TEST(test_memchr_single_char)  //проверяет, что функция правильно находит
                                     //единственный символ в строке
{
  const char str[] = "a";
  int c = 'a';
  size_t n = sizeof(str);

  const void *result_my = s21_memchr(str, c, n);
  const void *result_std = memchr(str, c, n);

  ck_assert_msg(result_my == result_std, "Expected: %p, Got: %p", result_std,
                result_my);
}
END_TEST

START_TEST(
    test_memchr_multiple_chars)  //проверяет, что функция правильно находит
                                 //первое вхождение символа в строке, когда
                                 //символ встречается несколько раз
{
  const char str[] = "aabbaabb";
  int c = 'b';
  size_t n = sizeof(str);

  const void *result_my = s21_memchr(str, c, n);
  const void *result_std = memchr(str, c, n);

  ck_assert_msg(result_my == result_std, "Expected: %p, Got: %p", result_std,
                result_my);
}
END_TEST

START_TEST(
    test_memchr_not_in_string)  //проверяет, что функция возвращает NULL, когда
                                //искомый символ отсутствует в строке
{
  const char str[] = "Example string";
  int c = 'x';
  size_t n = sizeof(str);

  const void *result_my = s21_memchr(str, c, n);
  const void *result_std = memchr(str, c, n);

  ck_assert_msg(result_my == result_std, "Expected: %p, Got: %p", result_std,
                result_my);
}
END_TEST

START_TEST(
    test_memchr_empty_string)  //проверяет работу функции с пустой строкой
{
  const char str[] = "";
  int c = 'a';
  size_t n = sizeof(str);

  const void *result_my = s21_memchr(str, c, n);
  const void *result_std = memchr(str, c, n);

  ck_assert_msg(result_my == result_std, "Expected: %p, Got: %p", result_std,
                result_my);
}
END_TEST

START_TEST(test_memcmp_equal_strings)  //сравнивает равные строки
{
  const char str1[] = "Hello";
  const char str2[] = "Hello";
  size_t n = 5;

  int result_my = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);

  ck_assert_msg(result_my == result_std, "Expected: %d, Got: %d", result_std,
                result_my);
}
END_TEST

START_TEST(test_memcmp_unequal_strings)  //сравнивает неравные строки
{
  const char str1[] = "Hello";
  const char str2[] = "World";
  size_t n = 5;

  int result_my = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);

  ck_assert_msg(result_my == result_std, "Expected: %d, Got: %d", result_std,
                result_my);
}
END_TEST

START_TEST(test_memcmp_partial_match)  //сравнивает первые 7 символов
{
  const char str1[] = "Hello, world!";
  const char str2[] = "Hello, friends!";
  size_t n = 7;

  int result_my = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);

  ck_assert_msg(result_my == result_std, "Expected: %d, Got: %d", result_std,
                result_my);
}
END_TEST

START_TEST(test_memcmp_zero_size)  //сравнивает 0 символов
{
  const char str1[] = "Hello";
  const char str2[] = "World";
  size_t n = 0;

  int result_my = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);

  ck_assert_msg(result_my == result_std, "Expected: %d, Got: %d", result_std,
                result_my);
}
END_TEST

START_TEST(test_memcmp_large_strings)  //сравнивает очень длинные строки
{
  char str1[100000], str2[100000];
  for (int i = 0; i < 100000; ++i) {
    str1[i] = 'a';
    str2[i] = 'b';
  }
  str1[99999] = '\0';
  str2[99999] = '\0';
  size_t n = 100000;

  int result_my = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);

  ck_assert_msg(result_my == result_std, "Expected: %d, Got: %d", result_std,
                result_my);
}
END_TEST

START_TEST(test_memcmp_large_strings_unequal)  //сравнивает две большие строки,
                                               //где середина второй строки
                                               //отличается от первой
{
  char str1[100000], str2[100000];
  for (int i = 0; i < 100000; ++i) {
    str1[i] = 'a';
    str2[i] = 'b';
  }
  str1[99999] = '\0';
  str2[99999] = '\0';
  str2[50000] = 'a';
  size_t n = 100000;

  int result_my = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);

  ck_assert_msg(result_my == result_std, "Expected: %d, Got: %d", result_std,
                result_my);
}
END_TEST

START_TEST(test_memcmp_null_pointers)  // проверяет поведение функции при
                                       // передаче нулевых указателей
{
  const char *str1 = NULL;
  const char *str2 = NULL;
  size_t n = 0;

  int result_my = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);

  ck_assert_msg(result_my == result_std, "Expected: %d, Got: %d", result_std,
                result_my);
}
END_TEST

START_TEST(test_memcpy_same_memory)  //копирование данных из одной области
                                     //памяти в другую
{
  char src[] = "Hello";
  char dest[] = "World";
  size_t n = 5;

  void *result_my = s21_memcpy(dest, src, n);
  void *result_std = memcpy(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_memcpy_large_data)  //копирование большого объема данных
{
  char src[1000];
  char dest[1000];
  for (int i = 0; i < 1000; ++i) {
    src[i] = 'A';
  }
  size_t n = 1000;

  void *result_my = s21_memcpy(dest, src, n);
  void *result_std = memcpy(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

START_TEST(test_memcpy_overlap)  //копирование с перекрытием областей памяти
{
  char str[] = "Hello, World!";
  char dest[15] = {0};
  size_t n = 13;

  void *result_my = s21_memcpy(dest, str, n);
  void *result_std = memcpy(dest, str, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(dest, "Hello, World!");
}
END_TEST

START_TEST(test_memcpy_empty_source)  //проверяет копирование данных из пустого
                                      //источника
{
  char src[] = "";
  char dest[5] = "Hello";
  size_t n = 0;

  void *result_my = s21_memcpy(dest, src, n);
  void *result_std = memcpy(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_memcpy_null_pointers)  //проверяет копирование данных при
                                       //передаче нулевых указателей
{
  char *src = NULL;
  char dest[6] = "Hello";
  size_t n = 0;

  void *result_my = s21_memcpy(dest, src, n);
  void *result_std = memcpy(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(
    test_memcpy_different_sizes)  //проверяет копирование данных различной длины
{
  char src[] = "World";
  char dest[10] = "Hello";
  size_t n = 6;

  void *result_my = s21_memcpy(dest, src, n);
  void *result_std = memcpy(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(dest, "World");
}
END_TEST

START_TEST(test_memcpy_large_destination)  //проверяет копирование данных в
                                           //большой массив памяти, начиная с
                                           //определенной позиции
{
  char src[] = "Hello";
  char dest[10];
  size_t n = 6;

  void *result_my = s21_memcpy(dest, src, n);
  void *result_std = memcpy(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_memset_basic)  //проверяет базовое использование функции memset,
                               //где все байты в строке устанавливаются в
                               //определенное значение
{
  char str[] = "Hello, World!";
  size_t n = 13;

  void *result_my = s21_memset(str, 'A', n);
  void *result_std = memset(str, 'A', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_mem_eq(str, "AAAAAAAAAAAAA", n);
}
END_TEST

START_TEST(test_memset_null_pointer)  //проверяет поведение функции при передаче
                                      //нулевого указателя
{
  char *str = NULL;
  size_t n = 0;

  void *result_my = s21_memset(str, 'A', n);
  void *result_std = memset(str, 'A', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_ptr_eq(result_my, str);
}
END_TEST

START_TEST(test_memset_zero_length)  //проверяет поведение функции при установке
                                     //длины в ноль
{
  char str[] = "Hello, World!";
  size_t n = 0;

  void *result_my = s21_memset(str, 'A', n);
  void *result_std = memset(str, 'A', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(str, "Hello, World!");
}
END_TEST

START_TEST(
    test_memset_large_data)  //проверяет установку значений в большом массиве
{
  char str[1000];
  size_t n = 1000;

  void *result_my = s21_memset(str, 'A', n);
  void *result_std = memset(str, 'A', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_mem_eq(str, result_my, n);
}
END_TEST

START_TEST(test_memset_different_characters)  //проверяет установку различных
                                              //символов в массив
{
  char str[10];
  size_t n = 10;

  void *result_my = s21_memset(str, 'A', n);
  void *result_std = memset(str, 'B', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_mem_eq(str, "BBBBBBBBBB", n);
}
END_TEST

START_TEST(test_memset_different_characters_partial)  //проверяет, что только
                                                      //часть строки изменяется
                                                      //на указанное значение
{
  char str[] = "Hello, World!";
  size_t n = 5;

  void *result_std = memset(str, 'B', n);
  void *result_my = s21_memset(str, 'A', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_mem_eq(str, "AAAAA, World!", n);
}
END_TEST

START_TEST(test_memset_single_byte)  //проверяет, что функция работает корректно
                                     //для строки из одного символа
{
  char str[] = "A";
  size_t n = 1;

  void *result_my = s21_memset(str, 'B', n);
  void *result_std = memset(str, 'B', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_mem_eq(str, "B", n);
}
END_TEST

START_TEST(
    test_memset_large_characters)  //устанавливает каждый символ в массиве
                                   //в максимально возможное значение и
                                   //проверяет, что результат правильный
{
  char str[10];
  size_t n = 10;

  void *result_my = s21_memset(str, '\xff', n);
  void *result_std = memset(str, '\xff', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  for (size_t i = 0; i < n; ++i) {
    ck_assert_msg(str[i] == '\xff', "Character at position %zu does not match",
                  i);
  }
}
END_TEST

START_TEST(
    test_memset_large_characters_partial)  //устанавливает первую половину
                                           //символов в массиве в максимально
                                           //возможное значение и проверяет, что
                                           //результат правильный
{
  char str[10];
  size_t n = 5;

  void *result_my = s21_memset(str, '\xff', n);
  void *result_std = memset(str, '\xff', n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  for (size_t i = 0; i < n; ++i) {
    ck_assert_msg(str[i] == '\xff', "Character at position %zu does not match",
                  i);
  }
}
END_TEST

START_TEST(test_strncat_basic)  //проверяет базовое использование функции
                                // strncat, где строки успешно склеиваются
{
  char dest[20] = "Hello";
  const char *src = " World!";
  size_t n = 7;

  char *result_my = s21_strncat(dest, src, n);
  char *result_std = strncat(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
}
END_TEST

START_TEST(
    test_strncat_null_pointer)  // проверяет поведение функции при передаче
                                // нулевого указателя в качестве источника
{
  char dest[20] = "Hello";
  const char *src = "";
  size_t n = 0;

  s21_strncat(dest, src, n);
  char *result_my = dest;
  strncat(dest, src, n);
  char *result_std = dest;

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
}
END_TEST

START_TEST(test_strncat_zero_length)  //проверяет поведение функции при передаче
                                      //длины равной нулю
{
  char dest[20] = "Hello";
  const char *src = " World!";
  size_t n = 0;

  char *result_my = s21_strncat(dest, src, n);
  char *result_std = strncat(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_strncat_partial_source)  //проверяет склеивание строк с
                                         //ограничением на длину источника
{
  char dest[20] = "Hello";
  const char *src = " World!";
  size_t n = 3;

  char *result_my = s21_strncat(dest, src, n);
  char *result_std = strncat(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
}
END_TEST

START_TEST(test_strncat_partial_destination)  //проверяет склеивание строк с
                                              //ограничением на длину приемника
{
  char dest[20] = "Hello";
  const char *src = " World!";
  size_t n = 7;

  char *result_my = s21_strncat(dest, src, n);
  char *result_std = strncat(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
}
END_TEST

START_TEST(test_strncat_max_length)  //проверяет склеивание строк с учетом
                                     //максимальной длины n
{
  char dest[20] = "Hello";
  const char *src = " World!";
  size_t n = 100000;

  char *result_my = s21_strncat(dest, src, n);
  char *result_std = strncat(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
}
END_TEST

START_TEST(
    test_strncat_dest_null_terminated)  //проверяет, что приемник остается
                                        // null-terminated после операции
{
  char dest[20] = "Hello";
  const char *src = " World!";
  size_t n = 10;

  char *result_my = s21_strncat(dest, src, n);
  char *result_std = strncat(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
}
END_TEST

START_TEST(
    test_strncat_src_length_shorter_than_n)  //проверяет склеивание строк, когда
                                             //длина источника меньше значения n
{
  char dest[20] = "Hello";
  const char *src = " W";
  size_t n = 5;

  char *result_my = s21_strncat(dest, src, n);
  char *result_std = strncat(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
}
END_TEST

START_TEST(
    test_strncat_dest_shorter_than_src)  //проверяет склеивание строк,
                                         //когда приемник короче источника
{
  char dest[20] = "Hi";
  const char *src = " World!";
  size_t n = 10;

  char *result_my = s21_strncat(dest, src, n);
  char *result_std = strncat(dest, src, n);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
}
END_TEST

START_TEST(test_strchr_basic)  //проверяет базовое использование функции strchr,
                               //когда символ присутствует в строке
{
  const char *str = "Hello, World!";
  int c = 'o';

  char *result_my = s21_strchr(str, c);
  char *result_std = strchr(str, c);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(result_my, "o, World!");
}
END_TEST

START_TEST(test_strchr_not_found)  //проверяет, что функция возвращает NULL,
                                   //когда искомый символ не найден в строке
{
  const char *str = "Hello, World!";
  int c = 'z';

  char *result_my = s21_strchr(str, c);
  char *result_std = strchr(str, c);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_msg(result_my == NULL, "Expected NULL pointer");
}
END_TEST

START_TEST(test_strchr_null_string)  //проверяет, что функция возвращает NULL,
                                     //когда передан NULL указатель на строку
{
  char *str = NULL;
  char c = 'o';

  char *result_my = s21_strchr(str, c);
  strchr(str, c);
  char *result_std = str;

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_msg(result_my == NULL, "Expected NULL pointer");
}
END_TEST

START_TEST(test_strchr_null_character)  //проверяет, что функция правильно
                                        //обрабатывает символ '\0'
{
  const char *str = "Hello, World!";
  int c = '\0';

  char *result_my = s21_strchr(str, c);
  char *result_std = strchr(str, c);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(result_my, "\0, World!");
}
END_TEST

START_TEST(
    test_strchr_nul_character_in_middle)  //проверяет, что функция правильно
                                          //обрабатывает символ '\0',
                                          //находящийся в середине строки
{
  char *str = "Hello, \0 World!";
  int c = 'W';

  char *result_my = s21_strchr(str, c);
  char *result_std = (char *)strchr(str, c);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_mem_eq(result_my, s21_NULL, 0);
}
END_TEST

START_TEST(
    test_strchr_nul_character_after)  //проверяет, что функция правильно
                                      //обрабатывает символ '\0', находящийся
                                      //после искомого символа в строке
{
  const char *str = "Hello, World!\0";
  int c = '!';

  char *result_my = s21_strchr(str, c);
  char *result_std = strchr(str, c);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(result_my, "!");
}
END_TEST

START_TEST(test_strchr_multiple_occurrences)  //проверяет, что функция может
                                              //находить множественные вхождения
                                              //символа в строку
{
  const char *str = "Hello, World!";
  int c = 'o';

  char *result_my = s21_strchr(str, c);
  char *result_std = strchr(str, c);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(result_my, "o, World!");

  result_my = s21_strchr(result_my + 1, c);
  result_std = strchr(result_std + 1, c);

  ck_assert_msg(result_my == result_std, "Memory addresses do not match");
  ck_assert_str_eq(result_my, "orld!");
}
END_TEST

START_TEST(test_strncmp_equal_strings)  //оба сравниваемых представляют собой
                                        //идентичные строки
{
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, World!";
  size_t n = 13;

  int result_my = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(test_strncmp_different_strings)  //сравниваемые строки различаются
{
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, Universe!";
  size_t n = 13;

  int result_my = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strncmp_equal_prefix)  //префикс обоих строк совпадает, но они
                                       //различаются в дальнейшем
{
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, Universe!";
  size_t n = 5;

  int result_my = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(
    test_strncmp_first_string_longer)  //первая строка длиннее второй строки
{
  const char *str1 = "Hello, Universe!";
  const char *str2 = "Hello, World!";
  size_t n = 16;

  int result_my = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strncmp_empty_strings)  //оба сравниваемых представляют собой
                                        //пустые строки
{
  const char *str1 = "";
  const char *str2 = "";
  size_t n = 0;

  int result_my = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(
    test_strncmp_first_string_empty)  //первая строка пустая, а вторая
                                      //строка содержит некоторое значение
{
  const char *str1 = "";
  const char *str2 = "Hello";
  size_t n = 0;

  int result_my = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(
    test_strncmp_second_string_empty)  //вторая строка пустая, а первая строка
                                       //содержит некоторое значение
{
  const char *str1 = "Hello";
  const char *str2 = "";
  size_t n = 0;

  int result_my = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(
    test_strncpy_basic)  //базовый тест, где мы копируем только часть строки
{
  const char *src = "Hello, World!";
  char dest[20];
  size_t n = 5;

  char *result_my = s21_strncpy(dest, src, n);
  char *result_std = strncpy(dest, src, n);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "Hello");
}
END_TEST

START_TEST(test_strncpy_exact_length)  // тест, где мы копируем строку точно
                                       // такой же длины
{
  const char *src = "Hello, World!";
  char dest[20];
  size_t n = strlen(src);

  char *result_my = s21_strncpy(dest, src, n);
  char *result_std = strncpy(dest, src, n);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, src);
}
END_TEST

START_TEST(test_strncpy_less_than_length)  //тест, где длина копируемой строки
                                           //меньше, чем указанная длина
{
  const char *src = "Hello, World!";
  char dest[20];
  size_t n = 15;

  char *result_my = s21_strncpy(dest, src, n);
  char *result_std = strncpy(dest, src, n);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, src);
}
END_TEST

START_TEST(
    test_strncpy_greater_than_length)  // тест, где длина копируемой строки
                                       // больше, чем указанная длина
{
  const char *src = "Hello, World!";
  char dest[20];
  size_t n = 20;

  char *result_my = s21_strncpy(dest, src, n);
  char *result_std = strncpy(dest, src, n);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, src);
}
END_TEST

START_TEST(
    test_strncpy_empty_source)  //проверка, что функция корректно обрабатывает
                                //пустую строку и копирует ее в буфер назначения
{
  const char *src = "";
  char dest[20];
  size_t n = 5;

  char *result_my = s21_strncpy(dest, src, n);
  char *result_std = strncpy(dest, src, n);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "");
}
END_TEST

START_TEST(
    test_strncpy_null_destination)  //проверка, что функция корректно
                                    //обрабатывает случай, когда указатель
                                    //на буфер назначения равен NULL
{
  const char src[20] = "Hello, World!";
  char dest[20] = "";
  size_t n = 14;

  char *result_my = s21_strncpy(dest, src, n);
  char *result_std = strncpy(dest, src, n);

  ck_assert_str_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strncpy_null_source)  //проверка, что функция корректно
                                      //обрабатывает случай, когда указатель на
                                      //исходную строку равен NULL
{
  const char *src = "";
  char dest[20];
  size_t n = 5;

  char *result_my = s21_strncpy(dest, src, n);
  char *result_std = strncpy(dest, src, n);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "");
}
END_TEST

START_TEST(
    test_strncpy_null_destination_and_source)  //проверка, что функция корректно
                                               //обрабатывает случай, когда
                                               //указатели на буфер назначения и
                                               //исходную строку равны NULL
{
  const char *src = "";
  char *dest = "";
  size_t n = 0;

  char *result_my = s21_strncpy(dest, src, n);
  char *result_std = strncpy(dest, src, n);

  ck_assert_str_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strcspn_basic)  //базовый тест, где в str1 находится первое
                                //вхождение любого из символов из str2
{
  const char *str1 = "Hello, World!";
  const char *str2 = " ,";
  size_t result_my = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 5);
}
END_TEST

START_TEST(test_strcspn_empty_strings)  //тест на пустые строки
{
  const char *str1 = "";
  const char *str2 = "";
  size_t result_my = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(
    test_strcspn_no_match)  //тест, где в str1 нет ни одного символа из str2
{
  const char *str1 = "Hello, World!";
  const char *str2 = "XYZ";
  size_t result_my = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 13);
}
END_TEST

START_TEST(
    test_strcspn_no_common_characters)  //проверяет ситуацию, когда str1 и
                                        // str2 не имеют общих символов.
                                        //Ожидаемый результат: длина str1
{
  const char *str1 = "1234567890";
  const char *str2 = "abcdefghijklmnopqrstuvwxyz";
  size_t result_my = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, strlen(str1));
}
END_TEST

START_TEST(
    test_strcspn_full_match)  //проверяет ситуацию, когда str1 и str2 полностью
                              //совпадают. Ожидаемый результат: длина 0
{
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, World!";
  size_t result_my = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(test_strcspn_first_character_match)  //проверяет ситуацию, когда
                                                //первый символ из str2
                                                //совпадает с символом в str1
{
  const char *str1 = "Hello, World!";
  const char *str2 = "o";
  size_t result_my = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 4);
}
END_TEST

START_TEST(
    test_strcspn_no_characters_from_str2_in_str1)  //проверяет ситуацию, когда
                                                   //нет ни одного символа из
                                                   // str2 в str1
{
  const char *str1 = "Hello, World!";
  const char *str2 = "XYZ";
  size_t result_my = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, strlen(str1));
}
END_TEST

START_TEST(
    test_strerror_valid_error_code)  // проверяет, что для валидного кода ошибки
                                     // результат функции strerror совпадает с
                                     // результатом стандартной библиотеки
{
  int errnum = EINVAL;
  char *result_my = s21_strerror(errnum);
  char *result_std = strerror(errnum);

  ck_assert_str_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strerror_invalid_error_code)  // проверяет, что для невалидного
                                              // кода ошибки результат функции
                                              // strerror не равен NULL
{
  int errnum = -1;
  char *result_my = s21_strerror(errnum);

  ck_assert_ptr_eq(result_my, 0);
}
END_TEST

START_TEST(
    test_strerror_valid_error_code_enoent)  //проверяет, что функция
                                            //s21_strerror возвращает корректное
                                            //описание для ошибки ENOENT
{
  int errnum = ENOENT;
  char *result_my = s21_strerror(errnum);
  char *result_std = strerror(errnum);

  ck_assert_str_eq(result_my, result_std);
}
END_TEST

START_TEST(
    test_strerror_valid_error_code_einval)  //проверяет, что функция
                                            //s21_strerror возвращает корректное
                                            //описание для ошибки EINVAL
{
  int errnum = EINVAL;
  char *result_my = s21_strerror(errnum);
  char *result_std = strerror(errnum);

  ck_assert_str_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strerror_valid_error_code_enomem)  // проверяет, что функция
                                                   // s21_strerror возвращает
                                                   // корректное описание для
                                                   // ошибки ENOMEM
{
  int errnum = ENOMEM;
  char *result_my = s21_strerror(errnum);
  char *result_std = strerror(errnum);

  ck_assert_str_eq(result_my, result_std);
}
END_TEST

START_TEST(
    test_strerror_invalid_error_code_high)  //проверяет, что функция
                                            //s21_strerror возвращает ненулевой
                                            //результат для невалидного высокого
                                            //значения кода ошибки
{
  int errnum = 1000;
  char *result_my = s21_strerror(errnum);

  ck_assert_ptr_ne(result_my, NULL);
}
END_TEST

START_TEST(
    test_strlen_empty_string)  //проверяет, что длина пустой строки равна 0
{
  const char *str = "";
  size_t result_my = s21_strlen(str);
  size_t result_std = strlen(str);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(test_strlen_non_empty_string)  //проверяет, что длина непустой строки
                                          //корректно вычисляется
{
  const char *str = "Hello, World!";
  size_t result_my = s21_strlen(str);
  size_t result_std = strlen(str);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 13);
}
END_TEST

START_TEST(test_strlen_null_string)  //проверяет, что функция правильно
                                     //обрабатывает нулевой указатель
{
  const char *str = "";
  size_t result_my = s21_strlen(str);
  size_t result_std = strlen(str);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 0);
}
END_TEST

START_TEST(
    test_strlen_single_character)  //проверяет, что функция правильно определяет
                                   //длину строки с одним символом
{
  const char *str = "A";
  size_t result_my = s21_strlen(str);
  size_t result_std = strlen(str);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 1);
}
END_TEST

START_TEST(test_strlen_long_string)  //проверяет, что функция правильно
                                     //определяет длину длинной строки
{
  const char *str = "This is a long string with multiple characters";
  size_t result_my = s21_strlen(str);
  size_t result_std = strlen(str);

  ck_assert_int_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strlen_utf8_string)  //проверяет, что функция правильно
                                     //определяет длину строки с символами UTF-8
{
  const char *str = "Привет, мир!";
  size_t result_my = s21_strlen(str);
  size_t result_std = strlen(str);

  ck_assert_int_eq(result_my, result_std);
}
END_TEST

START_TEST(
    test_strlen_embedded_null)  //проверяет, что функция корректно обрабатывает
                                //строку с встроенным нулевым символом,
                                //возвращая правильную длину до него
{
  const char *str = "Hello\0World";
  size_t result_my = s21_strlen(str);
  size_t result_std = strlen(str);

  ck_assert_int_eq(result_my, result_std);
  ck_assert_int_eq(result_my, 5);
}
END_TEST

START_TEST(
    test_strpbrk_match)  //проверяет, что функция правильно находит первое
                         //совпадение в строке str1 с любым символом из str2
{
  const char *str1 = "abcdef";
  const char *str2 = "cde";
  char *result_my = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, str1 + 2);
}
END_TEST

START_TEST(test_strpbrk_no_match)  //проверяет, что функция возвращает NULL,
                                   //если в строке str1 нет ни одного совпадения
                                   //с символами из str2
{
  const char *str1 = "abcdef";
  const char *str2 = "xyz";
  char *result_my = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, NULL);
}
END_TEST

START_TEST(test_strpbrk_empty_str2)  // проверяет, что функция возвращает NULL,
                                     // если строка str2 пустая
{
  const char *str1 = "abcdef";
  const char *str2 = "";
  char *result_my = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, NULL);
}
END_TEST

START_TEST(
    test_strpbrk_null_str1)  //проверяет, что функция корректно обрабатывает
                             //случай, когда str1 является нулевым указателем
{
  const char *str1 = "";
  const char *str2 = "xyz";
  char *result_my = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_my, result_std);
}
END_TEST

START_TEST(
    test_strpbrk_null_str2)  //проверяет, что функция корректно обрабатывает
                             //случай, когда str2 является нулевым указателем
{
  const char *str1 = "abcdef";
  const char *str2 = "";
  char *result_my = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);

  ck_assert_ptr_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strrchr_match)  //проверяет, что функция правильно находит
                                //последнее вхождение символа c в строке str
{
  const char *str = "abcdef";
  int c = 'c';
  char *result_my = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, str + 2);
}
END_TEST

START_TEST(test_strrchr_no_match)  //проверяет, что функция возвращает NULL,
                                   //если символ c не найден в строке str
{
  const char *str = "abcdef";
  int c = 'x';
  char *result_my = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, NULL);
}
END_TEST

START_TEST(test_strrchr_null_str)  //проверяет, что функция корректно
                                   //обрабатывает случай, когда строка str
                                   //является нулевым указателем
{
  const char *str = "";
  int c = 'c';
  char *result_my = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);

  ck_assert_ptr_eq(result_my, result_std);
}
END_TEST

START_TEST(
    test_strrchr_match_last)  //проверяет, что функция правильно находит
                              //последнее вхождение символа c в строке str
{
  const char *str = "abcdef";
  int c = 'f';
  char *result_my = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, str + 5);
}
END_TEST

START_TEST(test_strrchr_empty_str)  //проверяет, что функция возвращает NULL,
                                    //если строка str пустая
{
  const char *str = "";
  int c = 'c';
  char *result_my = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, NULL);
}
END_TEST

START_TEST(
    test_strrchr_multiple_occurrences)  //проверяет, что функция правильно
                                        //находит последнее вхождение символа c
                                        //в строке str с несколькими вхождениями
                                        //этого символа
{
  const char *str = "abcbab";
  int c = 'b';
  char *result_my = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, str + 5);
}
END_TEST

START_TEST(test_strstr_match)  //проверяет, что функция правильно находит первое
                               //вхождение подстроки needle в строке haystack
{
  const char *haystack = "Hello, world!";
  const char *needle = "world";
  char *result_my = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, haystack + 7);
}
END_TEST

START_TEST(
    test_strstr_no_match)  //проверяет, что функция возвращает NULL, если
                           //подстрока needle не найдена в строке haystack
{
  const char *haystack = "Hello, world!";
  const char *needle = "universe";
  char *result_my = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, NULL);
}
END_TEST

START_TEST(test_strstr_null_haystack)  // проверяет, что функция корректно
                                       // обрабатывает случай, когда строка
                                       // haystack является нулевым указателем
{
  const char *haystack = "";
  const char *needle = "world";
  char *result_my = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);

  ck_assert_ptr_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strstr_null_needle)  //проверяет, что функция корректно
                                     //обрабатывает случай, когда подстрока
                                     // needle является нулевым указателем
{
  const char *haystack = "Hello, world!";
  const char *needle = "";
  char *result_my = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);

  ck_assert_ptr_eq(result_my, result_std);
}
END_TEST

START_TEST(test_strstr_match_beginning)  //проверяет, что функция правильно
                                         //находит подстроку needle, находящуюся
                                         //в начале строки haystack
{
  const char *haystack = "Hello, world!";
  const char *needle = "Hello";
  char *result_my = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, haystack);
}
END_TEST

START_TEST(
    test_strstr_match_end)  //проверяет, что функция правильно находит подстроку
                            // needle, находящуюся в конце строки haystack
{
  const char *haystack = "Hello, world!";
  const char *needle = "world!";
  char *result_my = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, haystack + 7);
}
END_TEST

START_TEST(test_strtok_basic)  //разбивает строку "This is a test" на токены,
                               //используя разделитель пробел
{
  char str[] = "This is a test";
  char delim[] = " ";
  char *result_my = s21_strtok(str, delim);
  char *result_std = strtok(str, delim);
  ck_assert_str_eq(result_my, result_std);
  while (result_std != NULL) {
    result_my = s21_strtok(NULL, delim);
    result_std = strtok(NULL, delim);
    ck_assert_str_eq(result_my, result_std);
  }
}
END_TEST

START_TEST(
    test_strtok_multiple_delimiters)  //проверяет, как функция обрабатывает
                                      //случай, когда в строке есть несколько
                                      //разделителей подряд
{
  char str[] = "This,,is,a,test";
  const char delim[] = ",";
  char *result_my;
  char *result_std;

  result_my = s21_strtok(str, delim);
  result_std = strtok(str, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "This");

  result_my = s21_strtok(NULL, delim);
  result_std = strtok(NULL, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "");

  result_my = s21_strtok(NULL, delim);
  result_std = strtok(NULL, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "is");

  result_my = s21_strtok(NULL, delim);
  result_std = strtok(NULL, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "a");

  result_my = s21_strtok(NULL, delim);
  result_std = strtok(NULL, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "test");

  result_my = s21_strtok(NULL, delim);
  result_std = strtok(NULL, delim);

  ck_assert_ptr_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, NULL);
}
END_TEST

START_TEST(test_strtok_delimiter_at_start)  //проверяет, что функция корректно
                                            //обрабатывает случай, когда строка
                                            //начинается с разделителя
{
  char str[] = ",This,is,a,test";
  const char delim[] = ",";
  char *result_my;
  char *result_std;

  result_my = s21_strtok(str, delim);
  result_std = strtok(str, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "");

  result_my = s21_strtok(NULL, delim);
  result_std = strtok(NULL, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_str_eq(result_my, "This");
}
END_TEST

START_TEST(test_strtok_empty_string)  //проверяет, что функция возвращает NULL,
                                      //если строка является пустой
{
  char str[] = "";
  const char delim[] = ",";
  char *result_my;
  char *result_std;

  result_my = s21_strtok(str, delim);
  result_std = strtok(str, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, NULL);
}
END_TEST

START_TEST(
    test_strtok_delimiters_only)  //проверяет, что функция возвращает NULL, если
                                  //строка содержит только разделители.
{
  char str[] = ",,,";
  const char delim[] = ",";
  char *result_my;
  char *result_std;

  result_my = s21_strtok(str, delim);
  result_std = strtok(str, delim);

  ck_assert_str_eq(result_my, result_std);
  ck_assert_ptr_eq(result_my, NULL);
}
END_TEST

START_TEST(test_to_upper_basic)  //преобразование строки в верхний регистр
{
  const char *input = "hello";
  char *result = s21_to_upper(input);
  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(
    test_to_upper_empty_string)  //проверка работы функции с пустой строкой
{
  const char *input = "";
  char *result = s21_to_upper(input);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_to_upper_null_input)  //проверка того, что функция правильно
                                      //обрабатывает NULL вход
{
  char *result = s21_to_upper(NULL);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_to_upper_with_spaces)  //строки с пробелами
{
  const char *input = "hello world";
  char *result = s21_to_upper(input);
  ck_assert_str_eq(result, "HELLO WORLD");
  free(result);
}
END_TEST

START_TEST(test_to_upper_with_symbols)  //строки с специальными символами
{
  const char *input = "hello#world!";
  char *result = s21_to_upper(input);
  ck_assert_str_eq(result, "HELLO#WORLD!");
  free(result);
}
END_TEST

START_TEST(test_to_upper_with_numbers)  //строки с числами
{
  const char *input = "hello123world";
  char *result = s21_to_upper(input);
  ck_assert_str_eq(result, "HELLO123WORLD");
  free(result);
}
END_TEST

START_TEST(test_to_lower_basic)  //преобразование строки в нижний регистр
{
  const char *input = "HELLO";
  char *result = s21_to_lower(input);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(
    test_to_lower_empty_string)  //проверка работы функции с пустой строкой
{
  const char *input = "";
  char *result = s21_to_lower(input);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_to_lower_null_input)  //проверка того, что функция правильно
                                      //обрабатывает NULL вход
{
  char *result = s21_to_lower(NULL);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_to_lower_with_spaces)  //строки с пробелами
{
  const char *input = "Hello World";
  char *result = s21_to_lower(input);
  ck_assert_str_eq(result, "hello world");
  free(result);
}
END_TEST

START_TEST(test_to_lower_with_symbols)  //строки с специальными символами
{
  const char *input = "Hello#World!";
  char *result = s21_to_lower(input);
  ck_assert_str_eq(result, "hello#world!");
  free(result);
}
END_TEST

START_TEST(test_to_lower_with_numbers)  //строки с числами
{
  const char *input = "Hello123World";
  char *result = s21_to_lower(input);
  ck_assert_str_eq(result, "hello123world");
  free(result);
}
END_TEST

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
  const char *str = NULL;
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, src);
}
END_TEST

START_TEST(test_trim_basic)  //обрезка пробелов в начале и конце строки
{
  const char *src = "   hello   ";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_trim_multiple_chars)  //Обрезка нескольких символов, указанных в
                                      // trim_chars
{
  const char *src = "!!Hello, World!!!";
  const char *trim_chars = "! ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World");
  free(result);
}
END_TEST

START_TEST(test_trim_empty_trim_chars)  //Обработка случая, когда trim_chars
                                        //равен пустой строке
{
  const char *src = "test";
  const char *trim_chars = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "test");
  free(result);
}
END_TEST

START_TEST(
    test_trim_null_src)  //Обработка случая, когда исходная строка равна NULL
{
  const char *src = NULL;
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_trim_empty_string)  //Обработка пустой строки
{
  const char *src = "";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_trim_all_trim_chars)  //Обрезка строки, состоящей только из
                                      //символов, которые нужно удалить
{
  const char *src = "    ";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *sprintf_suite() {
  Suite *suite = suite_create("s21_sprintf");
  TCase *group_core = tcase_create("CORE");
  tcase_add_test(group_core, S21_SPRINTF);
  suite_add_tcase(suite, group_core);
  return suite;
}

Suite *memchr_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("memchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memchr);
  tcase_add_test(tc_core, test_memchr_null);
  tcase_add_test(tc_core, test_memchr_first_occurrence);
  tcase_add_test(tc_core, test_memchr_last_occurrence);
  tcase_add_test(tc_core, test_memchr_single_char);
  tcase_add_test(tc_core, test_memchr_multiple_chars);
  tcase_add_test(tc_core, test_memchr_not_in_string);
  tcase_add_test(tc_core, test_memchr_empty_string);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *memcmp_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("memcmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memcmp_equal_strings);
  tcase_add_test(tc_core, test_memcmp_unequal_strings);
  tcase_add_test(tc_core, test_memcmp_partial_match);
  tcase_add_test(tc_core, test_memcmp_zero_size);
  tcase_add_test(tc_core, test_memcmp_large_strings);
  tcase_add_test(tc_core, test_memcmp_large_strings_unequal);
  tcase_add_test(tc_core, test_memcmp_null_pointers);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *memcpy_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("memcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memcpy_same_memory);
  tcase_add_test(tc_core, test_memcpy_large_data);
  tcase_add_test(tc_core, test_memcpy_overlap);
  tcase_add_test(tc_core, test_memcpy_empty_source);
  tcase_add_test(tc_core, test_memcpy_null_pointers);
  tcase_add_test(tc_core, test_memcpy_different_sizes);
  tcase_add_test(tc_core, test_memcpy_large_destination);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *memset_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("memset");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memset_basic);
  tcase_add_test(tc_core, test_memset_null_pointer);
  tcase_add_test(tc_core, test_memset_zero_length);
  tcase_add_test(tc_core, test_memset_large_data);
  tcase_add_test(tc_core, test_memset_different_characters);
  tcase_add_test(tc_core, test_memset_different_characters_partial);
  tcase_add_test(tc_core, test_memset_single_byte);
  tcase_add_test(tc_core, test_memset_large_characters);
  tcase_add_test(tc_core, test_memset_large_characters_partial);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strncat_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strncat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncat_basic);
  tcase_add_test(tc_core, test_strncat_null_pointer);
  tcase_add_test(tc_core, test_strncat_zero_length);
  tcase_add_test(tc_core, test_strncat_partial_source);
  tcase_add_test(tc_core, test_strncat_partial_destination);
  tcase_add_test(tc_core, test_strncat_max_length);
  tcase_add_test(tc_core, test_strncat_dest_null_terminated);
  tcase_add_test(tc_core, test_strncat_src_length_shorter_than_n);
  tcase_add_test(tc_core, test_strncat_dest_shorter_than_src);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strchr_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strchr_basic);
  tcase_add_test(tc_core, test_strchr_not_found);
  tcase_add_test(tc_core, test_strchr_null_string);
  tcase_add_test(tc_core, test_strchr_null_character);
  tcase_add_test(tc_core, test_strchr_multiple_occurrences);
  tcase_add_test(tc_core, test_strchr_nul_character_in_middle);
  tcase_add_test(tc_core, test_strchr_nul_character_after);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strncmp_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strncmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncmp_equal_strings);
  tcase_add_test(tc_core, test_strncmp_different_strings);
  tcase_add_test(tc_core, test_strncmp_equal_prefix);
  tcase_add_test(tc_core, test_strncmp_first_string_longer);
  tcase_add_test(tc_core, test_strncmp_empty_strings);
  tcase_add_test(tc_core, test_strncmp_first_string_empty);
  tcase_add_test(tc_core, test_strncmp_second_string_empty);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strncpy_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strncpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncpy_basic);
  tcase_add_test(tc_core, test_strncpy_exact_length);
  tcase_add_test(tc_core, test_strncpy_less_than_length);
  tcase_add_test(tc_core, test_strncpy_greater_than_length);
  tcase_add_test(tc_core, test_strncpy_empty_source);
  tcase_add_test(tc_core, test_strncpy_null_destination);
  tcase_add_test(tc_core, test_strncpy_null_source);
  tcase_add_test(tc_core, test_strncpy_null_destination_and_source);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strcspn_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strcspn");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strcspn_basic);
  tcase_add_test(tc_core, test_strcspn_empty_strings);
  tcase_add_test(tc_core, test_strcspn_no_match);
  tcase_add_test(tc_core, test_strcspn_no_common_characters);
  tcase_add_test(tc_core, test_strcspn_full_match);
  tcase_add_test(tc_core, test_strcspn_first_character_match);
  tcase_add_test(tc_core, test_strcspn_no_characters_from_str2_in_str1);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strerror_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strerror");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strerror_valid_error_code);
  tcase_add_test(tc_core, test_strerror_valid_error_code_enoent);
  tcase_add_test(tc_core, test_strerror_valid_error_code_einval);
  tcase_add_test(tc_core, test_strerror_valid_error_code_enomem);
  tcase_add_test(tc_core, test_strerror_invalid_error_code);
  tcase_add_test(tc_core, test_strerror_invalid_error_code_high);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strlen_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strlen");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strlen_empty_string);
  tcase_add_test(tc_core, test_strlen_non_empty_string);
  tcase_add_test(tc_core, test_strlen_null_string);
  tcase_add_test(tc_core, test_strlen_single_character);
  tcase_add_test(tc_core, test_strlen_long_string);
  tcase_add_test(tc_core, test_strlen_utf8_string);
  tcase_add_test(tc_core, test_strlen_embedded_null);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strpbrk_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strpbrk");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strpbrk_match);
  tcase_add_test(tc_core, test_strpbrk_no_match);
  tcase_add_test(tc_core, test_strpbrk_empty_str2);
  tcase_add_test(tc_core, test_strpbrk_null_str1);
  tcase_add_test(tc_core, test_strpbrk_null_str2);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strrchr_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strrchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strrchr_match);
  tcase_add_test(tc_core, test_strrchr_no_match);
  tcase_add_test(tc_core, test_strrchr_null_str);
  tcase_add_test(tc_core, test_strrchr_match_last);
  tcase_add_test(tc_core, test_strrchr_empty_str);
  tcase_add_test(tc_core, test_strrchr_multiple_occurrences);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strstr_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strstr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strstr_match);
  tcase_add_test(tc_core, test_strstr_no_match);
  tcase_add_test(tc_core, test_strstr_null_haystack);
  tcase_add_test(tc_core, test_strstr_null_needle);
  tcase_add_test(tc_core, test_strstr_match_beginning);
  tcase_add_test(tc_core, test_strstr_match_end);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *strtok_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("strtok");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strtok_basic);
  tcase_add_test(tc_core, test_strtok_multiple_delimiters);
  tcase_add_test(tc_core, test_strtok_delimiter_at_start);
  tcase_add_test(tc_core, test_strtok_empty_string);
  tcase_add_test(tc_core, test_strtok_delimiters_only);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *to_upper_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("to_upper");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_upper_basic);
  tcase_add_test(tc_core, test_to_upper_empty_string);
  tcase_add_test(tc_core, test_to_upper_null_input);
  tcase_add_test(tc_core, test_to_upper_with_spaces);
  tcase_add_test(tc_core, test_to_upper_with_symbols);
  tcase_add_test(tc_core, test_to_upper_with_numbers);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *to_lower_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("to_lower");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_lower_basic);
  tcase_add_test(tc_core, test_to_lower_empty_string);
  tcase_add_test(tc_core, test_to_lower_null_input);
  tcase_add_test(tc_core, test_to_lower_with_spaces);
  tcase_add_test(tc_core, test_to_lower_with_symbols);
  tcase_add_test(tc_core, test_to_lower_with_numbers);

  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite *insert_suite(void) {
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

Suite *trim_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("trim");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_trim_basic);
  tcase_add_test(tc_core, test_trim_multiple_chars);
  tcase_add_test(tc_core, test_trim_empty_trim_chars);
  tcase_add_test(tc_core, test_trim_null_src);
  tcase_add_test(tc_core, test_trim_empty_string);
  tcase_add_test(tc_core, test_trim_all_trim_chars);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  int number_failed;
  SRunner *suite_runner = srunner_create(sprintf_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(memchr_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(memcmp_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(memcpy_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(memset_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strchr_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strcspn_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strerror_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strlen_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strncat_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strncmp_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strncpy_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strpbrk_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strrchr_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strstr_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(strtok_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(to_upper_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(to_lower_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(insert_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite_runner = srunner_create(trim_suite());
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count += srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
