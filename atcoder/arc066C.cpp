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
  ll N;
  cin >> N;

  vector<int> As(N);
  for(int i=0; i<N; i++){
    cin >> As[i];
  }

  ll ans=1;
  for(int i=1; i<N; i+=2){
    ans = (ans*2) % 1000000007;
  }


  sort(As.rbegin(), As.rend());
  for(int i=0; i<N; i++){
    int should = (N-1) - (i/2)*2;
    if(As[i] != should){
      ans = 0;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
