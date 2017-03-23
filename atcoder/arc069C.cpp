#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
#include <cfloat> // DBL_MAX

typedef long long ll;
using namespace std;

int main(){
  ll N,M;
  cin >> N >> M;

  ll ans = 0;

  ans += min(N, M/2);;
  N -= ans;
  M -= ans*2;

  if(M > 2){
    ans += M/4;
  }

  cout << ans << endl;
  return 0;
}
