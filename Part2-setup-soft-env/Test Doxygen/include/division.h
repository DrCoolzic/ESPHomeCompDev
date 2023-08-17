/*
 ============================================================================
 Name        : division.h
 Author      : LearnEmbeddedSystemsWithGeorge
 Version     : 1.0
 Copyright   : n.a.
 Description : Simple arithmetic calculator in C
 ============================================================================
 */
/**
 * @file division.h
 * @author LearnEmbeddedSystemsWithGeorge
 * @date 2021
 */

#ifndef DIVISION_H_
#define DIVISION_H_

/*! \def MACRO_ZERO
    \brief Macro used to verify for division by zero.
   Used to remove magic numbers from code.
*/
#define MACRO_ZERO 0

/*! \fn     double divide_a_by_b (double divident, double divisor)
    \brief  Calculate the quotient of two numbers.
    \param  divident -> first number read from the keyboard
    \param  divisor -> second number read from the keyboard
    \return quotient -> value of the quotient of the two numbers
    \warning This function checks for division by 0.
    \brief Activity diagram: \n
    \image{inline} html divide_a_by_b.png "activity"
*/
double divide_a_by_b (double divident, double divisor);

#endif /* DIVISION_H_ */
