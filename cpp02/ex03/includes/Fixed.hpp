#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &);
		Fixed(int const);
		Fixed(float const);
		Fixed &operator=(Fixed const &);
		Fixed &operator=(float const);
		Fixed operator+(Fixed const &) const;
		Fixed operator-(Fixed const &) const;
		Fixed operator*(Fixed const &) const;
		Fixed operator/(Fixed const &) const;
		bool operator>(Fixed const &) const;
		bool operator<(Fixed const &) const;
		bool operator>=(Fixed const &) const;
		bool operator<=(Fixed const &) const;
		bool operator==(Fixed const &) const;
		bool operator!=(Fixed const &) const;
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const);
		float	toFloat() const;
		int		toInt() const;

		static Fixed	min(Fixed &, Fixed &);
		static Fixed	max(Fixed &, Fixed &);
		static Fixed	min(Fixed const &, Fixed const &);
		static Fixed	max(Fixed const &, Fixed const &);

	private:
		int					_value;
		static int const	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif
