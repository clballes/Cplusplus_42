#include "span.hpp"

int main()
{
//  try {
//         Span span(1000);
//         std::vector<int> numberRange(1000);
// 		// std::iota(numberRange.begin(), numberRange.end(), 0);  // Fill the vector with numbers 0 to 9
//         span.addNumber(numberRange.begin(), numberRange.end());
//         int shortest = span.shortestSpan();
//         int longest = span.longestSpan();

//         std::cout << "Shortest Span: " << shortest << std::endl;
//         std::cout << "Longest Span: " << longest << std::endl;
//     }catch(const Span::OutBounds & e)
//     {
//         std::cout << "Exception max min: " << e.what() << std::endl;
//     }
//      catch(const Span::NoMoreNums & e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     return 0;
// }

    Span sp = Span(5);
    // Calling addNumber with iterators
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try
    {
        sp.addNumber(10);
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11); exception cannot add more nums
        std::cout << "Short Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Long Span: "<< sp.longestSpan() << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}