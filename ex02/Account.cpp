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
	_displayTimestamp();	
	std::cout << "index:" << _accountIndex << "amount:" <<  initial_dep << "created" << std::endl;
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

    // Print the formatted time
    std::cout << "[" << timeString << "] ";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << "amount:" <<  _amount << "closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << "total:" << _totalAmount << "deposits:" << _totalNbDeposits << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << " amount:" <<  _amount << " deposits:" << _nbDeposits << " withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << "p_amount:" <<  _accountIndex << "_amount:" <<  _amount << "deposit:" << deposit << "nb_deposits:" << _nbDeposits << std::endl;
// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	// poder el wir=tdhralwal es refused de una
	std::cout << "index:" << _accountIndex << "p_amount:" <<  _amount << "amount:" << "withdrawals" << withdrawal << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	std::cout << "amount in check amount:" <<  _amount << std::endl;
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