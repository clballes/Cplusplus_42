#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Default constructor Brain called" << std::endl;

}

Brain::Brain(Brain const & src)
{
    std::cout << "Default copy assigment Brain called" << std::endl;
    *this = src;
	return ;

}

Brain & Brain::operator=(Brain const & rhs)
{
    std::cout << "Operator overload Brain called" << std::endl;
    for(int i = 0, i < 100, i++)
    {
        _ideas[i] = rhs.getIdeas[i].();
    }
	return *this;
}

Brain::~Brain()
{
    std::cout << "Default destructor Brain called" << std::endl;
}

//get ideas
std::string	getIdeas( ) const
{
    return _ideas;
}
