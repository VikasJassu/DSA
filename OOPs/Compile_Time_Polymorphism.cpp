#include <iostream>
using namespace std;

class Animal {
        public:

                Animal() {
                        cout<<"i m inside animal constructor"<<endl;
                }

                virtual void speak() {
                        cout<<"speaking"<<endl;
                }
};

class Dog: public Animal {
        public:

                Dog() {
                        cout<<"i m inside dog constructor"<<endl;
                }

                void speak() {
                        cout<<"barking"<<endl;
                }
};

int main() {

        //upcasting
        // Animal *a = new Dog();
        // a->speak();

        // //Downcasting
        // Dog *b = (Dog*)new Animal();
        // b->speak();

        //iss runtime polymorphism mein hum virtual keyword ka use karke humnein jis ...
        //member function ka object create kiya hai use access ya print kra sakte hain. 

        // Animal* a = new Animal();
        // Animal* b = new Dog();
        // Dog *a = new Dog();
        Dog *a = (Dog*)new Animal();

        //iss case mein hamesha right side ka constructor hi call hoga.
        //Child ko call karenge to parent ka constructor bhi chalega  but parent ke case mein sirf parent ka hi constructor chalega.
  return 0;
}