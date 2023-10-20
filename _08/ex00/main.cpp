#include "easyfind.hpp"
#include <vector> 

int main()
{
    std::vector<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.push_back(4);
    myVec.push_back(5);
    try
    {
        easyfind(myVec, 3);
        easyfind(myVec, 8);
    }
    catch(const NothingFound & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}