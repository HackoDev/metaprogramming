#include <iostream>
#include <iomanip>
#include "binom_meta.h"
#include <boost/mpl/for_each.hpp>

using namespace boost;
using namespace mpl;


constexpr long N = 14;
constexpr int step = (N - 2) / 2;  // нужна для вывода
volatile int currentIndex = -1;  // нужна для вывода

volatile int currentW = N * step + step;

struct map_functor
{
    template<typename T> void operator()(T)
    {
		if (first<typename first<T>::type >::type::value != currentIndex) {
		   currentIndex++;
		   currentW -= step;
		   std::cout << std::setw(3) << std::endl << currentIndex << ":   ";
		   std::cout << std::setw(currentW / 2);
		}
		std::cout << second<T>::type::value << std::setw(step);
    }
};

int main(int argc, char* argv[])
{
	typedef typename Bci <N, N>::mapData exampleData;
	for_each<exampleData>(map_functor());
	std::cout << std::endl;
	return 0;
}