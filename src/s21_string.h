#ifndef S21_STRING_H
#define S21_STRING_H

#define s21_NULL ((void *)0)
typedef long unsigned s21_size_t;

#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <wchar.h>

#define s21_IS_SPEC(ch)                                                       \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'f' || (ch) == 's' || \
   (ch) == 'u' || (ch) == '%' || (ch) == 'x' || (ch) == 'X' || (ch) == 'o' || \
   (ch) == 'p' || (ch) == 'n' || (ch) == 'e' || (ch) == 'E' || (ch) == 'g' || \
   (ch) == 'G')
#define s21_IS_LENGTH(ch) ((ch) == 'l' || (ch) == 'h' || (ch) == 'L')
#define s21_IS_NUMERIC(ch) (((ch) <= '9' && (ch) >= '0') || (ch) == '*')
#define s21_IS_FLAG(ch) \
  ((ch) == ' ' || (ch) == '+' || (ch) == '-' || (ch) == '#' || (ch) == '0')

#define s21_INF 1.0 / 0.0

typedef long unsigned int s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *array1, const void *array2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strchr(const char *str, int c);
s21_size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
char *s21_strstr(const char *haystack, const char *needle);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif