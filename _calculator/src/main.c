#include "calculate/headers/polish.h"
#include "calculate/headers/validators.h"

int main() {
  char str[100] = "1.8+1.3";
  lexem_list* result_polish = ToPolish(str);
  lexem_list* current = result_polish;

  printf("Результат обратной польской нотации: ");
  while (current) {
    switch (current->lex.type) {
      case NUMBER:
        printf("%.4Lf ", current->lex.number);
        break;
      case FUNC:
        printf("%s ", current->lex.func);
        break;
      case OPEN_BR:
        printf("(");
        break;
      case CLOSE_BR:
        printf(")");
        break;
      case OPERATOR:
        printf("%c ", current->lex.operation);
        break;
      default:
        printf("UNKNOWN_TYPE ");
        break;
    }
    current = current->next;
  }
  printf("\n");

  char* result = SolvePolish(result_polish);
  printf("%s\n", result);

  char test1[100] = "3+1";
  printf("Валидация: %d\n", InsertionIsValid(test1));

  return 0;
}
