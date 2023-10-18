
#include "Array.hpp"

int main( void )
{
	Array<int> originalArray(5);
    for (int i = 0; i < 5; ++i) {
        originalArray[i] = i * 10;
    }

    // Use the copy constructor to create a new array with the same content
    Array<int> copiedArray(originalArray);

    // Use the assignment operator to copy the content of one array to another
    Array<int> assignedArray;
    assignedArray = originalArray;

    // Display the content of the arrays
    std::cout << "Original Array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << originalArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied Array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Assigned Array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
	// Array<int> intArray(2); // Instantiate an Array of integers with a size of 2
	//  try {
    //     intArray[0] = 42;
    //     intArray[1] = 73;
    //     intArray[2] = 99;
    // } catch ( Array< int >::OutOfBoundsException& e ) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
	// //try copy array overlaod
	// Array<int> intArrcopy(intArray);

	// std::cout << "hey "<< intArrcopy.getSize() << std::endl;
    return 0;
}