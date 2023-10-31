#include "ScalarConverter.hpp"

int main( int argc, char ** argv )
{
    if ( argc != 2 ) {
        std::cout << "Usage: ./convert number" << std::endl;
        return EXIT_FAILURE;
    }

    ScalarConverter c;
    try
    {
        c.setLiteral(argv[1]);
    }
    catch(ScalarConverter::OutofBounds & e)
    {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}