#include "headers/polish.h"

/**
 * @brief Функция определения цифры
 *
 * @param elem Входной символ
 *
 * @return Возращает код результата проверки. 1 - символ является числом; 0 -
 * символ не является числом
 */
int IsNum(char elem) {
  int result = 0;
  if (strchr("0123456789", elem)) {
    result = 1;
  } else {
    result = 0;
  }

  return result;
}