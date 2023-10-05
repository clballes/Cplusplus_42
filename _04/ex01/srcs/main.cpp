
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return 0;
}






//     std::string arr[100];
//     idx = 0;
//     while(idx < 100)
//     {   
//         i->Brain[idx];
//         if (idx == 49)
//         {
//             while (idx < 100)
//                 j->Brain.[idx++];
//         }
//         i++;
//     }
//     // delete j;//should not create a leak
//     // delete i;
//     return 0;
// }