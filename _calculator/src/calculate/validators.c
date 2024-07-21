#include "headers/validators.h"

/**
 * @brief Функция проверяет строку на корректность ввода
 *
 * @param input Входная строка
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int InsertionIsValid(char *input) {
  int result = OK;

  if (input == NULL || strlen(input) == 0 || strlen(input) > MAXLEN) {
    result = ERROR;
  } else if (BracketIsValid(input) == 0) {
    result = ERROR;
  } else if (DotIsValid(input) == 0) {
    result = ERROR;
  } else if (OperatorIsValid(input) == 0) {
    result = ERROR;
  } else if (TrigFuncIsValid(input) == 0) {
    result = ERROR;
  } else if (OtherFuncIsValid(input) == 0) {
    result = ERROR;
  } else if (CharIsValid(input) == 0) {
    result = ERROR;
  }

  return result;
}

/**
 * @brief Функция проверяет строку на корректность ввода скобок "(" и ")"
 *
 * @param input Входная строка
 *
 * @details Обрабатываются следующие ситуации:
 *          - подряд идущие открывающая и закрывающая скобки
 *          - количество открывающих скобок не равно количеству закрывающих
 *            скобок
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int BracketIsValid(char *input) {
  int result = OK;
  int brackets_count = 0;

  for (int i = 0; input[i] != '\0' && result; i++) {
    if (input[i] == '(') {
      brackets_count++;
      if (input[i + 1] == ')') {
        result = ERROR;
      }
    } else if (input[i] == ')') {
      brackets_count--;
    }
  }

  if (brackets_count != 0) {
    result = ERROR;
  }

  return result;
}

/**
 * @brief Функция проверяет строку на корректность ввода точек
 *
 * @param input Входная строка
 *
 * @details Обрабатываются следующие ситуации:
 *          - несколько точек в одном числе (например, 2.3.4 и 2..4)
 *          - точка без цифры перед ней (например, .234)
 *          - одиночная точка
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int DotIsValid(char *input) {
  int result = OK;
  int dots_count = 0;
  bool currently_in_num = false;

  for (int i = 0; input[i] != '\0' && result; i++) {
    if (IsNum(input[i]) || input[i] == '.') {
      currently_in_num = true;
      result = CheckDotPosition(input, i, &dots_count);
    } else if (currently_in_num && dots_count < 2) {
      dots_count = 0;
      currently_in_num = false;
    }

    if (currently_in_num && dots_count > 1) {
      result = ERROR;
    }
  }

  return result;
}

/**
 * @brief Функиця проверяет положение точки
 *
 * @param input Входная строка
 * @param index Индекс элемента в строке
 * @param dots_count Количество точек
 *
 * @details Обрабатываются следующие ситуации:
 *          - несколько точек в одном числе (например, 2.3.4 и 2..4)
 *          - точка без цифры перед ней (например, .234)
 *          - одиночная точка
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int CheckDotPosition(char *input, int index, int *dots_count) {
  if (input[index] == '.' && index != 0) {
    (*dots_count)++;

    if (index > 0 && (!IsNum(input[index - 1]) || !IsNum(input[index + 1]))) {
      return ERROR;
    }
  } else if (input[index] == '.' && index == 0) {
    return ERROR;
  }

  return OK;
}

/**
 * @brief Функция проверяет строку на корректность ввода операторов [+, -, *, /,
 * ^]
 *
 * @param input Входная строка
 *
 * @details Обрабатываются следующие ситуации:
 *          - два подряд идущих оператора
 *          - операторы /, *, ^ в начале и в конце строки
 *          - подряд идущие открывающая скобка и операторы /, *, ^
 *          - операторы + и - в конце строки
 *          - операторы перед закрывающей скобкой
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int OperatorIsValid(char *input) {
  int result = OK;

  for (size_t i = 0; input[i] != '\0' && result; i++) {
    if (strchr("+-*/^%", input[i]) && i + 1 < strlen(input) &&
        strchr("+-*/^%", input[i + 1])) {
      result = ERROR;
    } else if ((i == 0 || i == (strlen(input) - 1)) &&
               strchr("/*^", input[i])) {
      result = ERROR;
    } else if (i > 0 && input[i - 1] == '(' && (strchr("/*^", input[i]))) {
      result = ERROR;
    } else if (i == (strlen(input) - 1) && (strchr("+-", input[i]))) {
      result = ERROR;
    } else if (i > 0 && input[i] == ')' &&
               strchr("+-/*^", input[i - 1]) != NULL) {
      result = ERROR;
    }
  }

  return result;
}

/**
 * @brief Функция проверяет строку на достаточность места для записи функции
 *
 * @param input Входная строка
 * @param i Индекс символа в строке
 * @param length Длина функции
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int CheckLimBrackets(char *input, size_t i, int length) {
  int result = OK;
  if (i > strlen(input) - length) {
    result = ERROR;
  }

  return result;
}

/**
 * @brief Функция проверяет строку на корректность ввода тригонометрических
 *        функций sin(), cos(), tan(), asin(), acos(), atan()
 *
 * @param input Входная строка
 *
 * @details Обрабатываются следующие ситуации:
 *          - наличие открывающей скобки сразу после объявлении функции
 *          - наличие достаточного количества символов для записи функции и
 *            скобок
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int TrigFuncIsValid(char *input) {
  int result = OK;

  for (int i = 0; input[i] != '\0' && result; i++) {
    if (input[i] == 'a') {
      if (input[i + 4] != '(') {
        result = ERROR;
      }
      if (CheckLimBrackets(input, i, 6) == 0) {
        result = ERROR;
      }
      i += 3;
    }

    if (input[i] == 'c' || (input[i] == 't' && input[i + 1] == 'a') ||
        (input[i] == 's' && input[i] == 'i')) {
      if (input[i + 3] != '(') {
        result = ERROR;
      }
      if (CheckLimBrackets(input, i, 5) == 0) {
        result = ERROR;
      }
      i += 2;
    }
  }

  return result;
}

/**
 * @brief Функция проверяет строку на корректность ввода других
 *        функций ln(), log(), v() [= sqrt()]
 *
 * @param input Входная строка
 *
 * @details Обрабатываются следующие ситуации:
 *          - наличие открывающей скобки сразу после объявлении функции
 *          - наличие достаточного количества символов для записи функции и
 *            скобок
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int OtherFuncIsValid(char *input) {
  int result = OK;

  for (int i = 0; input[i] != '\0' && result; i++) {
    if (input[i] == 'l' && input[i + 1] == 'n') {
      if (input[i + 2] != '(') {
        result = ERROR;
      }
      if (CheckLimBrackets(input, i, 3) == 0) {
        result = ERROR;
      }
      i++;
    }

    if (input[i] == 'l' && input[i + 1] == 'o') {
      if (input[i + 3] != '(') {
        result = ERROR;
      }
      if (CheckLimBrackets(input, i, 6) == 0) {
        result = ERROR;
      }
      i += 2;
    }

    if (input[i] == 'v') {
      if (input[i + 1] != '(') {
        result = ERROR;
      }
      if (CheckLimBrackets(input, i, 4) == 0) {
        result = ERROR;
      }
      if (input[i + 2] == '-') {
        result = ERROR;
      }
    }
  }

  return result;
}

/**
 * @brief Функция проверяет строку на корректность ввода символов
 *
 * @param input Входная строка
 *
 * @details Обрабатываются следующие ситуации:
 *          - наличие символов, не участвующих в математических выражениях
 *
 * @return Возращает код результата проверки.
 *         OK - 1 - строка корректна;
 *         ERROR - 0 - строка некорректна
 */
int CharIsValid(char *input) {
  int result = OK;

  for (int i = 0; input[i] != '\0' && result; i++) {
    if (strchr("1234567890.+-/*v%^sincotalg()x", input[i]) == NULL) {
      result = ERROR;
    }
  }
  return result;
}