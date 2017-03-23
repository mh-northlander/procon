#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
#include <cfloat> // DBL_MAX

typedef long long ll;
using namespace std;

int main(){
  ll N,C,K;
  cin >> N >> C >> K;

  vector<int> ts(N);
  for(int i=0; i<N; i++){
    cin >> ts[i];
  }

  sort(ts.begin(), ts.end());
  int fst = *ts.begin();
  int mem = 0;
  int ans = 1;
  for(int i=0; i<N; i++){
    if(mem == C || ts[i]-fst > K){ // next bus
      fst = ts[i];
      mem = 0;
      ans += 1;
    }

    mem+=1;
  }

  cout << ans << endl;
  return 0;
}
