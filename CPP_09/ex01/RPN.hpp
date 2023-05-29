#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>

typedef int(*boperator)(int, int);

int rpn(std::string);

#endif
