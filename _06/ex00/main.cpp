#include "ScalarConverter.hpp"

int main( int argc, char ** argv )
{
    if ( argc != 2 ) {
        std::cout << "Usage: ./convert number" << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
    	ScalarConverter::setLiteral(argv[1]);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}