/*
 ============================================================================
 Name        : main.h
 Author      : LearnEmbeddedSystemsWithGeorge
 Version     : 1.0
 Copyright   : n.a.
 Description : Simple arithmetic calculator in C
 ============================================================================
 */
/**
 * @file main.h
 * @author LearnEmbeddedSystemsWithGeorge
 * @date 2021
 */

#ifndef MAIN_H_
#define MAIN_H_

/*! \def ENABLE_DEBUG
    \brief Macro used to enable code for debugging.
   Use 0 to disable debug, and 1 to enable debug. Default value: 0.
 */
#define ENABLE_DEBUG 0


/*! \enum EnumOperators
    \brief An enum type based on http://www.asciitable.com/.
*/
typedef enum
{
   en_addition_character = 43u,   /**< enum value 43, ASCII character '+' */
   en_substraction_character = 45u, /**< enum value 45, ASCII character '-' */
   en_multiplication_character = 42u, /**< enum value 42, ASCII character '*' */
   en_division_character = 47u /**< enum value 47, ASCII character '/' */
}EnumOperators;

/*! \struct St_ArithmeticResults
    \brief A structure used to store the results from the arithmetic operation.

    Test purpose only.
 */
typedef struct {
   double sum;      /**< Sum of two numbers */
   double difference;    /**< Difference of two numbers */

   /** Product of two numbers */
   double product;

   /** Quotient of two numbers */
   double quotient;
}St_ArithmeticResults;

#endif /* MAIN_H_ */
