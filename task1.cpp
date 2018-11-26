#include <iostream>
#include <vector>

// -std=c++11

using namespace std;

template <typename T>
T sum(const vector<T>& v)
{
  if (v.size() == 0)
    return T();
  T result = T(0);
  for (const T &tmp: v)
    result += tmp;
  return result;
}

class NumberInc
{
  private:
    int m_n;
    NumberInc &operator = (const NumberInc &);
  public:
    NumberInc() : m_n(-12345678) { }
  explicit NumberInc(int n) : m_n(n) { }
  
    NumberInc &operator += (const NumberInc &rcNumber)
    {
      m_n += rcNumber.m_n;
      return *this;
    }
    friend std::ostream &operator << (std::ostream &rOS, const NumberInc &rcNumber)
    {
      rOS << rcNumber.m_n;
      return rOS;
    }
};

int main()
{
  vector<int> v1= {1, 2, 3, 10};
  vector<NumberInc> v2 = {NumberInc(1), NumberInc(2), NumberInc(3), NumberInc(10)};
  cout << sum(v1) << endl; // 
  cout << sum(v2) << endl;
  return 0;
}
