#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>   // istringstream
#include <algorithm> // sort, reverse
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;

using namespace std;

int main(){
  //// input
  int N, K;
  string str;
  cin >> N >> K >> str;

  //// main loop
  // if(str[K-1]==')'){
  //   reverse(str.begin(), str.end());
  // }

  int idx=K-1,count=1;
  if(str[idx]=='('){
    while(++idx){
      if(str[idx]=='('){
        count++;
      } else {
        count--;
        if(count==0){
          break;
        }
      }
    }
  } else {
    while(idx--){
      if(str[idx]==')'){
        count++;
      } else {
        count--;
        if(count==0){
          break;
        }
      }
    }

  }

  //// output
  cout << idx+1 << endl;

  return 0;
}
