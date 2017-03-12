#include <iostream>
#include <cmath>
#include <vector>
// #include <array>
#include <queue>
#include <set>
#include <map>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

const ll diviser = 1000003;

ll power(ll m, ll e){
  if(e==0){ return 1; }
  if(e==1){ return m; }
  if(e==2){ return m*m; }
  ll tmp = power(m,e/2);
  if(e%2==0){
    return (tmp*tmp) % diviser;
  } else {
    return (tmp*tmp*m) % diviser;
  }
}

int main(){
  // input
  ll X,N; // [10]
  cin >> X >> N;
  vector<int> As(N);
  for(int i=0; i<N; i++){
    cin >> As[i];
  }

  // main
  sort(As.begin(), As.end(), greater<ll>());

  vector<int> dif(N);
  for(int i=0; i<N-1; i++){
    dif[i] = As[i]-As[i+1];
  } dif[N-1] = As[N-1];

  ll res = 0;
  for(int i=0; i<N; i++){
    res = ((res+1)*power(X,dif[i])) % diviser;
  }

  cout << res << endl;

  return 0;
}
