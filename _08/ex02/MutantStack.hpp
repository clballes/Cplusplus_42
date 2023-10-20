#ifndef __MUTANTSTACK__H__
#define __MUTANTSTACK__H__

#include <iostream>
#include <stack>
#include <list>
#include <deque>
#include <algorithm>
#include<iterator>

template <class T, class container = std::deque<T> >
class  MutantStack : public std::stack<T> 
{
    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack &stack)
        {
            *this = stack;
        }
        MutantStack&    operator=( const MutantStack& rhs )
        {
            std::stack< T, container >::operator=( rhs );
            return *this;
        }
        typedef typename container::iterator iterator;
        iterator begin() {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }
};

#endif