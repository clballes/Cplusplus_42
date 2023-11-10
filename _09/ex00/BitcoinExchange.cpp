#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( std::string filename )
{
    std::cout << "Default Constructor Bitcoin Exchange Called" << std::endl;
    std::ifstream dataCsv(filename);
	if (!dataCsv.is_open())
	{
		throw FailOpen();
	}
	else
	{
		std::string line;
		while (getline(dataCsv, line))
		{
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

    size_t first = line.find_first_of("-");
    size_t last = line.find_last_of("-");

    if ((last == expectedLastDashPosition || last == 13 )&& first == expectedFirstDashPosition && pipe == expectedPipePosition) {
        for (size_t i = 0; i < line.length(); ++i) {
            if (std::isalpha(line[i])) {
                return false;
                // throw ErrorChar();
            }
        }
    }else if(pipe == 0)
        return true;
    else {
        return false;
            // throw ErrorSyntax();
    }
    return true;
}

void BitcoinExchange::print(std::string const & date, float result, float num, int badInput)
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
    else if(badInput == 0 )
    {
        std::cout << "Error: bad input"<< " => " << date << std::endl;
        return ;
    }
    else if(isnan(num))
    {
        std::cout << "Error: empty value" << " => " << date << std::endl;
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

bool BitcoinExchange::checkTextInput(std::string const line)
{
    size_t first = line.find_first_of("-");
    //parsing year 
    std::string str_year = line.substr(0, first);
    const char* c_str_year = str_year.c_str();
    int year = atoi(c_str_year);
    if (year > 2023 || year < 2009)
    {
        return false;
    }

    //parsing months
    std::string str_month = line.substr(first + 1, 2);
    const char* c_str_month = str_month.c_str();
    int month = atoi(c_str_month);
    if (month > 12 || month < 1)
    {
        return false;
    }

    //parsing dates
    std::string str_day = line.substr(first + 4, 2);
    const char* c_str_day = str_day.c_str();
    int day = atoi(c_str_day);
    if (day > 31 || day < 1)
    {
        return false;
    }
    return true;
}

void    BitcoinExchange::loadInput(std::string filename)
{
    std::ifstream btcFile(filename);
    std::string line;
    //check if its empty 
    while (getline(btcFile, line) == 0)
    {
        std::cerr << "Error: empty file" << std::endl;
        return ;
    }
    btcFile.clear();
    btcFile.seekg(0, std::ios::beg);

    //continue checking
    getline(btcFile, line);
    if (getline(btcFile, line) == 0)
    {
        std::cerr << "Error: empty file" << std::endl;
        return ;
    }

    btcFile.clear();
    btcFile.seekg(0, std::ios::beg);
    //check error numbers & do exchange & print
    getline(btcFile, line);
    while (getline(btcFile, line))
    {
        if (!line.empty())
        {
            std::istringstream iss(line);
            std::string date;
            float number;
            int badInput = BitcoinExchange::checkErrorInput(line);
            int badInput2 = BitcoinExchange::checkTextInput(line);
            if (badInput == 0 || badInput2 == 0)
                badInput = 0;
            if (getline(iss, date, '|') && iss >> number)
            {
                float result = getExhangeRate(date) * number; //li passo la date x cada line
                print(date, result, number, badInput);
            }
            else
            {
                number = std::numeric_limits<float>::quiet_NaN(); //poso el number a Nan to get the error
                print(date, 0, number, badInput);
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
    return "Error in input text: wrong syntax year-month-day.";
}

const char * BitcoinExchange::ErrorChar::what() const throw()
{
    return "Error input text: not numeric values.";
}

const char * BitcoinExchange::FailOpen::what() const throw()
{
    return "Error: Cannot open the file, file not found.";
}
