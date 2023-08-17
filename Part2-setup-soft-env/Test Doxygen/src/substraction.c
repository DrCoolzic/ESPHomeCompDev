/* ========================================================================= */
/**
 * @file substraction.c
 * @author LearnEmbeddedSystemsWithGeorge
 * @date 2021
 */
/* ========================================================================= */

/** @defgroup Substraction substraction.c
 * Subtraction, denoted by the symbol −, is the inverse operation to addition.
 * Subtraction finds the difference between two numbers, the minuend minus
 * the subtrahend: D = M − S. Resorting to the previously established addition,
 * this is to say that the difference is the number that, when added to the subtrahend,
 * results in the minuend: D + S = M.\n
 * @{
 */

#include "substraction.h"

/*! \fn     difference_of_two_numbers(double minuend, double subtrahend)
    \brief  Calculate the difference of two numbers.
    \param  minuend -> first number read from the keyboard
    \param  subtrahend -> second number read from the keyboard
    \return difference -> value of the difference of the two numbers
*/
double difference_of_two_numbers(double minuend, double subtrahend)
{
   double difference = 0;

   difference = minuend - subtrahend;

   return difference;
}

/** @} */
