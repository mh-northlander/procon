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

int bitCount(int);

int main(){
  //// input
  int N;
  cin >> N;

  //// main
  queue<pair<int,int> > search;
  vector<bool> checked(N, false);
  search.push(make_pair(1,1));
  checked[1-1] = true;

  while(true){
    if(search.empty()){
      cout << -1 << endl;
      break;
    }

    pair<int,int> crr = search.front();
    search.pop();

    if(crr.first == N){
      cout << crr.second << endl;
      break;
    }

    int bc = bitCount(crr.first);
    int t1 = crr.first + bc;
    int t2 = crr.first - bc;

    if(t1 <= N && !checked[t1-1]){
      search.push(make_pair(t1, crr.second+1));
      checked[t1-1] = true;
    }
    if(t2 > 0 && !checked[t2-1]){
      search.push(make_pair(t2, crr.second+1));
      checked[t2-1] = true;
    }
  }

  return 0;
}

int bitCount(int n){
  int count=0;
  while(n>0){
    if(n&1){ count++; }
    n >>= 1;
  }
  return count;
}
