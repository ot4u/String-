#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list params;
  va_start(params, format);
  int i = 0;
  s21_memset(str, 0, s21_strlen(str));
  while (i < (int)s21_strlen(format)) {
    if (format[i] != '%') {
      add_sym(str, format[i++]);
    } else {
      options opts = {0};
      init_options(&opts, &i);
      processing_flags(format, &opts, &i);
      processing_width(format, params, &opts, &i);
      processing_precision(format, params, &opts, &i);
      processing_length(format, &opts, &i);
      proccesing_spec(str, format[i++], params, &opts);
    }
  }
  va_end(params);
  return s21_strlen(str);
}

void init_options(options *opts, int *i) {
  opts->minus = opts->plus = opts->space = opts->sharp = opts->zero =
      opts->width = 0;
  opts->precision = -1;
  opts->length = '\0';
  *i = *i + 1;
}

void proccesing_spec(char *str, char specifier, va_list params, options *opts) {
  char buff[BUF_SIZE] = {0};
  opts->specifier = specifier;
  switch (specifier) {
    case 'c':
      apply_c(str, params, opts);
      break;
    case 'd':
      apply_d(str, params, opts);
      break;
    case 'i':
      apply_d(str, params, opts);
      break;
    case 'f':
      if (opts->precision == -1) opts->precision = 6;
      apply_f(str, params, opts);
      break;
    case 's':
      if (opts->precision == -1) opts->precision = INF;
      apply_s(str, params, opts);
      break;
    case 'u':
      apply_u(str, params, opts);
      break;
    case 'o':
      apply_o(str, params, opts);
      break;
    case 'x':
      apply_x(str, params, opts);
      break;
    case 'X':
      apply_X(str, buff, params, opts);
      break;
    case 'p':
      apply_p(str, params, opts);
      break;
    case 'e':
      if (opts->precision == -1) opts->precision = 6;
      apply_e(str, params, opts);
      break;
    case 'E':
      if (opts->precision == -1) opts->precision = 6;
      apply_E(str, buff, params, opts);
      break;
    case 'g':
      if (opts->precision == -1) opts->precision = 6;
      apply_g(str, params, opts);
      break;
    case 'G':
      if (opts->precision == -1) opts->precision = 6;
      apply_G(str, buff, params, opts);
      break;
    case 'n':
      apply_n(str, params);
      break;
    case '%':
      add_sym(str, '%');
      break;
    default:
      break;
  }
}

void processing_flags(const char *buff, options *opts, int *i) {
  int out = 0;
  while (1) {
    switch (buff[*i]) {
      case '-':
        opts->minus = 1;
        break;
      case '+':
        opts->plus = 1;
        break;
      case ' ':
        opts->space = 1;
        break;
      case '#':
        opts->sharp = 1;
        break;
      case '0':
        opts->zero = 1;
        break;
      default:
        out = 1;
        break;
    }
    if (out) break;
    *i = *i + 1;
  }
}

void processing_width(const char *buff, va_list params, options *opts, int *i) {
  opts->width = get_num_from_buffer(buff, params, i);
}

void processing_precision(const char *buff, va_list params, options *opts,
                          int *i) {
  if (buff[*i] == '.') {
    *i = *i + 1;
    opts->precision = get_num_from_buffer(buff, params, i);
  }
}

void processing_length(const char *buff, options *opts, int *i) {
  if (buff[*i] == 'h' || buff[*i] == 'l' || buff[*i] == 'L') {
    opts->length = buff[*i];
    *i = *i + 1;
  }
}

long get_num_from_buffer(const char *buff, va_list params, int *i) {
  long num = 0;
  if (buff[*i] >= '0' && buff[*i] <= '9') {
    num = collect_num(buff, i);
  }
  if (buff[*i] == '*') {
    num = va_arg(params, int);
    *i = *i + 1;
  }
  return num;
}

long collect_num(const char *buff, int *i) {
  char width[100] = {0};
  while (buff[*i] >= '0' && buff[*i] <= '9') {
    width[s21_strlen(width)] = buff[*i];
    *i = *i + 1;
  }
  return s21_atoi(width);
}

long s21_atoi(char *str) {
  long num = 0;
  while (*str) {
    num = num * 10 + (*str) - '0';
    str++;
  }
  return num;
}

void apply_c(char *str, va_list params, const options *opts) {
  char c = va_arg(params, int);
  rjust(str, opts, 1);
  add_sym(str, c);
  ljust(str, opts, 1);
}

void apply_d(char *str, va_list params, const options *opts) {
  long long number = get_length_processed_int_num(params, opts);
  char buff[BUF_SIZE] = {0};
  s21_itoa(buff, number < 0 ? -number : number, 10, opts);
  format_just(str, buff, opts, number < 0 ? 1 : 0);
}

char *s21_itoa(char *buff, unsigned long number, int base,
               const options *opts) {
  int count = 0;
  do {
    int digit = number % base;
    buff[count++] = (digit > 9) ? digit - 10 + 'a' : digit + '0';
  } while ((number /= base) != 0);
  if (opts->precision > (int)s21_strlen(buff) && opts->specifier != 'f' &&
      opts->specifier != 'e' && opts->specifier != 'E' &&
      opts->specifier != 'g' && opts->specifier != 'G') {
    while (opts->precision != (int)s21_strlen(buff)) {
      buff[count++] = '0';
    }
  }
  buff[count] = '\0';
  s21_reverse(buff, count);
  return buff;
}

char *s21_reverse(char *buff, int len) {
  for (int i = 0; i < len / 2; i++) {
    char c = buff[i];
    buff[i] = buff[len - i - 1];
    buff[len - i - 1] = c;
  }
  return buff;
}

void apply_f(char *str, va_list params, const options *opts) {
  long double value = get_length_processed_float_num(params, opts);
  char buff[BUF_SIZE] = {0};
  s21_ftoa(value < 0 ? -value : value, buff, opts);
  format_just(str, buff, opts, value < 0 ? 1 : 0);
}

char *s21_ftoa(long double value, char *buff, const options *opts) {
  s21_itoa(buff, (long)value, 10, opts);
  value = value < 0 ? -value : value;
  if (opts->precision > 0) {
    add_sym(buff, '.');
    int i = 0;
    while (i++ < opts->precision) {
      value *= 10;
      long sub = (long)value % 10;
      add_sym(buff, sub + '0');
    }
  }
  return buff;
}

void apply_s(char *str, va_list params, const options *opts) {
  const char *buff = va_arg(params, char *);
  if (s21_strlen(buff) > (size_t)opts->precision) {
    rjust(str, opts, opts->precision);
    for (int i = 0; i < opts->precision; i++) {
      add_sym(str, buff[i]);
    }
  } else {
    rjust(str, opts, s21_strlen(buff));
    for (int i = 0; i < (int)s21_strlen(buff); i++) {
      add_sym(str, buff[i]);
    }
  }
  ljust(str, opts, s21_strlen(buff));
}

void apply_u(char *str, va_list params, const options *opts) {
  unsigned long number = get_length_processed_unsigned_int_num(params, opts);
  char buff[BUF_SIZE] = {0};
  s21_utoa(buff, number, 10, opts);
  format_just(str, buff, opts, 0);
}

char *s21_utoa(char *buff, unsigned long number, int base,
               const options *opts) {
  s21_itoa(buff, number, base, opts);
  return buff;
}

void rjust(char *str, const options *opts, int length) {
  if (opts->width && !opts->minus) {
    char justSym = ' ';
    if (opts->zero) {
      justSym = '0';
    }
    for (int _ = 0; _ < opts->width - length; _++) {
      add_sym(str, justSym);
    }
  }
}

void ljust(char *str, const options *opts, int length) {
  if (opts->width && opts->minus) {
    char justSym = ' ';
    for (int _ = 0; _ < opts->width - length; _++) {
      add_sym(str, justSym);
    }
  }
}

void put_sym_before_num(char *str, const options *opts) {
  if (opts->space || opts->plus) {
    char sym_to_put = ' ';
    if (opts->plus) sym_to_put = '+';
    add_sym(str, sym_to_put);
  }
}

long get_length_processed_int_num(va_list params, const options *opts) {
  long number = 0;
  if (opts->length == 'h')
    number = (short)va_arg(params, int);
  else if (opts->length == 'l')
    number = (long)va_arg(params, long);
  else
    number = (int)va_arg(params, int);
  return number;
}

long double get_length_processed_float_num(va_list params,
                                           const options *opts) {
  long double number = 0.0;
  if (opts->length == 'L')
    number = (long double)va_arg(params, long double);
  else
    number = (double)va_arg(params, double);
  return number;
}

unsigned long get_length_processed_unsigned_int_num(va_list params,
                                                    const options *opts) {
  long number = 0;
  if (opts->length == 'h')
    number = (unsigned short)va_arg(params, int);
  else if (opts->length == 'l')
    number = (unsigned long)va_arg(params, long);
  else
    number = (unsigned int)va_arg(params, int);
  return number;
}

void apply_o(char *str, va_list params, const options *opts) {
  char buff[BUF_SIZE] = {0};
  long number = get_length_processed_unsigned_int_num(params, opts);
  if (number != 0 && opts->sharp) {
    add_sym(buff, '0');
    s21_utoa(buff + 1, number, 8, opts);
  } else {
    s21_utoa(buff, number, 8, opts);
  }
  format_just(str, buff, opts, 0);
}

void apply_p(char *str, va_list params, const options *opts) {
  long value = get_length_processed_unsigned_int_num(params, opts);
  char buff[BUF_SIZE] = {0};
  if (value) {
    char buff_2[BUF_SIZE] = {0};
    s21_utoa(buff_2, value, 16, opts);
    s21_strncat(buff, "0x", 2);
    s21_strncat(buff, buff_2, s21_strlen(buff_2));
  } else {
    s21_strncat(buff, "0x0", 3);
  }
  format_just(str, buff, opts, 0);
}

void apply_x(char *str, va_list params, const options *opts) {
  long number = get_length_processed_unsigned_int_num(params, opts);
  char buff[BUF_SIZE] = {0};
  if (number != 0 && opts->sharp) {
    s21_strncat(buff, "0x", 2);
    s21_utoa(buff + 2, number, 16, opts);
  } else {
    s21_utoa(buff, number, 16, opts);
  }
  format_just(str, buff, opts, 0);
}

void apply_X(char *str, char *buff, va_list params, const options *opts) {
  apply_x(buff, params, opts);
  buff = s21_to_upper(buff);
  s21_strncat(str, buff, s21_strlen(buff));
  free(buff);
}

void apply_e(char *str, va_list params, const options *opts) {
  long double num = get_length_processed_float_num(params, opts);
  int pow = 0;
  char sign = '+';
  char buff[BUF_SIZE] = {0};
  science_notaion(buff, &num, opts, &pow, &sign);
  process_mantiss(buff, pow, sign);
  format_just(str, buff, opts, num < 0 ? 1 : 0);
}

void apply_E(char *str, char *buff, va_list params, const options *opts) {
  apply_e(buff, params, opts);
  buff = s21_to_upper(buff);
  s21_strncat(str, buff, s21_strlen(buff));
  free(buff);
}

void science_notaion(char *buff, long double *num, const options *opts,
                     int *pow, char *sign) {
  if ((int)*num == 0) *sign = '-';
  if ((int)*num - *num) {
    while ((int)*num == 0) {
      (*pow)++;
      *num *= 10;
    }
  } else {
    *sign = '+';
  }
  while ((int)*num / 10 != 0) {
    (*pow)++;
    *num /= 10;
  }
  s21_ftoa(*num < 0 ? -*num : *num, buff, opts);
}

void process_mantiss(char *str, int pow, char sign) {
  int length = s21_strlen(str);
  str[length] = 'e';
  str[length + 1] = sign;
  str[length + 3] = pow % 10 + '0';
  pow /= 10;
  str[length + 2] = pow % 10 + '0';
  str[length + 4] = '\0';
}

void format_just(char *str, char *buff, const options *opts, int sign) {
  char temp[BUF_SIZE] = {0};
  int znak = 0;
  znak = process_sign(temp, opts, sign);
  if (!opts->zero) {
    s21_strncat(temp, buff, s21_strlen(buff));
    s21_strncpy(buff, temp, s21_strlen(temp));
    s21_memset(temp, 0, s21_strlen(temp));
    znak = 0;
  }
  rjust(temp, opts, s21_strlen(buff) + znak);
  s21_strncat(temp, buff, s21_strlen(buff));
  ljust(temp, opts, s21_strlen(temp));
  s21_strncat(str, temp, s21_strlen(temp));
}

int process_sign(char *str, const options *opts, int sign) {
  int znak = 0;
  if (sign || opts->plus || opts->space) znak = 1;
  if (sign)
    add_sym(str, '-');
  else
    put_sym_before_num(str, opts);
  return znak;
}

void add_sym(char *str, char sym) {
  str[s21_strlen(str) + 1] = '\0';
  str[s21_strlen(str)] = sym;
}

void apply_n(const char *str, va_list params) {
  int *number = va_arg(params, int *);
  *number = s21_strlen(str);
}

void apply_g(char *str, va_list params, const options *opts) {
  long double num = get_length_processed_float_num(params, opts);
  long double num_1 = num;
  options temp_opts = *opts;
  int pow = 0;
  char sign = '+';
  char buff_1[BUF_SIZE] = {0};
  char buff_2[BUF_SIZE] = {0};
  s21_itoa(buff_2, num < 0 ? -num : num, 10, opts);
  temp_opts.precision = opts->precision - s21_strlen(buff_2);
  s21_memset(buff_2, 0, s21_strlen(buff_2));
  int precision = temp_opts.precision;
  if (temp_opts.precision < 0 && opts->precision != 0) temp_opts.precision = 1;
  science_notaion(buff_1, &num_1, &temp_opts, &pow, &sign);
  remove_trail_zeros(buff_1);
  process_mantiss(buff_1, pow, sign);
  temp_opts.precision = precision;
  s21_ftoa(num < 0 ? -num : num, buff_2, &temp_opts);
  remove_trail_zeros(buff_2);
  if (precision < 0 && pow != 0)
    format_just(str, buff_1, opts, num < 0 ? 1 : 0);
  else
    format_just(str, buff_2, opts, num < 0 ? 1 : 0);
}

void apply_G(char *str, char *buff, va_list params, const options *opts) {
  apply_g(buff, params, opts);
  buff = s21_to_upper(buff);
  s21_strncat(str, buff, s21_strlen(buff));
  free(buff);
}

void remove_trail_zeros(char *buff) {
  while (buff[s21_strlen(buff) - 1] == '0') {
    buff[s21_strlen(buff) - 1] = '\0';
  }
}