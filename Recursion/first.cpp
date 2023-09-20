#include<iostream>
using namespace std;

// void Counting(int n) {
    
//     if(n == 0) 
//     return;
//     cout<<n<<" ";

//     Counting(n-1);
// }
// int main() {

//     int n;
//     cout<<"enter any number"<<endl;
//     cin>>n;

//   Counting(n);
// }

int factorial(int n) {
    cout<<"printing factorial for n: "<<n<<endl;
    if(n==1) {
        return 1;
    }
    int ans = n * factorial(n-1);
    return ans;
}
int main()
{
    int n;
    cout<<"enter any number"<<endl;
    cin>>n;

    int ans = factorial(n);
    cout<<ans<<endl;
} 