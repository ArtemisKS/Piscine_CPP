/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:57:37 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/03 13:19:11 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <Account.class.hpp>
#include <iostream>
#include <ctime>	

int			Account::_nbAccounts(0);
int			Account::_totalAmount(0);
int			Account::_totalNbDeposits(0);
int			Account::_totalNbWithdrawals(0);
int			Account::_nbCheckAmountCalls(0);

Account::Account( int initial_deposit ) : 
	_accountIndex(_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << initial_deposit
	<< ";created" << std::endl;

}

Account::~Account( void )
{
	_nbAccounts--;

	Account::_displayTimestamp();
	std::cout
	<< "index:" << _nbAccounts
	<< ";amount:" << _amount
	<< ";closed" << std::endl;

}

int			Account::getNbAccounts( void ) { return _nbAccounts; }
int			Account::getTotalAmount( void ) { return _totalAmount; }
int			Account::getNbDeposits( void ) { return _totalNbDeposits; }
int			Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

int			Account::checkAmount( void ) const {

	_nbCheckAmountCalls++;

	return _amount;
}

void		Account::_displayTimestamp( void )
{
	time_t		rawtime;
	char		buffer[25];

	time(&rawtime);
	strftime(buffer, 25, "[%Y%m%d_%H%M%S] ", localtime(&rawtime));
	std::cout << buffer;
}

void		Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void		Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit;

	_amount += deposit;
	_nbDeposits++;

	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits
	<< std::endl;
}

bool		Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount << ";withdrawal:";

	if (_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return false;
	}
	else {
		_amount -= withdrawal;
		_nbWithdrawals++;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}

	std::cout << withdrawal << ";amount:" << _amount
	<< ";nb_withdrawals:" << 1 << std::endl;

	return true;
}

void		Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}
