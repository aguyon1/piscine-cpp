/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:30:18 by aguyon            #+#    #+#             */
/*   Updated: 2023/04/17 23:48:29 by aguyon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <sstream>

struct s_time
{
	std::string hour;
	std::string minute;
	std::string second;
};

struct s_date
{
	std::string year;
	std::string month;
	std::string day;
};

struct s_timestamp
{
	struct s_time time;
	struct s_date date;
};

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;
	std::cout << " "
			  << "index:" <<_accountIndex
			  << ";amount:" <<_amount
			  << ";created"
			  << std::endl;
	return;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " "
			  << "index:" <<_accountIndex
			  << ";amount:" <<_amount
			  << ";closed"
			  << std::endl;
	Account::_nbAccounts -= 1;
	return;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " "
			  << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals()
			  << std::endl;
	return;
}

void Account::makeDeposit(int deposit)
{
	const int p_amount = _amount;

	_nbDeposits++;
	Account::_totalNbDeposits += 1;
	_amount += deposit;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " "
			  << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	const int p_amount = _amount;

	_displayTimestamp();
	std::cout << " "
			  << "index:" << _accountIndex
			  << ";p_amount:" << p_amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	Account::_totalNbWithdrawals += 1;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	return(_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " "
			  << "index:" <<_accountIndex
			  << ";amount:" <<_amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
	return;
}

static struct s_time getTime(void)
{
	struct s_time time = {};
	std::istringstream iss(__TIME__);

	std::getline(iss, time.hour, ':');
	std::getline(iss, time.minute, ':');
	std::getline(iss, time.second);
	return (time);
}

static int monthToInt(const std::string& month)
{
	const std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	for (int i = 0; i < 12; i++)
		if (month.compare(months[i]) == 0)
			return (i + 1);
	return (-1);
}

static struct s_date getDate(void)
{
	struct s_date date = {};
	std::istringstream iss(__DATE__);

	std::getline(iss, date.month, ' ');
	std::getline(iss, date.day, ' ');
	std::getline(iss, date.year);

	date.month = std::to_string(monthToInt(date.month));
	if (date.month.length() == 1)
		date.month = "0" + date.month;
	return (date);
}

void Account::_displayTimestamp(void)
{
	const struct s_date date = getDate();
	const struct s_time time = getTime();

	std::cout << "["
			  << date.year << date.month << date.day
			  << "_"
			  << time.hour << time.minute << time.second
			  << "]";
	return;
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::_nbAccounts = 0;

int	Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;
