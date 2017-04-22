#include <iostream>
#include <cmath>
#include <cstdlib> // rand
#include <cfloat> // DBL_MAX
#include <map>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair

typedef long long ll;
using namespace std;

int main(){
  ll N, A, B;
  cin >> N >> A >> B;

  vector<int> xs(N);
  for(int i=0; i<N; i++){
    cin >> xs[i];
  }

  ll ans = 0;
  for(int i=1; i<N; i++){
    ans += min((xs[i]-xs[i-1]) * A, B);
  }

  cout << ans << endl;

  return 0;
}
