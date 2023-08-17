/* ========================================================================= */
/**
 * @file division.c
 * @author LearnEmbeddedSystemsWithGeorge
 * @date 2021
 */
/* ========================================================================= */

/** @defgroup Division division.c
 * Division, denoted by the symbols ÷ or /, is essentially the inverse operation
 * to multiplication. Division finds the quotient of two numbers, the dividend
 * divided by the divisor. Any dividend divided by zero is undefined.
 * For distinct positive numbers, if the dividend is larger than the divisor,
 * the quotient is greater than 1, otherwise it is less than 1 (a similar rule
 * applies for negative numbers). The quotient multiplied by the divisor always
 * yields the dividend.\n
 * @{
 */

#include "division.h"

/*! \fn     double divide_a_by_b (double divident, double divisor)
    \brief  Calculate the quotient of two numbers.
    \param  divident -> first number read from the keyboard
    \param  divisor -> second number read from the keyboard
    \return quotient -> value of the quotient of the two numbers
    \warning This function checks for division by 0.
    \brief Activity diagram: \n
    \image{inline} html divide_a_by_b.png "activity"
*/
double divide_a_by_b (double divident, double divisor)
{
   double quotient = 0;

   if(MACRO_ZERO != divisor)
   {
      quotient = divident / divisor;
   }
   else
   {
      quotient = 0;
   }

   return quotient;
}

/** @} */
