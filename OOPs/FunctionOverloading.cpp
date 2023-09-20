#include <iostream>
using namespace std;

class Maths{
        public:

        //function overloading type of compile time polymorphism
        int sum(int a , int b) {
                return a + b;
        }

        int sum(int a , int b , int c) {
                return a+b+c;
        }

        int sum(int a , float b) {
                return a+b;
        }
};
int main() {
  Maths obj;
  cout << obj.sum(2,3.22f) << endl;
  return 0;
}