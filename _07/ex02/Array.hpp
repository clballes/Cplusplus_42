#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#pragma once
#include <iostream>

template<typename T>

class Array {
	public: 
		Array()
		{
			std::cout << "Default constructor array" << std::endl;
			this->_arr = new T();
			this->_len = 0;
		}
		Array(unsigned int n)
		{
			std::cout << "Default constructor unsigned int array len: " << n << std::endl;
			this->_arr = new T[n];
			this->_len = n;
		}
		Array(Array const & src)
		{
			std::cout << "copy constructor" << std::endl;
			*this = src;
		}
		Array & operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				std::cout << "operator overload constructor" << std::endl;
				delete [] this->_arr;
				this->_arr = new T[rhs.getSize()];				
				this->_len = rhs._len;
			}
			for ( unsigned int i = 0; i < this->_len; i++ )
                this->_arr[i] = rhs._arr[i];
        	return *this;
		}
		T& operator[](unsigned int index) const
		{
			if (index >= _len || index < 0) 
    		{
				throw OutOfBoundsException();
			}
				return _arr[index];
    	}
		~Array()
		{
			delete [] _arr;
			std::cout << "Default destructor array" << std::endl;
		}
		size_t getSize( void ) const
		{
			return this->_len;
		}

		class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Index is out of bounds";}
    };

	private:
		T *				_arr;
		unsigned int	_len;
};

#endif