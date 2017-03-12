#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

const int maxN = 200000;
bool ps[maxN-1];

int myhash(int p){
  while(p>9){
    int sum=0, tmp=p;
    while(tmp>0){
      sum += tmp%10;
      tmp /= 10;
    }
    p = sum;
  }
  return p;
}

int main(){
  ll K,N; // [2, 200 000]
  cin >> K >> N;

  // prime (K ~ N)
  vector<int> primes;
  for(int i=0; i<N-1; i++){ ps[i] = true; }
  for(int i=2; i<sqrt(N)+1; i++){
    if(ps[i-2]){
      for(int j=i*i; j<=N; j+=i){
        ps[j-2] = false;
      }
    }
  }
  for(int i=K; i<=N; i++){
    if(ps[i-2]){
      primes.push_back(i);
    }
  }

  int np = primes.size();

  // main
  vector<int> hashed(np);
  for(int i=0; i<np; i++){
    hashed[i] = myhash(primes[i]);
  }

  vector<int> maxlen(np, 10);
  for(int n=1; n<10; n++){
    int c,tmp=0,nn;
    for(nn=0; nn<(int)np; nn++){
      if(hashed[nn]==n){
        if(tmp>0){ break; }
        tmp++;
      }
    }
    c=nn;

    for(int i=0; i<(int)np; i++){
      maxlen[i] = min(maxlen[i], c-i);
      if(hashed[i]==n){
        for(nn=c+1; nn<(int)np; nn++){
          if(hashed[nn]==n) { break; }
        }
        c=nn;
      }
    }
  }

  // for(int i=0; i<np; i++){
  //   cout << primes[i] << " ";
  // } cout << endl;
  // for(int i=0; i<np; i++){
  //   cout << hashed[i] << " ";
  // } cout << endl;
  // for(int i=0; i<np; i++){
  //   cout << maxlen[i] << " ";
  // } cout << endl;

  int maxid=0;
  for(int i=0; i<np; i++){
    if(maxlen[i] >= maxlen[maxid]){
      maxid = i;
    }
  }
  cout << primes[maxid] << endl;

  return 0;
}
