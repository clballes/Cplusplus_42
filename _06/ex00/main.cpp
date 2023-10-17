#include "ScalarConverter.hpp"

int main( int argc, char ** argv )
{
    if ( argc != 2 ) {
        std::cout << "Usage: ./convert number" << std::endl;
        return EXIT_FAILURE;
    }

    ScalarConverter c;
    c.setLiteral(argv[1]);
    // c.convert();

        // std::cout << c;
    return EXIT_SUCCESS;
}