#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
  unordered_map<string, int> m;

  pair<string, int> p = make_pair("alto",10);
  m.insert(p);
  m["thar"] = 20;
  cout<<m.at("alto")<<endl;
  cout<<m.at("thar")<<endl;
  cout<<m["thar"]<<endl;
  cout<<m.count("thar")<<endl;
  if(m.find("alto") != m.end()) {
    cout<<"alto found"<<endl;
  }
  else{
    cout<<"not found"<<endl;
  }
  cout<<m.size()<<endl;
  cout<<m["zen"]<<endl; //ye method iski entry create karta hai and iske corresponding 0 insert karta hai and then 0 return karta hai. Thats why size increase hota hai.
  cout<<m.size()<<endl;
  m.erase("alto");

  cout<<"printing all values of map"<<endl;
  for(auto i:m) {
    cout<<i.first<<"->"<<i.second<<endl;
  }
  return 0;
}