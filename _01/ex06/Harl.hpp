#include <iostream>
#include <string>
#include <map> 

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
        Harl();
        void    cutString(std::string& str);
        void    switchCase();
        void complain( std::string level );
};
#endif