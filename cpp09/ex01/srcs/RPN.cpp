#include "RPN.hpp"

static int	isInSet(char c, std::string set)
{
	size_t	size = set.size();

	for (size_t i = 0; i < size; i++) {
		if (c == set[i]) {
			return (1);
		}
	}
	return (0);
}

void	RPN::operate(char const &c, std::stack<long int, std::list<long int> > &stack)
{
	long int	n1;
	long int	n2;
	long int	res;

	if (stack.size() < 2) {
		throw (RPN::badArgException());
	}

	n2 = stack.top();
	stack.pop();
	n1 = stack.top();
	stack.pop();

	switch (c) {
		case '+':
			res = n1 + n2;
			break ;
		case '-':
			res = n1 - n2;
			break ;
		case '*':
			res = n1 * n2;
			break ;
		case '/':
		{
			if (n2 == 0)
				throw (RPN::divisionByZeroException());
			res = n1 / n2;
			break ;
		}
	}
	stack.push(res);
}

static long int	charToInt(char const c)
{
	return (c - '0');
}

void	RPN::calculate(std::string str)
{
	std::stack<long int, std::list<long int> >	stack;
	std::string		s;
	size_t			pos = 0;

	while (pos != std::string::npos)
	{
		pos = str.find(" ");
		if (pos != std::string::npos)
		{
			s = str.substr(0, pos);
			str.erase(0, pos + 1);
		}
		else {
			s = str;
		}
		if (s.size() != 1 || !isInSet(s[0], "0123456789+-*/")) {
			throw (RPN::badArgException());
		}
		if (isInSet(s[0], "0123456789")) {
			stack.push(charToInt(s[0]));
		}
		else {
			RPN::operate(s[0], stack);
		}
	}
	if (stack.size() != 1) {
		throw (RPN::badArgException());
	}
	std::cout << stack.top() << std::endl;
}
