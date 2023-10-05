#ifndef _BRAIN_H__
# define _BRAIN_H__

#include <iostream>

class Brain {
    public:
        Brain( void );
        Brain(std::string name);
        Brain(Brain const & src);
        Brain & operator=(Brain const & rhs);
        ~Brain();

        std::string	getIdeas(  ) const;
	    // void		setIdeas( int i, std::string idea );

    protected:
        std::string _ideas[100];
};

#endif