#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>   // istringstream
#include <algorithm> // sort, uint
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

int main(){
  //// input
  int N, K;
  cin >> N >> K;

  vector<int> Nums(N);
  for(int i=0; i<N; i++){
    cin >> Nums[i];
  }

  //// main
  sort(Nums.begin(), Nums.end());

  //// output
  cout << Nums[N-1]-Nums[0] << endl;

  return 0;
}
