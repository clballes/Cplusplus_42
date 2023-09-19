#include <iostream>

int main(int argc, char **argv)
{
    int i;
    char c;
    int j = 1;

    if (argc == 1)
    {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    else
    {
        while(argv[j])
        {
            i = 0;
            c = ' ';
            std::cout << c;
            while (argv[j][i])
            {
                c = std::toupper(argv[j][i++]);
                std::cout << c;
            }
            j++;
        }
        std::cout << std::endl;
    }
    return (0);
}
