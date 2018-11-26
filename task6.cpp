#include <iostream>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/mpl/set/set0.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits.hpp>
#include <typeinfo>
#include <boost/mpl/placeholders.hpp>


namespace mpl = boost::mpl;

using namespace std;

class Expl1 {};
class Expl2 {};
class Expl3 {};

typedef mpl::vector <char, short, int, Expl3, Expl2,Expl3, Expl2, long, float, double, double, long, float, Expl1> Seq;

using namespace mpl::placeholders;

struct visit_type
{
  template <class TVisitor>
  void operator () (TVisitor) const
  {   
    TVisitor::visit();
  }
};

template <class T>
struct print_visitor
{
  static void visit()
  {
    std::cout << typeid (T).name() << std::endl;
  }
};

template <class TSeq> void print_types(int sIndex)
{
  std::cout << "------ Print Sequence (" << sIndex << ")------" << std::endl;
  mpl::for_each <TSeq, print_visitor <_> > (visit_type());
  std::cout << "------ Print Finished ------" << std::endl;
}

int main() {
  typedef mpl::fold<
                mpl::filter_view<
                  Seq,
                  boost::is_class<_>
                  // mpl::not_< boost::is_class<_> >
                >::type, 
                mpl::set0<>,
                mpl::insert<_1, _2>
              >::type newSeq;

  print_types<Seq>(1);
  print_types<newSeq>(2);
  return 0;
}
