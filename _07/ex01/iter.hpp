#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <iostream>

template< typename T>
void func(T &adress)
{
	std::cout << "Valor dintre array: " << adress << std::endl;
}

template< typename T>
void iter(T *adress, size_t const &len, void (*func)(T&))
{
	for (size_t i = 0; i < len; i++)
	{
		func(adress[i]);
	}
}


// con const
// template< typename T>
// void iter(T *adress, size_t const &len, void (*func)(const T&))
// {
// 	for (size_t i = 0; i < len; i++)
// 	{
// 		func(adress[i]);
// 	}
// }

// template< typename T>
// void func(T const &adress)
// {
// 	std::cout << "Valor dintre array: " << adress << std::endl;
// }

#endif