#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

const int maxN = 10000;
bool ps[maxN-1];

int main(){
  int P; // [100]
  cin >> P;

  for(int round=0; round<P; round++){
    int N,K; // [2,120000]
    cin >> N >> K;

    // you can win iff you can say N-1.
    // <-> say N-1-(K+1) <-> N-1-n(K+1)
    int firstTarget = (N-1)%(K+1);

    if(0 < firstTarget && firstTarget <= K){
      cout << "Win" << endl;
    } else {
      cout << "Lose" << endl;
    }
  }
  return 0;
}
