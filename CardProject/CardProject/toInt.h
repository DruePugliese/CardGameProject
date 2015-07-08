#include <iostream>

using namespace std;

template <class toInt>
toInt StringToNumber(const string &Text, toInt defValue = toInt())
{
	stringstream ss;
	for (string::const_iterator i = Text.begin(); i != Text.end(); ++i)
		if (isdigit(*i) || *i == 'e' || *i == '-' || *i == '+' || *i == '.')
			ss << *i;
	toInt result;
	return ss >> result ? result : defValue;
}
