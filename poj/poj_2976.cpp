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

int proper(double d){
  int tmp = (int)d;
  return (d-tmp < 0.5) ? tmp : tmp+1;
}

int main(){
  while(true){
    // input
    ll N,K; // [1000],[N]
    cin >> N >> K;
    if(N==0 && K==0){ break; }

    vector<int> as(N);
    for(int i=0; i<N; i++){
      cin >> as[i];
    }
    vector<int> bs(N);
    for(int i=0; i<N; i++){
      cin >> bs[i];
    }

    // main
    double s=0,e=1.002;
    double avg = 0.5;

    while(true){

    }
    // while(true){
    //   if(s>=e-1) { break; }

    //   // check if c is valid
    //   int count = 0;
    //   int prev = 0;
    //   for(int i=0; i<rocks.size(); i++){
    //     if(rocks[i] - prev < c){ // remove
    //       count++;
    //     } else {
    //       prev = rocks[i];
    //     }
    //   }

    //   // cerr << s << " " << e << " " << c << " " << count << endl;

    //   // update
    //   int next = M<count ? (s+c)/2 : (c+e)/2;
    //   if(M<count){ e=c; } else { s=c; }
    //   c=next;
    // }

    // output
    cout << proper(avg) << endl;
  }

  return 0;
}
