#include <iostream>
using namespace std;

class Animal {
  private: 
          int age;
};

class Dog: private Animal {
    public:
    void print() {
      cout<<"this is protected"<<endl;
      cout<<this->age;
    }

};
int main() {
 Dog d1;
 cout<<d1.age<<endl; //public member ya class ko access karne ke liye.
 d1.print(); //protected and private members ya class ko access karne ke liye.
  return 0;
}