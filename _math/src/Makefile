CC = gcc
FLAGS = -Wall -Werror -Wextra
OBJECT_MATH = s21_abs.o s21_acos.o s21_asin.o s21_atan.o s21_ceil.o s21_cos.o \
							s21_exp.o s21_fabs.o s21_floor.o s21_fmod.o s21_log.o s21_pow.o \
							s21_sin.o s21_sqrt.o s21_tan.o

all: s21_math.a test gcov_report

s21_math.a: clean
	$(CC) $(FLAGS) -c math_functions/*.c
	$(CC) $(FLAGS) -c extra.c
	ar rc s21_math.a $(OBJECT_MATH) extra.o
	rm -rf $(OBJECT_MATH) extra.o

main: s21_math.a
	$(CC) $(FLAGS) main.c s21_math.a
	./a.out

test: 
	$(CC) $(FLAGS) -c extra.c s21_test.c
	$(CC) $(FLAGS) -c math_functions/*.c --coverage
	$(CC) $(FLAGS) -o s21_test *.o -lcheck --coverage
	./s21_test

gcov_report: test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage-html
	open coverage-html/index.html

clean:
	rm -rf *.o s21_test *.gcda *.gcno coverage-html coverage.info s21_math.a a.out

rebuild: clean all