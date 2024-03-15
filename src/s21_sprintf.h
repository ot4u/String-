#include <stdarg.h>

#define BUF_SIZE 4096
#define INF 100000

typedef struct options {
  int minus, plus, space, sharp, zero, put_minus;
  long width, precision;
  char length, specifier;
} options;

int s21_sprintf(char *str, const char *format, ...);
void proccesing_spec(char *str, char specifier, va_list params, options *opts);
void apply_c(char *str, va_list params, const options *opts);
void apply_d(char *str, va_list params, const options *opts);
char *s21_itoa(char *buff, unsigned long number, int base, const options *opts);
char *s21_reverse(char *buff, int len);
void apply_f(char *str, va_list params, const options *opts);
char *s21_ftoa(long double value, char *buff, const options *opts);
void apply_s(char *str, va_list params, const options *opts);
void apply_u(char *str, va_list params, const options *opts);
char *s21_utoa(char *buff, unsigned long number, int base, const options *opts);
void init_options(options *opts, int *i);
void processing_flags(const char *buff, options *opts, int *i);
void processing_width(const char *buff, va_list params, options *opts, int *i);
void processing_precision(const char *buff, va_list params, options *opts,
                          int *i);
void processing_length(const char *buff, options *opts, int *i);
long get_num_from_buffer(const char *buff, va_list params, int *i);
long collect_num(const char *buff, int *i);
long s21_atoi(char *str);
void rjust(char *str, const options *opts, int length);
void ljust(char *str, const options *opts, int length);
void put_sym_before_num(char *str, const options *opts);
long get_length_processed_int_num(va_list params, const options *opts);
long double get_length_processed_float_num(va_list params, const options *opts);
unsigned long get_length_processed_unsigned_int_num(va_list params,
                                                    const options *opts);
void to_upper(char *str);
void apply_x(char *str, va_list params, const options *opts);
void apply_X(char *str, char *buff, va_list params, const options *opts);
void apply_p(char *str, va_list params, const options *opts);
void apply_o(char *str, va_list params, const options *opts);
void apply_e(char *str, va_list params, const options *opts);
void apply_E(char *str, char *buff, va_list params, const options *opts);
void science_notaion(char *buff, long double *num, const options *opts,
                     int *pow, char *sign);
void process_mantiss(char *str, int pow, char sign);
void format_just(char *str, char *buff, const options *opts, int sign);
int process_sign(char *str, const options *opts, int sign);
void add_sym(char *str, char sym);
void apply_n(const char *str, va_list params);
void apply_g(char *str, va_list params, const options *opts);
void apply_G(char *str, char *buff, va_list params, const options *opts);
void remove_trail_zeros(char *buff);
