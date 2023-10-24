#ifndef ____BITCOINEXHANGE__H___
#define ____BITCOINEXHANGE__H___

#include <iostream>
#include <map>
#include <cmath>
#include <fstream>
#include <sstream>
#include <exception>

class BitcoinExchange
{       
        private:
            std::map<std::string, float> mapCsv;

        public:
                BitcoinExchange( std::string filename ); //charge the csvmap
                BitcoinExchange(BitcoinExchange const & src);
                BitcoinExchange & operator=(BitcoinExchange const & rhs);
                ~BitcoinExchange();

                //member functions
                bool    checkErrorInput(std::string const line);
                void    loadInput(std::string filename);
                float   getExhangeRate(const std::string & date);
                void    print(std::string const & date, float result, float num);
                class ErrorSyntax : public std::exception
                {
                        public:
                                virtual const char *what() const throw();
                };
                class ErrorChar : public std::exception
                {
                        public:
                                virtual const char * what() const throw();
                };

};
#endif