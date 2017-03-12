#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
  string str;
  cin >> str;

  std::sort(str.begin(), str.end());
  if(str == "ahooy"){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
