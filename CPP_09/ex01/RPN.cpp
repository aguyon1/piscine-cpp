#include "RPN.hpp"

static inline int isoperator(int c)
{
	return (std::string("+-*/").find(c) != std::string::npos);
}

static inline int plus(int a, int b) {return (a + b);};
static inline int minus(int a, int b) {return (a - b);}
static inline int divides(int a, int b) {if (!b) throw std::runtime_error("Division per 0"); return(a / b);}
static inline int multiplies(int a, int b) {return (a * b);}

static inline int hash(char c)
{
	return (std::string("+-*/").find(c));
}

int rpn(std::string expression)
{
	const boperator operators[4] = {plus,  minus, multiplies, divides};
	std::stack<int> operands;
	for (std::string::const_iterator cit = expression.begin(); cit != expression.end(); cit++)
	{
		if (isdigit(*cit))
		{
			operands.push(*cit - '0');
		}
		else if (isoperator(*cit))
		{
			if (operands.size() < 2)
				throw std::runtime_error("Not enough operands");
			int b = operands.top();
			operands.pop();
			int a = operands.top();
			operands.pop();
			int res = operators[hash(*cit)](a,b);
			operands.push(res);
		}
	}
	if (operands.size() != 1)
		throw std::runtime_error("Incorrect expression");
	return (operands.top());
}
