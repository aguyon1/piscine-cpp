#include "BitcoinExchange.hpp"

bool stringIsNumber(const std::string& str)
{
	std::string::const_iterator cit = str.begin();

	if (*cit == '-' || *cit == '+')
		cit++;
	for (; cit != str.end(); cit++)
		if (!isdigit(*cit))
			return (false);
	return (true);
}

inline static void printError(const std::string& error)
{
	std::cout << "Error: " << error << std::endl;
}

bool extractData(const std::string& line, Date& date, float& value)
{
	if (line.length() < 13)
		return (printError("bad input => " + line), false);
	const std::string year(line, 0, 4);
	const std::string month(line, 5, 2);
	const std::string day(line, 8, 2);
	if (!stringIsNumber(year) || !stringIsNumber(month) || !stringIsNumber(day))
		return (printError("bad input => " + line), false);
	if (line[4] != '-' && line[7] != '-' && !(line.substr(10, 3) == " | "))
		return (printError("bad input => " + line), false);
	value = atof((line.substr(13)).c_str());
	if (value < 0)
		return (printError("not a positive number."), false);
	if (value > 1000)
		return (printError("too large a number."), false);
	date = Date(year, month, day);
	return (true);
}

float getBitcoinPrice(std::map<Date, float, CompareDate>& dataMap, Date date, float value)
{
	std::map<Date, float, CompareDate>::iterator it;
	std::map<Date, float, CompareDate>::iterator itBegin = dataMap.begin();
	float price;

	it = dataMap.find(date);
	if (it != dataMap.end())
	{
		price = value * it->second;
	}
	else if (date < itBegin->first)
	{
		price = value * itBegin->second;
	}
	else
	{
		it = dataMap.lower_bound(date);
		--it;
		price = value * it->second;
	}
	return (price);
}

void inputHandle(std::map<Date, float, CompareDate>& dataMap, std::ifstream& inputFile)
{
	std::string input;

	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (std::getline(inputFile, input))
	{
		Date date;
		float value;

		if (extractData(input, date, value))
		{
			float price = getBitcoinPrice(dataMap, date, value);
			std::cout << date << " => " << value << " = " << price << std::endl;
		}
	}
}

void readAndStockData(std::ifstream& dataFile, std::map<Date, float, CompareDate>& dataMap)
{
	dataFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!dataFile.eof())
	{
		Date date;
		float exchange_rate;

		if (!getline(dataFile, date.year, '-'))
			continue;
		getline(dataFile, date.month, '-');
		getline(dataFile, date.day, ',');
		dataFile >> std::setprecision(2) >> exchange_rate;
		dataMap[date] = exchange_rate;
		dataFile.ignore();
	}
}

int main(int ac, char *av[])
{
	std::ifstream dataFile ("data.csv"), inputFile;
	std::map<Date, float, CompareDate> dataMap;

	if (ac != 2)
		printError("not enough or too many files"), exit(EXIT_FAILURE);
	inputFile.open(av[1]);
	if (!dataFile.is_open() || !inputFile.is_open())
		printError("could not open file."), exit(EXIT_FAILURE);
	readAndStockData(dataFile, dataMap);
	inputHandle(dataMap, inputFile);
	return (0);
}
