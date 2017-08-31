#include <boost/scoped_ptr.hpp>
#include <iostream>

using boost::scoped_ptr;
using std::cout;
using std::endl;

struct MyRes {
  MyRes(int, double) {
    cout << "MyRes ctor" << endl;
  }

  void use() {
    cout << "MyRes used" << endl;
  }

  ~MyRes() {
    cout << "MyRes dtor" << endl;
  }
};

int
boosted (int x, double y)
{
  scoped_ptr<MyRes> ptr(new MyRes(x, y));

  ptr->use();

  if (x > 3)
    return -1;

  return 0;
}

int
main ()
{
  assert (boosted(2, 1.0) == 0);
  assert (boosted(4, 1.0) == -1);
}

