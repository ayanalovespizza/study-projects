#include "headers/polish.h"

/**
 * @brief Функция преобразования строки в постфиксное выражение
 *
 * @param str Входная строка
 *
 * @return Возращает постфиксное выражение c вставленными пропущенными
 *         элементами
 */
lexem_list *ToPolish(char *str) {
  lexem_list *unsorted_lex = ToLexemList(str);
  unsorted_lex = AddMissingOperators(unsorted_lex);

  // списки для польской нотации и стека
  lexem_list *polish = NULL;
  lexem_list *buffer_stack = NULL;

  // начинаем перебирать элементы
  while (1) {
    // обработка чисел
    if (unsorted_lex->lex.type == NUMBER) {
      polish = PushLexemStack(unsorted_lex->lex, polish);
    }

    // обработка функций и левой скобки
    else if (unsorted_lex->lex.type == FUNC ||
             unsorted_lex->lex.type == OPEN_BR) {
      buffer_stack = PushLexemStack(unsorted_lex->lex, buffer_stack);
    }

    // обработка операторов
    else if (unsorted_lex->lex.type == OPERATOR) {
      while (buffer_stack && buffer_stack->lex.type == OPERATOR &&
             (buffer_stack->lex.operator_priority <
                  unsorted_lex->lex.operator_priority ||
              (buffer_stack->lex.operator_priority ==
                   unsorted_lex->lex.operator_priority &&
               strchr("+*", unsorted_lex->lex.operation)))) {
        lexem popped_lexem = PopLexemStack(&buffer_stack);
        polish = PushLexemStack(popped_lexem, polish);
      }
      buffer_stack = PushLexemStack(unsorted_lex->lex, buffer_stack);
    }

    // обработка закрывающей скобки
    else if (unsorted_lex->lex.type == CLOSE_BR) {
      while (buffer_stack->lex.type != OPEN_BR) {
        lexem popped_lexem = PopLexemStack(&buffer_stack);
        polish = PushLexemStack(popped_lexem, polish);
      }
      PopLexemStack(&buffer_stack);
      if (buffer_stack && buffer_stack->lex.type == FUNC) {
        lexem popped_lexem = PopLexemStack(&buffer_stack);
        polish = PushLexemStack(popped_lexem, polish);
      }
    }

    // переходим к следующей лексеме, если она есть
    if (!unsorted_lex->next) {
      break;
    } else {
      unsorted_lex = unsorted_lex->next;
    }
  }

  // дорабатываем стек
  while (buffer_stack) {
    lexem popped_lexem = PopLexemStack(&buffer_stack);
    polish = PushLexemStack(popped_lexem, polish);
  }
  while (unsorted_lex->prev) {
    unsorted_lex = unsorted_lex->prev;
  }
  while (polish->prev) {
    polish = polish->prev;
  }
  FreeLexemList(unsorted_lex);

  return polish;
}

/**
 * @brief Функция преобразования строки в двухсвязный список из лексем
 *
 * @param str Входная строка
 *
 * @return Возращает указатель на список лексем lexem_list
 */
lexem_list *ToLexemList(char *str) {
  lexem_list *prev = NULL;
  lexem_list *current = NULL;

  while (*str != '\0') {
    // создаем новый элемент списка
    current = malloc(sizeof(lexem_list));
    current->prev = prev;
    current->next = NULL;

    if (current->prev) {
      current->prev->next = current;
    }
    prev = current;

    // сколько символов строки считано
    int num = 0;
    ScanLexem(str, &(current->lex), &num);
    str += num;
  }

  while (current->prev) {
    current = current->prev;
  }

  return current;
}

/**
 * @brief Функция считывания одной лексемы
 *
 * @param str Входная строка
 *
 * @return Возращает указатель на список лексем lexem_list
 */
void ScanLexem(char *str, lexem *lex, int *num) {
  *num = 1;

  // числа
  if (IsNum(*str)) {
    sscanf(str, "%Lf%n", &(lex->number), num);
    lex->type = NUMBER;
  }

  // скобки
  else if (*str == '(') {
    lex->type = OPEN_BR;
  } else if (*str == ')') {
    lex->type = CLOSE_BR;
  }

  // операторы
  else if (strchr("+-*/^%v", *str)) {
    lex->type = OPERATOR;
    lex->operation = *str;

    if (strchr("^v", *str)) {
      lex->operator_priority = 1;
    } else if (strchr("*/%", *str)) {
      lex->operator_priority = 2;
    } else if (strchr("+-", *str)) {
      lex->operator_priority = 3;
    }
  }

  // функции
  else {
    lex->type = FUNC;
    if (!strncmp(str, "ln(", 3)) {
      strcpy(lex->func, "ln");
      *num = 2;
    } else if (!strncmp(str, "log(", 4) || !strncmp(str, "sin(", 4) ||
               !strncmp(str, "cos(", 4) || !strncmp(str, "tan(", 4)) {
      strncpy(lex->func, str, 3);
      lex->func[3] = '\0';
      *num = 3;
    } else if (!strncmp(str, "asin(", 5) || !strncmp(str, "acos(", 5) ||
               !strncmp(str, "atan(", 5)) {
      strncpy(lex->func, str, 4);
      lex->func[4] = '\0';
      *num = 4;
    }
  }
}

/**
 * @brief Функция меняет унарные операторы на бинарные и добавляет умножение,
 * где оно необходимо
 *
 * @param item Список лексем
 *
 * @return Возращает указатель на дополненный список лексем lexem_list
 */
lexem_list *AddMissingOperators(lexem_list *item) {
  // обработка на унарный оператор в начале строки
  if (!item->prev && item->lex.type == OPERATOR &&
      strchr("+-", item->lex.operation)) {
    lexem_list *zero = malloc(sizeof(lexem_list));
    zero->prev = NULL;
    zero->next = item;
    item->prev = zero;
    zero->lex.type = NUMBER;
    zero->lex.number = 0;
    item = zero;
  }

  while (item->next) {
    // проверяем унарные операторы и вставляем перед ними ноль
    if (item->lex.type == OPERATOR && strchr("+-", item->lex.operation) &&
        (item->prev->lex.type == FUNC || item->prev->lex.type == OPEN_BR)) {
      lexem_list *zero = malloc(sizeof(lexem_list));
      zero->prev = item->prev;
      item->prev->next = zero;

      zero->next = item;
      item->prev = zero;

      zero->lex.type = NUMBER;
      zero->lex.number = 0;
      item = zero;
    }

    // проверяем вставку умножения в случаях:
    // [число или ")"] + ["(" или функция или число или корень]
    // вариант число/число не реализован...
    else if ((item->lex.type == NUMBER || item->lex.type == CLOSE_BR) &&
             (item->next->lex.type == OPEN_BR || item->next->lex.type == FUNC ||
              item->next->lex.type == NUMBER ||
              (item->next->lex.type == OPERATOR &&
               item->next->lex.operation == 'v'))) {
      lexem_list *mul = malloc(sizeof(lexem_list));
      mul->prev = item;
      mul->next = item->next;

      mul->prev->next = mul;
      mul->next->prev = mul;

      mul->lex.type = OPERATOR;
      mul->lex.operation = '*';
      mul->lex.operator_priority = 2;
      item = mul;
    }
    item = item->next;
  }

  while (item->prev) {
    item = item->prev;
  }

  return item;
}

/**
 * @brief Функция очищает список лексем
 *
 * @param list Список лексем
 */
void FreeLexemList(lexem_list *list) {
  if (list) {
    if (list->next) {
      FreeLexemList(list->next);
    }
    free(list);
  }
}

/**
 * @brief Функция добавления лексемы в стек
 *
 * @param lex Лексема
 * @param list Список лексем
 *
 * @return Новая лексема
 */
lexem_list *PushLexemStack(lexem lex, lexem_list *list) {
  lexem_list *new = malloc(sizeof(lexem_list));
  if (list) {
    list->next = new;
  }
  new->next = NULL;
  new->lex = lex;
  new->prev = list;

  return new;
}

/**
 * @brief Функция удаления лексемы из стека
 *
 * @param list Список лексем
 *
 * @return Возвращает удаленную лексему
 */
lexem PopLexemStack(lexem_list **list) {
  lexem_list *top = *list;
  lexem lex = top->lex;

  *list = top->prev;
  free(top);
  if (*list) {
    (*list)->next = NULL;
  }

  return lex;
}

/**
 * @brief Функция решения постфиксного выражения
 *
 * @param polish Список лексем
 *
 * @return Возвращает решение постфиксного выражения
 */
char *SolvePolish(lexem_list *polish) {
  char *result = malloc(1000 * sizeof(char));

  while (polish->next) {
    if (polish->next->lex.type == NUMBER) {
      polish = polish->next;

    } else if (polish->next->lex.type == OPERATOR) {
      lexem lex_operator = PopAndFreeLexem(polish->next);

      // обработка корня
      if (lex_operator.operation == 'v') {
        polish->lex.number = sqrt(polish->lex.number);

        // обработка бинарных операторов
      } else {
        lexem left_lex = PopAndFreeLexem(polish->prev);

        if (lex_operator.operation == '^')
          polish->lex.number = powl(left_lex.number, polish->lex.number);
        else if (lex_operator.operation == '*')
          polish->lex.number = left_lex.number * polish->lex.number;
        else if (lex_operator.operation == '/')
          polish->lex.number = left_lex.number / polish->lex.number;
        else if (lex_operator.operation == '%')
          polish->lex.number = fmodl(left_lex.number, polish->lex.number);
        else if (lex_operator.operation == '+')
          polish->lex.number = left_lex.number + polish->lex.number;
        else if (lex_operator.operation == '-')
          polish->lex.number = left_lex.number - polish->lex.number;
      }

      // обработка функций
    } else if (polish->next->lex.type == FUNC) {
      lexem lex_func = PopAndFreeLexem(polish->next);

      if (strcmp(lex_func.func, "ln") == 0)
        polish->lex.number = logl(polish->lex.number);
      else if (strcmp(lex_func.func, "log") == 0)
        polish->lex.number = log10l(polish->lex.number);
      else if (strcmp(lex_func.func, "sin") == 0)
        polish->lex.number = sinl(polish->lex.number);
      else if (strcmp(lex_func.func, "cos") == 0)
        polish->lex.number = cosl(polish->lex.number);
      else if (strcmp(lex_func.func, "tan") == 0)
        polish->lex.number = tanl(polish->lex.number);
      else if (strcmp(lex_func.func, "asin") == 0)
        polish->lex.number = asinl(polish->lex.number);
      else if (strcmp(lex_func.func, "acos") == 0)
        polish->lex.number = acosl(polish->lex.number);
      else if (strcmp(lex_func.func, "atan") == 0)
        polish->lex.number = atanl(polish->lex.number);
    }
  }

  if (polish->lex.number != polish->lex.number)
    sprintf(result, "ERROR");
  else if (polish->lex.number == INFINITY)
    sprintf(result, "inf");
  else if (polish->lex.number == -INFINITY)
    sprintf(result, "-inf");
  else
    sprintf(result, "%.7Lf", polish->lex.number);

  if (strchr(result, '.')) {
    while (result[strlen(result) - 1] == '0') {
      result[strlen(result) - 1] = '\0';
    }
    if (result[strlen(result) - 1] == '.') {
      result[strlen(result) - 1] = '\0';
    }
  }

  free(polish);

  return result;
}

/**
 * @brief Функция удаления и очищения лексемы из стека
 *
 * @param elem Список лексем
 *
 * @return Возвращает удаленную лексему
 */
lexem PopAndFreeLexem(lexem_list *elem) {
  lexem lex = elem->lex;

  if (elem->next) {
    elem->next->prev = elem->prev;
  }
  if (elem->prev) {
    elem->prev->next = elem->next;
  }

  free(elem);
  return lex;
}