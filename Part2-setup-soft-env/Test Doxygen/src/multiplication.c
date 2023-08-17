/* ========================================================================= */
/**
 * @file multiplication.c
 * @author LearnEmbeddedSystemsWithGeorge
 * @date 2021
 */
/* ========================================================================= */

/** @defgroup Multiplication multiplication.c
 * Multiplication, denoted by the symbols × or ⋅ , is the second basic operation
 * of arithmetic. Multiplication also combines two numbers into a single number,
 * the product. The two original numbers are called the multiplier and the
 * multiplicand, mostly both are simply called factors.\n
 * @{
 */

#include "multiplication.h"

/*! \fn     multiply_a_by_b(double multiplier, double multiplicand)
    \brief  Calculate the product of two numbers.
    \param  multiplier -> first number read from the keyboard
    \param  multiplicand -> second number read from the keyboard
    \return product -> value of the product of the two numbers
*/
double multiply_a_by_b(double multiplier, double multiplicand)
{
   double product = 0;

   product = multiplier * multiplicand;

   return product;
}

/** @} */
