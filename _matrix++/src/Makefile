CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++17
COVERAGE = --coverage
GTEST = -lgtest -lgtest_main -pthread

all: s21_matrix_oop.a gcov_report

s21_matrix_oop.a:
	$(CC) $(FLAGS) -c core.cpp helpers.cpp operations.cpp operators.cpp
	ar rc s21_matrix_oop.a *.o
	rm -rf *.o

test: clean s21_matrix_oop.a
	$(CC) $(FLAGS) -c test.cpp
	$(CC) $(FLAGS) -c core.cpp helpers.cpp operations.cpp operators.cpp $(COVERAGE)
	$(CC) $(FLAGS) -o s21_test core.o helpers.o operations.o operators.o test.o $(COVERAGE) $(GTEST)
	./s21_test

gcov_report: test
	lcov --no-external -c -d . -o coverage.info
	genhtml coverage.info -o coverage-html
	open coverage-html/index.html

main: clean s21_matrix_oop.a
	$(CC) $(FLAGS) main.cpp s21_matrix_oop.a -o main
	./main

clang:
	clang-format -n -style=google *.cpp *.h

clean:
	rm -rf *.o s21_test *.gcda *.gcno coverage-html coverage.info s21_matrix_oop.a main

rebuild: clean all

