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
  int N;
  cin >> N;

  //// main loop
  vector<bool> poss(10, true);
  int a,b,c,d;
  string yn;
  for(int i=0; i<N; i++){
    cin >> a >> b >> c >> d >> yn;
    if(yn=="YES"){
      for(int i=0; i<10; i++){
        if(i!=a&&i!=b&&i!=c&&i!=d){
          poss[i] = false;
        }
      }
    } else { // NO
      poss[a]=poss[b]=poss[c]=poss[d] = false;
    }
  }

  //// output
  for(int i=0; i<10; i++){
    if(poss[i]){
      cout << i << endl;
      break;
    }
  }

  return 0;
}
