#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>

class	RPN
{
	public:
		static void	calculate(std::string);

		class	badArgException: public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("bad arguments");
				}
		};

	private:
		RPN();
		RPN(RPN const &);
		~RPN();
		RPN	&operator=(RPN const &);

		static void	operate(char const &, std::stack<int> &);
};

#endif
