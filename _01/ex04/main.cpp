/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:37:16 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:37:17 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void createNewFile(std::ifstream& inputFile, const std::string& filename, const std::string& s1, const std::string& s2);
int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        std::ifstream inputFile;
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        inputFile.open(filename);
        if (!inputFile.is_open())
        {
            std::cerr << "Failed to open the file for reading." << std::endl;
            return 1;
        }
		createNewFile(inputFile, filename, s1, s2);
        inputFile.close();
    }
    else
        return 0;
}
