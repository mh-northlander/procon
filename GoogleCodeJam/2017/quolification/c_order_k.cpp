#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // sort
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;

int main(){
  ll T;
  cin >> T;

  for(int i=0; i<T; i++){
    ll N,K;
    cin >> N >> K;

    queue<ll> q;
    q.push(N);

    // O(N)
    for(ll j=0; j<K; j++){
      ll crr = q.front();
      q.pop();

      // l<=r;
      ll l=(crr-1)/2, r=(crr-1)-l;
      if(r > 0){ q.push(r); }
      if(l > 0){ q.push(l); }

      if(j == K-1){
        cout << "Case #" << i+1 << ": " << r << " " << l << endl;
      }
    }
  }

  return 0;
}
