#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <math.h>

#include "../calculate/headers/polish.h"
#include "../calculate/headers/validators.h"

Suite *InputIsValid();
Suite *InputIsNotValid();
Suite *CalculationSuite();

#endif