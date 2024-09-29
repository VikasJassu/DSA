#include <iostream>
using namespace std;

int ithBit(int n, int i){
  int mask = 1 << i;
  int ans = n & mask;
  if(ans) return 1;
  else return 0;
}

int setIthBit(int n, int i){
  int mask = 1 << i;
  int ans = n | mask;
  return ans;
}

void clearIthBit(int &n, int i){
  int mask = ~(1 << i);
  n = n & mask;
}

int setClearIthBit(int n, int i, int target){
  int mask = 1 << i;
  if(target == 0) mask = ~(mask);
  int ans = target ? (n | mask) : (n & mask);
  return ans;
}

void updateIthBit(int &n, int i, int target){
  clearIthBit(n,i);
  int mask = target << i;
  int ans = n | mask;
  cout<<"after updating -> "<<ans;
}

void clearLastIBits(int n, int i){
  int mask = -1 << i;
  int ans = n & mask;
  cout<<"after clearing -> "<<ans;
}

int main() {
  //cout<<ithBit(10,0);
  //cout<<setIthBit(10,2);
  //cout<<clearIthBit(10,1);
  //cout<<setClearIthBit(10,1,0);
  // int n = 10;
  // updateIthBit(n,2,1);
  clearLastIBits(7,2);
}
