#include <boost/mpl/map.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/at.hpp>
#include <boost/static_assert.hpp>
#include <iostream>

using namespace boost;
using namespace mpl;


template <long N, long M>
struct Bci
{
  typedef typename Bci <N, M - 1>::mapData prev;

  typedef typename long_<N>::type currentX;
  typedef typename long_<M>::type currentY;

  static const int value = at <prev, pair<long_<N - 1>, currentY>>::type::value + 
                           at <prev, pair<long_<N - 1>, long_<M - 1>>>::type::value;
  
  typedef typename insert <
                      prev,
                      pair<
                        pair<
                          long_<N>, 
                          long_<M>
                          >, 
                        long_<value>
                        >
                      >::type mapData;
};

// специализация для 0,0- это стоп состояние
template<>
struct Bci<0, 0> 
{
  static const long value = 1;
  typedef map<
            pair<
              pair<
                long_<0>, 
                long_<0>
                >, 
              long_<value>
            >
        > mapData;
};

// специализация для k=0, уменьшаем n на 1
template <long N>
struct Bci<N, 0> 
{
  typedef typename Bci <N - 1, N -1>::mapData prev;
  static const long value = 1;
  typedef typename insert <
                      prev,
                      pair<
                        pair<
                          long_<N>, 
                          long_<0>
                          >, 
                        long_<value>
                        >
                      >::type mapData;
};


// специализация для n == m, уменьшаем m на 1
template <long N>
struct Bci<N, N> 
{
  typedef typename Bci <N, N -1>::mapData prev;
  static const long value = 1;
  typedef typename insert <
                      prev,
                      pair<
                        pair<
                          long_<N>, 
                          long_<N>
                          >, 
                        long_<value>
                        >
                      >::type mapData;
};
