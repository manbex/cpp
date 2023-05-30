#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &);
		Fixed &operator=(Fixed const &cpy);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static int const	_bits;
};

#endif
