#include<iostream>
#include<math.h>
using namespace std;

void printDigit(int n) {
   if(n==0)
   return;

    printDigit(n/10);

   int digit = n%10;
   cout<<digit<<" ";

   
}
int main()
{
    int n;
    cout<<"enter any number"<<endl;
    cin>>n;
    if(n==0){
        cout<<"0"<<endl;
    }
    if(n<0) {
        n = -n;
    }
    cout<<"-";
    printDigit(n);
}