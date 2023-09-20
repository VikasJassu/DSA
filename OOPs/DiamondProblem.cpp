#include <iostream>
using namespace std;

class A {
  public:
        int chemistry;

         A() {
            chemistry=100;
        }
};

class B {
  public:
        int chemistry;

         B() {
          chemistry=200;
        }
};
class C:public A , public B {
      public:
          int maths;
};

int main() {
  C obj;
  cout<<obj.B::chemistry<<" "<<obj.maths<<" "<<endl;
  return 0;
}