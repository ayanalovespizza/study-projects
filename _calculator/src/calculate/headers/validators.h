/**
 * @file validators.h
 * @brief Заголовочный файл, содержащий функции для валидации входной строки.
 */

#ifndef VALIDATORS_H
#define VALIDATORS_H

#define OK 1
#define ERROR 0
#define MAXLEN 255

#include <stdbool.h>
#include <stdlib.h>

#include "helpers.h"

int InsertionIsValid(char *input);
int BracketIsValid(char *input);
int DotIsValid(char *input);
int CheckDotPosition(char *input, int index, int *dots_count);
int OperatorIsValid(char *input);
int CheckLimBrackets(char *input, size_t i, int length);
int TrigFuncIsValid(char *input);
int OtherFuncIsValid(char *input);
int NumberIsValid(char *input);
int CharIsValid(char *input);

#endif