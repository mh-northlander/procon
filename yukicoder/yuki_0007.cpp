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
  int N;
  cin >> N;

  // is able to win
  vector<bool> able (max(N+1,4), false);
  able[0] = true; able[1] = true;

  // prime (<= N)
  vector<int> primes;
  for(int i=0; i<N-1; i++){ ps[i] = true; }
  for(int i=2; i<sqrt(N)+1; i++){
    if(ps[i-2]){
      for(int j=i*i; j<=N; j+=i){
        ps[j-2] = false;
      }
    }
  }
  for(int i=2; i<=N; i++){
    if(ps[i-2]){
      primes.push_back(i);
    }
  }

  //// main
  for(int i=4; i<N+1; i++){
    for(uint j=0; j<primes.size(); j++){
      if(i <= primes[j]){ // its enough
        break;
      }
      if(!able[i-primes[j]]){ // choice which opp can't win
        able[i] = true;
        break;
      }
    }
  }

  //// main
  if(able[N]){
    cout << "Win" << endl;
  } else {
    cout << "Lose" << endl;
  }

  return 0;
}
