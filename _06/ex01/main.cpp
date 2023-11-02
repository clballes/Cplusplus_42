#include "Serialization.hpp"
#include "Data.hpp"

int	main()
{
	Data originalData(42);
	Serialization a;
	
    uintptr_t serializedPtr = a.serialize(&originalData);

    // Deserialize the pointer
    Data* deserializedPtr = a.deserialize(serializedPtr);

    // Check if deserialized pointer is equal to the original pointer
    if (deserializedPtr == &originalData) {
        std::cout << "Serialization and deserialization successful!\n";
        std::cout << "Original Data value: " << originalData.value << "\n";
    } else {
        std::cout << "Serialization and deserialization failed!\n";
    }

    return 0;

}