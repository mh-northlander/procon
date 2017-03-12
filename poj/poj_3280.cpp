#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm> // sort

using namespace std;

typedef long long ll;

const int maxM = 2000;
ll dp[maxM][maxM]; // tag * gat

int main(){
  //// input
  int N, L;
  cin >> N >> L;

  string tag;
  tag.reserve(L);
  for(int i=0; i<L; i++){
    char tmp;
    cin >> tmp;
    tag.push_back(tmp);
  }

  map<char,ll> costs;
  for(int i=0; i<N; i++){
    char c;
    int t1,t2;
    cin >> c >> t1 >> t2;
    costs[c] = min(t1,t2); // only min cost is needed
  }

  //// main
  string gat = tag;
  reverse(gat.begin(), gat.end());
  // cout << tag << " " << gat << endl;

  // i==j==0
  dp[0][0] = (tag[0]==gat[0]) ? costs[tag[0]] : 0ll;
  for(int j=1; j<L; j++){ // i==0
    dp[0][j] = max(dp[0][j-1],
                   (tag[0]==gat[j])? costs[tag[0]] : 0ll);
  }
  for(int i=1; i<L; i++){
    // j==0
    dp[i][0] = max(dp[i-1][0],
                   (tag[i]==gat[0])? costs[gat[0]] : 0ll);
    for(int j=1; j<L; j++){
      dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      dp[i][j] = max(dp[i][j],
                     (tag[i]==gat[j])? dp[i-1][j-1]+costs[tag[i]] : dp[i-1][j-1]);
    }
  }

  //
  // for(int i=0; i<L; i++){
  //   cout << dp[i][0];
  //   for(int j=1; j<L; j++){
  //     cout << " " << dp[i][j];
  //   }
  //   cout << endl;
  // }

  // output
  ll sum=0;
  for(int i=0; i<L; i++){
    sum += costs[tag[i]];
  }

  cout << sum - dp[L-1][L-1] << endl;

  return 0;
}
