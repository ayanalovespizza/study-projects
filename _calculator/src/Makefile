CC = gcc
FLAGS = -Wall -Werror -Wextra
COVERAGE = --coverage

all: open

s21_calculate.a:
	$(CC) $(FLAGS) calculate/*.c -c
	ar rc s21_calculate.a *.o

test: clean
	$(CC) $(FLAGS) calculate/*.c -c $(COVERAGE)
	$(CC) $(FLAGS) tests/*.c -c
	$(CC) $(FLAGS) -o s21_test *.o -lcheck --coverage 
	./s21_test

gcov_report: test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage-html
	open coverage-html/index.html

main: s21_calculate.a
	$(CC) $(FLAGS) s21_calculate.a main.c -o main
	./main

clean:
	rm -rf *.o s21_calculate.a main *.gcda *.gcno s21_test coverage-html coverage.info docs

rebuild: clean main

install: uninstall
	echo "Installation of SmartCalc.app:"
	mkdir -p ../build
	cd SmartCalc/ && qmake && make && make clean && rm -rf Makefile && mv SmartCalc.app ../../build/SmartCalc.app
	mv ../build/SmartCalc.app/Contents/MacOS/SmartCalc ../build/SmartCalc.app/Contents/MacOS/SmartCalc.app
	echo "Installation completed! You can find app in the ../build/ folder!"

uninstall:
	rm -rf ../build

dist: install
	mkdir -p ../dist
	cp -R ../build/SmartCalc.app ../dist
	cp -R . ../dist/src
	cd ../dist && tar cvzf SmartCalc.tgz *
	cd ../dist && rm -rf SmartCalc.app
	rm -rf ../dist/src
	echo "Archive creation completed successfully!"	

dvi:
	doxygen
	open docs/html/index.html