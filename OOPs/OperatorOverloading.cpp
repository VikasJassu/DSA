#include <iostream>
using namespace std;

class Param{
        public:
                int value;

                //operator overloading in compile time polymorphism.
                void operator-(Param& obj2) {
                        int val1 = this->value;
                        int val2 = obj2.value;

                        cout<<(val2+val1)<<endl;
                }
};
int main() {

        Param object1 , object2;
        object1.value = 5;
        object2.value = 2;

        object1 - object2;
        //isme - karange but hoga plus. operator overloading mein hum operator ko define kar skte hain.
  return 0;
}