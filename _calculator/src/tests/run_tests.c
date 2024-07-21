#include "tests.h"

int main() {
  int fail = 0;
  Suite *calculator_suite[] = {InputIsValid(), InputIsNotValid(),
                               CalculationSuite(), NULL};

  for (int i = 0; calculator_suite[i] != NULL; i++) { // (&& failed == 0)
    SRunner *calculator_runner = srunner_create(calculator_suite[i]);

    srunner_set_fork_status(calculator_runner, CK_NOFORK);
    srunner_run_all(calculator_runner, CK_NORMAL);

    fail += srunner_ntests_failed(calculator_runner);
    srunner_free(calculator_runner);
  }
  printf("\033[35m\n~~~~~~~~~ FAILED: %d ~~~~~~~~~\n\033[0m", fail);

  return fail == 0 ? 0 : 1;
}