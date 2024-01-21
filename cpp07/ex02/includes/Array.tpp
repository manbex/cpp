#ifndef ARRAY_TPP
# define ARRAY_TPP

template<typename T>
Array<T>::Array(): _array(new T[0]), _size(0)
{}

template<typename T>
Array<T>::Array(unsigned int const &n)
{
	this->_array = new T[n]();
	this->_size = n;
}

template<typename T>
Array<T>::Array(Array const &cpy)
{
	*this = cpy;
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template<typename T>
Array<T>	&Array<T>::operator=(Array const &cpy)
{
	delete[] this->_array;
	this->_array = new T[cpy._size];
	this->_size = cpy._size;
	for (unsigned int i = 0; i < cpy._size; i++)
	{
		this->_array[i] = cpy._array[i];
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int const &i)
{
	if (i >= this->_size)
		throw Array<T>::InvalidIndexException();
	return this->_array[i];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
class Array<T>::InvalidIndexException: public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Index outside of array");
		}
};

#endif
