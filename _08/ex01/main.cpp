#include "span.hpp"
#include <vector> 
#include <list> 

int main()
{
 try {
        Span span(10);
        std::vector<int> numberRange(10);
        span.addNumber(numberRange.begin(), numberRange.end());
        //  for(int i = 0; i < 10; i++)
        // {
        //     std::cout << span << std::endl;
        // }
        // for (int i = 0; i < 10000; ++i) {
        //     span.addNumber(i);
        // }
        // int shortest = span.shortestSpan();
        // int longest = span.longestSpan();

        // std::cout << "Shortest Span: " << shortest << std::endl;
        // std::cout << "Longest Span: " << longest << std::endl;
    }catch(const Span::OutBounds & e)
    {
        std::cout << "Exception max min: " << e.what() << std::endl;
    }
     catch(const Span::NoMoreNums & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

    // Span sp = Span(5);
    // // Calling addNumber with iterators
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    // try
    // {
    //     sp.addNumber(10);
    //     // sp.addNumber(6);
    //     // sp.addNumber(3);
    //     // sp.addNumber(17);
    //     // sp.addNumber(9);
    //     // sp.addNumber(11); exception cannot add more nums
    //     std::cout << sp.shortestSpan() << std::endl;
    //     std::cout << sp.longestSpan() << std::endl;
    // }
    // catch(const Span::OutBounds & e)
    // {
    //     std::cout << "Exception max min: " << e.what() << std::endl;
    // }
    //  catch(const Span::NoMoreNums & e)
    // {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }
//     return 0;
// }