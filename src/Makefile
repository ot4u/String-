PUTb=-I/Users/theiaing/.brew/Cellar/check/0.15.2/include

gcc = gcc -std=c11
flags = -Wall -Werror -Wextra
TEST= *.c TESTS/*.cm
TEST_FLAGS = -lcheck

OS := $(shell uname -s)

ifeq ($(OS), Darwin)
    TEST_FLAGS = -lcheck
else
	TEST_FLAGS = -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
endif

all: build

build: s21_string.a

gcov_report: clean
	$(gcc) --coverage $(TEST_FLAGS) $(flags) $(TEST) -o test
	./test
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info
	open report/index.html

s21_string.a: s21_string.h
	gcc -Wall -Werror -Wextra -c s21_string.c s21_sprintf.c
	ar rc s21_string.a *.o
	ranlib s21_string.a
	rm -rf *.o

test: s21_string.a TESTS/s21_string_test.c
	gcc TESTS/s21_string_test.c s21_string.a -lcheck $(PUTb) -o s21_string_test

check:
	clang-format -i *.c *.h
	clang-format -i TESTS/*.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h TESTS/*.c
	valgrind --tool=memcheck --leak-check=yes ./s21_string_test

clean:
	rm -rf s21_string_test
	rm -rf *.gcno
	rm -f test
	rm -rf *.a *.o

rebuild: clean build
