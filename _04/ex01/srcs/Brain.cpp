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
    for(int i = 0; i < 10; i++)
    {
        this->_ideas[i] = rhs.getIdeas(i);
    }
	return *this;
}

Brain::~Brain()
{
    std::cout << "Default destructor Brain called" << std::endl;
}

//get ideas
std::string	Brain::getIdeas(int idx) const
{
    return this->_ideas[idx];
}

//set ideas
void		Brain::setIdeas( int i, std::string idea )
{
    this->_ideas[i] = idea;
}

