/* InvalidInputException.h - a custom error for handling invalid inputs
 * Author:     Richard Zarate
 * Project:    Final Project
 * Description: Custom error for handling invalid inputs.
 * Algorithm:
 *     1.  Custom error class that uses parent constructor
 */
#include <stdexcept>
#include <limits>

#ifndef INVALID_INPUT_EXCEPTION_H
#define INVALID_INPUT_EXCEPTION_H

using namespace std;

class InvalidInputException : public runtime_error {
public:
    InvalidInputException() : runtime_error("Invalid input. Expected an integer. Please try again!") {}
};

#endif