#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <bitcoin_data_file>" << std::endl;
        return 1;
    }
    BitcoinExchange bitcoin("data.csv");
    try
    {
        bitcoin.loadInput(argv[1]);
    }
    catch(const BitcoinExchange::ErrorSyntax & e)
    {
        std::cout << "Error in input text:" << e.what() << std::endl;
    }
     catch(const BitcoinExchange::ErrorChar & e)
    {
        std::cout << "Error input text: " << e.what() << std::endl;
    }
    return 0;
}
