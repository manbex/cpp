#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <list>

class	RPN
{
	public:
		static void	calculate(std::string);

		class	badArgException: public std::exception {
			public:
				virtual const char	*what() const throw() {
					return ("bad arguments");
				}
		};

		class	divisionByZeroException: public std::exception {
			public:
				virtual const char	*what() const throw() {
					return ("division by zero");
				}
		};

	private:
		RPN();
		RPN(RPN const &);
		~RPN();
		RPN	&operator=(RPN const &);

		static void	operate(char const &, std::stack<long int, std::list<long int> > &);
};

#endif
