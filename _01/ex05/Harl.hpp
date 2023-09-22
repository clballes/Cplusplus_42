#include <iostream>
#include <string>
#include <map> // Include the map header

#ifndef __HARL_H__
#define __HARL_H__

class Harl {
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void);
        typedef void (Harl::*MemberFunction)();
        std::map<std::string, MemberFunction> levelToFunction;
    public:
    // Map complaint levels to member function pointers
        Harl();
        void complain( std::string level );
};
#endif