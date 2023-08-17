/* ========================================================================= */
/**
 * @file addition.c
 * @author LearnEmbeddedSystemsWithGeorge
 * @date 2021
 */
/* ========================================================================= */

/** @defgroup Addition addition.c
 * Addition, denoted by the symbol +, is the most basic operation of arithmetic.
 * In its simple form, addition combines two numbers, the addends or terms,
 * into a single number, the sum of the numbers (such as 2 + 2 = 4 or 3 + 5 = 8).\n
 * @{
 */

#include "addition.h"

/*! \fn     double sum_of_two_numbers(double first_number, double second_number)
    \brief  Calculate the sum of two numbers.
    \param  first_number -> first number read from the keyboard
    \param  second_number -> second number read from the keyboard
    \return sum -> value of the sum of the two numbers
*/
double sum_of_two_numbers(double first_number, double second_number)
{
   double sum = 0;

   sum = first_number + second_number;

   return sum;
}

/** @} */
