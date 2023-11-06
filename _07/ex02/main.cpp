
#include "Array.hpp"

int main( void )
{
	Array<int> originalArray(5); 
    for (int i = 0; i < 5; ++i)
    {
        originalArray[i] = i * 10;
        std::cout << originalArray[i] << " ";
    }

    Array<int> copiedArray(originalArray); //check copy array
    std::cout << "Copied Array: ";
    for (int i = 0; i < 5; ++i)
	{
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    // // Use the assignment operator to copy the content of one array to another
    Array<int> assignedArray;
    assignedArray = originalArray;

    std::cout << "Assigned Array using operator: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    // ----- THROW EXCEPTION -------
	Array<int> intArray(2);
	 try {
        intArray[0] = 42;
        intArray[1] = 73;
        // intArray[2] = 99;
    } catch ( Array< int >::OutOfBoundsException& e ) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}