CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

all: s21_matrix.a

s21_matrix.a:
	$(CC) $(FLAGS) -c matrix_functions/*.c
	$(CC) $(FLAGS) -c extra.c
	ar rc s21_matrix.a *.o

test: clean
	$(CC) $(FLAGS) -c matrix_functions/*.c extra.c --coverage
	$(CC) $(FLAGS) -c tests/*.c
	$(CC) $(FLAGS) -o s21_test *.o -lcheck --coverage
	./s21_test

# gcov_report: test
# 	lcov -c -d . -o coverage.info
# 	genhtml coverage.info -o coverage-html
# 	open coverage-html/index.html

gcov_report: test
	lcov --capture --directory . --output-file coverage.info --ignore-errors inconsistent
	genhtml coverage.info --output-directory coverage-html --ignore-errors inconsistent
	open coverage-html/index.html

main: s21_matrix.a
	$(CC) $(FLAGS) main.c s21_matrix.a
	./a.out

clean:
	rm -rf *.o s21_test *.gcda *.gcno coverage-html coverage.info s21_matrix.a a.out

rebuild: clean all