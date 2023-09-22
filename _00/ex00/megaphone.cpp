/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:02:29 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 13:02:30 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
