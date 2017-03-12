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

// const int maxN = 10000;
// bool ps[maxN-1]; // 2~maxN-1 : 0~maxN-3

int main(){
  // input
  ll L,N,M; // [10 0000 0000],[50000],[N]
  cin >> L >> N >> M;
  vector<int> rocks(N);
  for(int i=0; i<N; i++){
    cin >> rocks[i];
  }

  // main
  sort(rocks.begin(), rocks.end());
  rocks.push_back(L);

  int s=0, e=L/(N-M+1)+1; // L/(N-M+1) >= min
  int c = (s+e)/2;

  while(true){
    if(s>=e-1) { break; }

    // check if c is valid
    int count = 0;
    int prev = 0;
    for(int i=0; i<rocks.size(); i++){
      if(rocks[i] - prev < c){ // remove
        count++;
      } else {
        prev = rocks[i];
      }
    }

    // cerr << s << " " << e << " " << c << " " << count << endl;

    // update
    int next = M<count ? (s+c)/2 : (c+e)/2;
    if(M<count){ e=c; } else { s=c; }
    c=next;
  }

  // output
  cout << c << endl;
  return 0;
}
