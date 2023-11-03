#include "Serialization.hpp"
#include "Data.hpp"

int	main()
{
	Data data;
	data.value = 42;
	
    uintptr_t serializedPtr = Serialization::serialize(&data);

    // Deserialize the pointer
    Data* deserializedPtr = Serialization::deserialize(serializedPtr);

    // Check if deserialized pointer is equal to the original pointer
    if (deserializedPtr == &data) {
        std::cout << "Serialization and deserialization successful!\n";
        std::cout << "Original Data value: " << data.value << "\n";
    } else {
        std::cout << "Serialization and deserialization failed!\n";
    }

    return 0;

}