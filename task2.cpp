#include <iostream>
#include <iterator>
#include <sstream>

// -std=c++11
// Вариант 

using namespace std;

template <class Itr, class T = typename iterator_traits<Itr>::value_type>
T sum(Itr it1, Itr it2)
{
	T result = 0;
	while (it1 != it2)
	{
		result += *it1;
		it1++;
	}
	return result;
}

int main()
{
	istringstream is("1 2 3 4 5 6 7");
	int nSum = sum(
	    istream_iterator <int> (is),
        istream_iterator <int> ()
	);
	cout << nSum << endl;
	return 0;
}
