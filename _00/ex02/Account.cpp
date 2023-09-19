/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clballes <clballes@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:17:00 by clballes          #+#    #+#             */
/*   Updated: 2023/09/18 18:17:02 by clballes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_dep)
{
    _accountIndex = getNbAccounts(); // Get the current number of accounts as the index
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << " amount:" <<  initial_dep << " created" << std::endl;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_dep;
    // Update the static variables to track the total number of accounts and total amount
    _nbAccounts++;
    _totalAmount += initial_dep;
}

void Account::_displayTimestamp(void)
{
    // Get the current time
    std::time_t currentTime;
    std::tm *timeInfo;
    char timeString[20];

    std::time(&currentTime); // Get current time
    timeInfo = std::localtime(&currentTime); // Convert to local time

    // Format the current time as a string
    std::strftime(timeString, sizeof(timeString), "%Y%m%d_%H%M%S", timeInfo);
    std::cout << "[" << timeString << "] ";
}

Account::~Account(void)
{
    int currentIndex = _accountIndex; // Store the current index in a local variable

    _displayTimestamp();
    std::cout << "index:" << currentIndex << " amount:" <<  _amount << " closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << " total:" << _totalAmount << " deposits:" << _totalNbDeposits << " withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << " amount:" <<  _amount << " deposits:" << _nbDeposits << " withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	int result = _amount + deposit;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << " p_amount:" <<  _amount << " deposit:" << deposit << " _amount:" <<  result << " nb_deposits:" << _nbDeposits << std::endl;
	_amount = result;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	int result = _amount - withdrawal;
	if (result < 0)
	{
		std::cout << "index:" << _accountIndex << " p_amount:" << _amount << " withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;	
		_nbWithdrawals++;
		std::cout << "index:" << _accountIndex << " p_amount:" << _amount << " withdrawal:" << withdrawal << " amount:" << result << " nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount = result;
		return (true);
	}
}

int	Account::checkAmount( void ) const
{
	return _amount;
}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}