#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <cstdlib>
#include <cassert>
#include <iomanip>

struct Date
{
	std::string year;
	std::string month;
	std::string day;
	Date(void)
	: year(std::string()), month(std::string()), day(std::string())
	{}
	Date(std::string y, std::string m, std::string d)
	: year(y), month(m), day(d)
	{}
	bool operator<(const Date& d2) const
	{
		if (this->year < d2.year)
			return (true);
		else if (this->year > d2.year)
			return (false);
		else if (this->month < d2.month)
			return (true);
		else if (this->month > d2.month)
			return (false);
		else
			return (this->day < d2.day);
	}
};

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	return (os << date.year << '-' << date.month << '-' << date.day);
}

struct CompareDate
{
	bool operator()(const Date& d1, const Date& d2) const
	{
		return (d1 < d2);
	}
};

#endif
