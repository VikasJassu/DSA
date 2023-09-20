#include <iostream>
using namespace std;

class Animal {
  private:
  int weight;

  public:
  int age;
  string name;

  //default constructor 
  Animal() {
    cout<<"default constructor"<<endl;
  }

  //Parameterised constructor
  Animal(int age , int weight , string name) {
    this->age = age;
    this->weight = weight;
    this->name = name;
    cout<<"i m inside parameterised constructor"<<endl;
  }

  //copy constructor
  Animal(Animal &obj) {
    this->age = age;
    this->weight = weight;
    this->name = name;
    cout<<"this is copy constructor"<<endl;
  }

  //destructor
  ~Animal() {
    cout<<"i m inside destructor"<<endl;
  }

  // Animal(Animal &obj) {
  //   this->age = obj.age;
  //   this->name = obj.name;
  //   cout<<"i m inside copy constructor" <<endl;
  // }
};

int main() {
  // Animal lion;
  // Animal();
  // // Animal(10,100,"abd");
   Animal a; //stack memory allocation
   Animal *b = new Animal(); //dynamic memory allocation
   Animal c = a;
   Animal animal1(c);

  a.age = 10;
  b->age = 20;
  delete b;

  


//  Animal *b = new Animal;
// Animal c = a;
  return 0;
}