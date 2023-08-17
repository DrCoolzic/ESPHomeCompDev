/* ========================================================================= */
/**
 * @file main.c
 * @author LearnEmbeddedSystemsWithGeorge
 * @date 2021
 * @brief Simple arithmetic calculator in C
*/
/* ========================================================================= */

/** @defgroup Calculator Calculator
 * Main file of the project.\n
 * @{
 */

/* ========================================================================= */
/* Include files section                                                     */
/* ========================================================================= */
// Standard C libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// User header files
#include "main.h"
#include "addition.h"
#include "division.h"
#include "multiplication.h"
#include "substraction.h"

/* ========================================================================= */
/* Global variables section                                                  */
/* ========================================================================= */
/*! \var St_ArithmeticResults g_Results
    \brief Global variable used to store results of arithmetic operations.
*/
St_ArithmeticResults g_Results = {0.0, 0.0, 0.0, 0.0};

/* ========================================================================= */
/* Program section                                                           */
/* ========================================================================= */
/*! \fn int main(void)
 *  \brief Main function.
 *  \param void
 *  \return EXIT_SUCCESS
 *  \note Call this function first, this is the entry point of application
 *  \code
 *  main();
 *  \endcode
 */
int main(void)
{
   EnumOperators operator     = en_addition_character; //'+'
   double first               = 0.0;
   double second              = 0.0;

   printf("Enter an operator (+, -, *,): \n");

   scanf("%c", (char *)&operator);

   //ToDo do while loop for multiple tries
   if((en_addition_character != operator) &&
         (en_substraction_character != operator) &&
         (en_multiplication_character != operator) &&
         (en_division_character != operator))
   {
      printf("Operator is not correct! Program will exit in 3 seconds.\n");
#if ENABLE_DEBUG == 1
      printf("Value of operator: %d\n", operator);
#endif
   }
   else
   {
#if ENABLE_DEBUG == 1
      printf("Value of operator: %d\n", operator);
#endif
      printf("Enter two operands separated by a space, floating values are accepted (e.g. 1.5 2.0): \n");

      scanf("%lf %lf", &first, &second);

      switch (operator)
      {
      case '+':
         printf("Result: %.1lf\n", sum_of_two_numbers(first, second));
         break;
      case '-':
         printf("Result: %.1lf\n", difference_of_two_numbers(first, second));
         break;
      case '*':
         printf("Result: %.1lf\n", multiply_a_by_b(first, second));
         break;
      case '/':
         printf("Result: %.1lf\n", divide_a_by_b(first, second));
         break;
      default:
         // operator doesn't match any case constant
         printf("ERROR - invalid switch case, branch shall not be reached.\n");
      }
      printf("Program will exit in 3 seconds.\n");
   }

   sleep(3); // sleep for 3 seconds

   return EXIT_SUCCESS;
}

/** @} */
