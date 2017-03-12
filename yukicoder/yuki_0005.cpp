#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;

using namespace std;

int main(){
  //// input
  int L, N;
  cin >> L >> N;

  vector<int> blocks (N);
  for(int i=0; i<N; i++){
    cin >> blocks[i];
  }

  //// main
  sort(blocks.begin(), blocks.end());

  //// output
  int idx, space = L;
  for(idx=0; idx<N; idx++){
    if(space < blocks[idx]){
      break;
    }
    space -= blocks[idx];
  }

  cout << idx << endl;

  return 0;
}
