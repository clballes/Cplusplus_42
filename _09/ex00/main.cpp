#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <bitcoin_data_file>" << std::endl;
        return 1;
    }
    try
    {
    	BitcoinExchange bitcoin("data.csv");
        bitcoin.loadInput(argv[1]);
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}