#include "s21_tests.h"

int main() {
  int fail = 0;

  Suite *matrix_suite[] = {
      eq_matrix_suite(),     sum_matrix_suite(),       sub_matrix_suite(),
      mult_number_suite(),   mult_matrix_suite(),      transpose_suite(),
      determinant_suite(),   calc_complements_suite(), inverse_matrix_suite(),
      create_matrix_suite(), remove_matrix_suite(),    NULL};

  for (int i = 0; matrix_suite[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *matrix_runner = srunner_create(matrix_suite[i]);

    srunner_set_fork_status(matrix_runner, CK_NOFORK);
    srunner_run_all(matrix_runner, CK_NORMAL);

    fail += srunner_ntests_failed(matrix_runner);
    srunner_free(matrix_runner);
  }
  printf("\033[35m\n~~~~~~~~~ FAILED: %d ~~~~~~~~~\n\033[0m", fail);

  return fail == 0 ? 0 : 1;
}