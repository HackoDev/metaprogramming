#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

// -std=c++11
// Вариант: 6 

using namespace std;

template <class Iterator, 
          class T = typename iterator_traits<Iterator>::value_type>
vector<T*> update_iterator(Iterator it1, Iterator it2)
{
  vector<T*> v;
  while (it1 != it2)
  {
    bool exists = false;
    // check if exists
    for (T* tmp:v)
      if (*tmp == *it1)
        exists = true;
    // add if doen't exist
    if (!exists)
      v.push_back(&*it1);
    // increase iterator
    it1++;
  }
  return v;
}

class Comparable
{
private:
  int m_n;
  Comparable &operator = (const Comparable &);
public:
  explicit Comparable(int n) : m_n(n) { }
  bool operator == (const Comparable &rcOther)
  {
    return (m_n == rcOther.m_n);
  }
  friend std::ostream &operator << (
    std::ostream &rOS, const Comparable &rcComparable)
  {
    rOS << rcComparable.m_n;
    return rOS;
  }
};

// I've tried to implement template function 
// which can receive iterator<T*> instead iterator<T>, but I can't
// template<class Iterator, class T = typename iterator_traits<Iterator>::value_type>
// void display(Iterator it)
// {
  // for (const T* tmp: it);
    // cout << *tmp << endl;
// }

int main()
{
  vector<int> s1 = {1, 2, 3, 4, 4, 3, 2, 9};
  vector<Comparable> s2 = {
    Comparable(1),
    Comparable(2),
    Comparable(3),
    Comparable(1),
    Comparable(2),
    Comparable(3),
  };
  vector<char> s3 = {'s', 'f', 'g', 'f', 'f', 'g', 's', 'z'};

  vector<int*> result1 = update_iterator(s1.begin(), s1.end());
  vector<Comparable*> result2 = update_iterator(s2.begin(), s2.end());
  vector<char*> result3 = update_iterator(s3.begin(), s3.end());

  cout << "Result 1: " << endl;
  for (const int* tmp: result1)
    cout << *tmp << endl;

  cout << "Result 2: " << endl;
  for (const Comparable* tmp: result2)
    cout << *tmp << endl;

  cout << "Result 3: " << endl;
  for (const char* tmp: result3)
    cout << *tmp << endl;

  return 0;
}
