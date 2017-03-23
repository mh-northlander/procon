#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
#include <cfloat> // DBL_MAX

typedef long long ll;
using namespace std;

int main(){
  ll N;
  cin >> N;

  vector<ll> As(N);
  for(int i=0; i<N; i++){
    cin >> As[i];
  }

  sort(As.begin(), As.end());
  ll ans = N;
  for(int i=1; i<N; i++){
    if(As[i-1] == As[i]){
      ans--;
    }
  }
  if(ans%2 == 0){
    ans--;
  }

  cout << ans << endl;
  return 0;
}
