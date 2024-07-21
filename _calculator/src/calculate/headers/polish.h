/**
 * @file polish.h
 * @brief Заголовочный файл, содержащий определения структур лексем, а также
 * функции записи и решений постфиксного выражения
 */

#ifndef POLISH_H
#define POLISH_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

/**
 * @brief Перечисление типов лексем.
 */
typedef enum {
  NUMBER,  /**< Лексема представляет число */
  FUNC,    /**< Лексема представляет функцию */
  OPEN_BR, /**< Лексема представляет открывающую скобку */
  CLOSE_BR, /**< Лексема представляет закрывающую скобку */
  OPERATOR, /**< Лексема представляет оператор */
} lexem_types;

/**
 * @brief Структура, представляющая лексему
 */
typedef struct {
  lexem_types type; /**< Тип лексемы */
  long double number; /**< Значение лексемы, если это число */
  char func[10]; /**< Название функции, если лексема является функцией */
  char operation; /**< Оператор, если лексема является оператором */
  int operator_priority; /**< Приоритет оператора, если лексема является
                            оператором */
} lexem;

/**
 * @brief Структура, представляющая связанный список лексем
 */
typedef struct l_lst {
  lexem lex; /**< Лексема, хранящаяся в узле */
  struct l_lst *prev; /**< Указатель на предыдущий узел в списке */
  struct l_lst *next; /**< Указатель на следующий узел в списке */
} lexem_list;

lexem_list *ToPolish(char *str);
lexem_list *ToLexemList(char *str);
void ScanLexem(char *str, lexem *lex, int *num);
lexem_list *AddMissingOperators(lexem_list *item);
char *SolvePolish(lexem_list *polish);

lexem_list *PushLexemStack(lexem lex, lexem_list *list);
lexem PopLexemStack(lexem_list **list);
lexem PopAndFreeLexem(lexem_list *elem);

void FreeLexemList(lexem_list *list);

#endif