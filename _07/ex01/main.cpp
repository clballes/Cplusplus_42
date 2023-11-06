
#include "iter.hpp"

int main( void )
{
    int arr[] = {1, 2, 3, 4, 5};
	char arr2[] = {'a', 'b', 'b', 'e', 'f'};
    float arr3[] = {1.1f, 2.4f, 3.8f, 4.8f, 5.7f};
    // double arr4[] = {1, 2, 3, 4, 5};

    int length = 5;

    iter(arr, length, func<int>);
	std::cout << "------------------" << std::endl;
    iter(arr2, length, func<char>);
	std::cout << "------------------" << std::endl;
    iter(arr3, length, func<float>);
    return 0;
}