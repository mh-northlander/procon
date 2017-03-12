#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;

using namespace std;

int main(){
  //// input
  string str;
  cin >> str;

  //// main
  int MM;
  istringstream(str) >> MM;

  for(uint i=0; i < str.length()-1; i++){
    for(uint j=i+1; j < str.length(); j++){
      string tmps = str;
      tmps[i] = str[j];
      tmps[j] = str[i];

      int tmpi;
      istringstream(str) >> tmpi;
      MM = max(MM, tmpi);
    }
  }

  //// output
  cout << MM << endl;

  return 0;
}
