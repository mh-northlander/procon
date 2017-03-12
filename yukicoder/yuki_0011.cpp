#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

int main(){
  ll W,H,N; // [1000000],[100]
  cin >> W >> H >> N;

  set<int> marks, nums;

  for(int i=0; i<N; i++){
    int S,K; // [W], [H]
    cin >> S >> K;

    marks.insert(S);
    nums.insert(K);
  }

  // w*n +H*m -n*m -N
  ll matchs = W*nums.size() +H*marks.size() -nums.size()*marks.size()-N;
  cout << matchs  << endl;

  return 0;
}
