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
  bool d1,d2,d3,s;
  cin >> d1 >> d2 >> d3 >> s;

  //// output
  if(s || d1+d2+d3<2){
    cout << "SURVIVED" << endl;
  } else {
    cout << "DEAD" << endl;
  }

  return 0;
}
