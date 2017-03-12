#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

//// search all
// bool rec(vector<int> vec, int idx, int N, int tgt){
//   if(idx >= N || tgt < 0){ return false; }
//   if(vec[idx] == tgt) { return true; }
//   return rec(vec, idx+1, N, tgt-vec[idx])
//     || rec(vec, idx+1, N, tgt);
// }

int main(){
  int N;
  cin >> N;

  vector<int> weights (N);
  int sum=0;
  for(int i=0; i<N; i++){
    cin >> weights[i];
    sum += weights[i];
  }

  // odd
  if(sum%2){
    cout << "impossible" << endl;
    return 0;
  }

  vector<bool> able (sum/2+1,false);
  able[0] = true;

  //// main
  // sort(weights.begin(), weights.end());
  int maxId = 0;
  for(int i=0; i<N; i++){ // weights
    for(int j=maxId; j>=0; j--){ // list
      if(able[j] && j+weights[i] <= sum/2){
        able[j+weights[i]] = true;
        maxId = max(maxId, j+weights[i]);
      }
    }
  }

  if(able[sum/2]){
    cout << "possible" << endl;
  } else {
    cout << "impossible" << endl;
  }

  // if(sum%2 || !rec(weights, 0, N, sum/2)){

  return 0;
}
