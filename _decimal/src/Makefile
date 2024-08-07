CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

SYSTEM := $(shell uname -s)

ifeq ($(SYSTEM), Linux)
	OPEN_CMD = xdg-open
    ADD_LIB =  -lcheck -lm -lsubunit
else ifeq ($(SYSTEM), Darwin)
	OPEN_CMD = open
	ADD_LIB =  -lcheck 
else
    $(error Unsupported system: $(SYSTEM))
endif

all: test

s21_decimal.a:
	$(CC) $(FLAGS) -c comparison/*.c
	$(CC) $(FLAGS) -c another/*.c
	$(CC) $(FLAGS) -c arithmetic/*.c
	$(CC) $(FLAGS) -c convertors/*.c 
	$(CC) $(FLAGS) -c extra.c
	ar rc s21_decimal.a *.o

main: clean s21_decimal.a
	$(CC) $(FLAGS) main.c s21_decimal.a
	./a.out

test: clean
	$(CC) $(FLAGS) -c comparison/*.c --coverage
	$(CC) $(FLAGS) -c another/*.c --coverage
	$(CC) $(FLAGS) -c arithmetic/*.c --coverage
	$(CC) $(FLAGS) -c convertors/*.c --coverage
	$(CC) $(FLAGS) -c extra.c tests/*.c
	$(CC) $(FLAGS) -o s21_test *.o $(ADD_LIB) --coverage 
	./s21_test

gcov_report: test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage-html
	$(OPEN_CMD) coverage-html/index.html

clean: 
	rm -rf *.o s21_test *.gcda *.gcno coverage-html coverage.info s21_decimal.a a.out

rebuld: clean all


install:
ifeq ($(SYSTEM), Linux)
	apk add --no-cache check perl-capture-tiny perl-datetime build-base subunit-dev

	git clone https://github.com/linux-test-project/lcov.git /tmp/lcov && \
		cd /tmp/lcov && \
		make install && \
		cd -
else
	brew install lcov
endif