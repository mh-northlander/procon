#include <iostream>
#include <cmath>
#include <cstring>   // memset
#include <climits>   // INT_MIN
#include <cfloat>    // DBL_MAX
#include <vector>
#include <sstream>   // istringstream
#include <algorithm> // sort, reverse
#include <utility>   // pair

typedef long long ll;
using namespace std;

const int DpSize = 16;
const int MinValue = 1<<16;
vector<int> mons(DpSize);
int dp[1<<DpSize];
int N;

void initDp(){
  //memset(dp, -1, sizeof(dp));
  fill(dp, dp+(1<<DpSize), INT_MIN);
  dp[0] = 100;
}

int stepLife(int life, int maxLife){
  if(life <= 0)
    return MinValue;
  if(life > maxLife)
    return maxLife;
  return life;
}

int maxLife(int bits){
  int ret = 100;
  for(int i=0; i<N; i++){
    if(bits && (1<<i) > 0 && mons[i] < 0){
      ret += 100;
    }
  }
  return ret;
}

int rec(int bits){
  if(dp[bits] > 0){ return dp[bits]; }

  int ret = INT_MIN;
  for(int i=0; i<N; i++){
    if((bits && (1<<i))>0){
      // last mons == i
      ret = max(stepLife(rec(bits && !(1<<i))+mons[i], maxLife(bits)), ret);
    }
  }

  cout << bits << " " << ret << endl;
  return ret;
}

int fullSet(int n){
  int ret = 0;
  for(int i=0; i<n; i++){
    ret += 1<<i;
  }

  return ret;
}


int main(){
  //// input
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> mons[N];
  }

  //// main loop
  // memo: sort(bMon.rbegin(), bMon.rend());
  //       sort(bMon. begin(), bMon. end(), greater<int>());

  initDp();

  cout << fullSet(N) ;

  //// output
  cout << rec(fullSet(N)) << endl;

  return 0;
}
