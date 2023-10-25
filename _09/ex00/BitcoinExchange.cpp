#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( std::string filename )
{
    std::cout << "Default constructor bitcoin exchange called" << std::endl;
    std::ifstream dataCsv(filename);
    std::string line;
    while (getline(dataCsv, line)) {
        if (line != "date,exchange_rate") {
            std::istringstream iss(line);
            std::string date;
            float number;

            if (getline(iss, date, ',') && iss >> number) {
                this->mapCsv[date] = number;
            }
        }
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    *this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    (void)rhs;
    std::cout << "default destructor bitcoin exchange called" << std::endl;
    return *this;
}

bool BitcoinExchange::checkErrorInput(std::string const line)
{
    const size_t expectedPipePosition = 11;
    const size_t expectedFirstDashPosition = 4;
    const size_t expectedLastDashPosition = 7;

    size_t pipe = line.find("|");
    if (pipe == std::string::npos) {
        pipe = 0;
    }

    if (line == "date | value") {
        return true;
    }

    size_t first = line.find_first_of("-");
    size_t last = line.find_last_of("-");

    if ((last == expectedLastDashPosition || last == 13 )&& first == expectedFirstDashPosition && pipe == expectedPipePosition) {
        for (size_t i = 0; i < line.length(); ++i) {
            if (std::isalpha(line[i])) {
                throw ErrorChar();
            }
        }
    }else if(pipe == 0)
        return true;
    else {
            throw ErrorSyntax();
    }
    return true;
}

void BitcoinExchange::print(std::string const & date, float result, float num)
{
    if (num < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return ;
    }
    else if (num > 1000)
    {
        std::cout << "Error: too large number." << std::endl;
        return ;
    }
    else if(isnan(num))
    {
        std::cout << "Error: bad input"<< " => " << date << std::endl;
        return ;
    }
    std::cout << date << " => " << num << " = " << result << std::endl;
}

float    BitcoinExchange::getExhangeRate(const std::string & date)
{
    std::map<std::string, float>::iterator it = this->mapCsv.lower_bound(date);
    if (date == it->first)
    {
        return it->second;
    }
    if (!this->mapCsv.empty() && it != this->mapCsv.end()) {
		--it;
        return it->second;
	}
    return -1;
}

void    BitcoinExchange::loadInput(std::string filename)
{
    std::ifstream btcFile(filename);
    std::string line;

    while (getline(btcFile, line)) {
        BitcoinExchange::checkErrorInput(line);
    }
    btcFile.clear();
    btcFile.seekg(0, std::ios::beg);
    while (getline(btcFile, line))
    {
        if (line != "date | value")
        {
            std::istringstream iss(line);
            std::string date;
            float number;

            if (getline(iss, date, '|') && iss >> number)
            {
                float result = getExhangeRate(date) * number; //li passo la date x cada line
                print(date, result, number);
            }
            else
            {
                number = std::numeric_limits<float>::quiet_NaN(); //poso el number a Nan to get the error
                print(date, 0, number);
            }
        }
    }
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Default destructor bitcoin exchange called" << std::endl;
}

const char * BitcoinExchange::ErrorSyntax::what() const throw()
{
    return " wrong syntax year-month-day.";
}

const char * BitcoinExchange::ErrorChar::what() const throw()
{
    return " not numeric values.";
}