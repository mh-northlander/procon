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

  // vector<bool> sieve(32-2, true); // 32**2 = 1024 > 10**3
  vector<bool> sieve(1000-2, true);
  vector<int> ps;
  for(int i=0; i<sieve.size(); i++){
    if(!sieve[i]){ continue; }
    ps.push_back(i+2);
    for(int j=2*i+2; j<sieve.size(); j+=(i+2)){
      sieve[j] = false;
    }
  }

  map<int,int> pfs; // prime factorization
  for(int i=2; i<=N; i++){
    int v = i;
    for(int j=0; j<ps.size(); j++){
      if(v==1){ break; }
      while(v%ps[j] == 0){
        if(pfs.find(ps[j]) != pfs.end()){
          pfs[ps[j]] += 1;
        } else {
          pfs[ps[j]] = 1;
        }
        v /= ps[j];
      }
    }
  }

  ll ans = 1;
  for(auto itr=pfs.begin(); itr!=pfs.end(); itr++){
    ans = (ans*(itr->second+1)) % 1000000007;
    // cout << itr->first << " " << itr->second << endl;
  }

  cout << ans << endl;

  return 0;
}
