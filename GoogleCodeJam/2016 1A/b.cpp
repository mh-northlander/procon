#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm> // sort
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;

bool cmp_vec(vector<int> a, vector<int> b){
  int len = min(a.size(), b.size());
  for(int i=0; i<len; i++){
    if(a[i] < b[i]) return true;
    if(a[i] > b[i]) return false;
  }
  return false;
}

int main(){
  ll T;
  cin >> T;

  for(int t=0; t<T; t++){
    int N;
    cin >> N;

    // vector<vector<int> > ls(2*N-1);
    map<int,int> count;
    for(int i=0; i<2*N-1; i++){
      // ls[i].resize(N);
      for(int j=0; j<N; j++){
        int tmp;
        cin >> tmp;
        count[tmp] += 1;
        // cin >> ls[i][j];
      }
    }

    cout << "Case #" << t+1 << ":";
    for(auto itr=count.begin(); itr!=count.end(); itr++){
      if(itr->second % 2 == 1){
        cout << " " << itr->first;
      }
    } cout << endl;

    // sort(ls.begin(), ls.end(), cmp_vec);

    // for(int i=0; i<ls.size(); i++){
    //   for(int j=0; j<ls[i].size(); j++){
    //     cout << ls[i][j] << " ";
    //   } cout << endl;
    // } cout << endl;

    // cout << "Case #" << t+1 << ": " << ans << endl;
  }

  return 0;
}
