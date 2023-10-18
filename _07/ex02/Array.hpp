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
			std::cout << "Default constructor unsigned int array" << n << std::endl;
			this->_arr = new T();
			this->_len = n;
		}
		Array(Array const & src)
		{
			*this = src;
		}
		Array & operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				delete [] this->_arr;
				_arr = new T[rhs.getSize()];
				_len = rhs._len;
			}
			for ( unsigned int i( 0 ); i < _len; i++ )
                _arr[i] = rhs._arr[i];
        	return *this;
		}
		~Array()
		{
			delete [] _arr;
			std::cout << "Default destructor array" << std::endl;
		}
		void getSize( void )
		{
			return this->_len;
		}
	private:
		T *		_arr;
		size_t	_len;
};

#endif