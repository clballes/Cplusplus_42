/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:38:08 by clballes          #+#    #+#             */
/*   Updated: 2023/09/22 17:38:09 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void createNewFile(std::ifstream& inputFile, const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ofstream Ouputfile(filename + ".replace");
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string modifiedLine;
		size_t pos = 0;
		while (pos < line.length()) {
			size_t foundPos = line.find(s1, pos);
			if (foundPos == std::string::npos) {
				modifiedLine += line.substr(pos);
				break;
			}
			modifiedLine += line.substr(pos, foundPos - pos);
			modifiedLine += s2;
			pos = foundPos + s1.length();
			}
			Ouputfile << modifiedLine << '\n';
		}
}