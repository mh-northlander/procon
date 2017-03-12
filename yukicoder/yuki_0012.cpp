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

const int maxR = 5000000;
bool ps[maxR-1]; // 2~maxN-1 : 0~maxN-3
//bool ov[maxR-1]; // 2~maxN-1 : 0~maxN-3

bool match(vector<int> tgtAs, vector<int> dCount){
  for(uint i=0; i<tgtAs.size(); i++){
    if(dCount[tgtAs[i]] == 0){
      return false; // didn't appears
    }
  }
  return true;
}

int main(){
  // prime
  ll L=1, R=maxR;
  map<int,int> p2i;
  //vector<int> primes;
  for(int i=0; i<R-1; i++){ ps[i] = true; }
  for(int i=2; i*i<R; i++){
    if(ps[i-2]){
      for(int j=i*i; j<=R; j+=i){
        ps[j-2] = false;
      }
    }
  }
  int count = 0;
  for(int i=L; i<=R; i++){
    if(ps[i-2]){
      p2i[i] = count++;
      //primes.push_back(i);
    }
  }
  // int np = primes.size();
  // cout << np << endl;

  // input
  ll N; // [10]
  cin >> N;
  vector<int> As(N);
  vector<bool> appear(10,false);
  for(int i=0; i<N; i++){
    cin >> As[i];
  }
  for(int i=0; i<N; i++){
    appear[As[i]] = true;
  }

  // clc excessness
  // for(int i=0; i<R-1; i++){ ov[i] = false; }

  vector<int> excess;
  excess.push_back(0);
  for(int i=0; i<maxR; i++){
    if(!ps[i-2]){ continue; }
    int crr = i;
    while(crr>0){
      if(!appear[crr%10]){
        excess.push_back(i);
        break;
      }
      crr /= 10;
    }
  }
  excess.push_back(maxR+1);

  // for(int i=0; i<100; i++){
  //   if(ps[i-2]){
  //     cout << i << " ";
  //   }
  // } cout << endl;
  // for(int i=0; i<30; i++){
  //   cout << excess[i] << " ";
  // } cout << endl;

  // main
  // shakutori -> xx
  // *x-*-*---xx---...
  //   i     j

  int maxI = -1;
  for(uint i=0; i<excess.size()-1; i++){
    vector<int> dCount(10,0);
    for(int j=excess[i]+1; j<excess[i+1]; j++){
      if(!ps[j-2]){ continue; }
      int crr = j;
      while(crr>0){
        dCount[crr%10]++;
        crr/=10;
      }
    }
    if(match(As, dCount)){
      maxI = max(maxI, excess[i+1]-excess[i]-2);
    }
  }

  cout << maxI << endl;

  return 0;
}
