gcc = gcc -std=c11
flags = -Wall -Werror -Wextra $(shell pkg-config --cflags check)
TEST= *.a TESTS/*.c
TEST_FLAGS = $(shell pkg-config --libs check)

all: build

build: s21_string.a

gcov_report: clean s21_string.a
	$(gcc) --coverage $(flags) $(TEST) $(TEST_FLAGS) -o test
	./test
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info
	open ./report/index.html

s21_string.a: s21_string.h s21_sprintf.h
	gcc -Wall -Werror -Wextra -c s21_string.c s21_sprintf.c
	ar rc s21_string.a *.o
	ranlib s21_string.a
	rm -rf *.o

test: s21_string.a TESTS/s21_string_test.c
	$(gcc) $(flags) TESTS/s21_string_test.c s21_string.a $(TEST_FLAGS) -o s21_string_test

check:
	clang-format -i *.c *.h
	clang-format -i TESTS/*.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h TESTS/*.c
	valgrind --tool=memcheck --leak-check=yes ./s21_string_test

clean:
	rm -rf s21_string_test
	rm -rf *.gcno
	rm -rf *.gcda
	rm -f test
	rm -rf *.a *.o
	rm -rf report
	rm -rf *.info

rebuild: clean build
