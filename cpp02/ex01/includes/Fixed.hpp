#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &);
		Fixed(int const n);
		Fixed(float const n);
		Fixed &operator=(Fixed const &cpy);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					_value;
		static int const	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif
