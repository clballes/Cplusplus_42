#ifndef ____BITCOINEXHANGE__H___
#define ____BITCOINEXHANGE__H___

#include <iostream>
#include <map>
#include <cmath>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdlib.h>

class BitcoinExchange
{       
        private:
                std::map<std::string, float> mapCsv;

        public:
                BitcoinExchange( std::string filename ); //charge the data.csv
                BitcoinExchange(BitcoinExchange const & src);
                BitcoinExchange & operator=(BitcoinExchange const & rhs);
                ~BitcoinExchange();

                bool    checkErrorInput(std::string const line);
                bool    checkTextInput(std::string const line);
                bool    isValidDate(int month, int day);


                void    loadInput(std::string filename);
                float   getExhangeRate(const std::string & date);
                void    print(std::string const & date, float result, float num, int badInput);

		class FailOpen : public std::exception
                {
                        public:
                                virtual const char * what() const throw();
                };


};
#endif