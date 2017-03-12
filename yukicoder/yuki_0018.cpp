#include <iostream>
#include <algorithm> // uint, sort

typedef long long ll;
using namespace std;

int main(){
  //// input
  string str;
  cin >> str;

  //// main
  for(uint i=0; i<=str.length(); i++){
    str[i] = (str[i]-'A'+26-(i+1)%26)%26+'A';
  }

  //// output
  cout << str << endl;

  return 0;
}
