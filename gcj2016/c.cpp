#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm> // sort
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;

int main(){
  ll T;
  cin >> T;

  for(int t=0; t<T; t++){
    int N;
    cin >> N;
    vector<int> fs(N);
    map<int, vector<int> > rs;
    for(int i=0; i<N; i++){
      rs[i].resize(0);
    }
    for(int i=0; i<N; i++){
      cin >> fs[i];
      rs[fs[i]-1].push_back(i+1);
    }

    // for(int i=0; i<N; i++){
    //   for(int j=0; j<rs[i].size(); j++){
    //     cout << rs[i][j] << " ";
    //   } cout << endl;
    // } continue;

    // loop detection
    vector<pair<int,int> > loop2s;
    vector<bool> check(N, false);
    for(int i=0; i<N; i++){ // pair
      if(check[i]) continue;

      if(fs[fs[i]-1]-1 == i){
        loop2s.push_back(make_pair(i+1,fs[i]));
        check[fs[i]-1] = true;
        continue;
      }
    }

    for(int i=0; i<N; i++){ check[i] = false; }
    for(int i=0; i<loop2s.size(); i++){
      check[loop2s[i].first-1] = check[loop2s[i].second-1] = true;
    }

    int max_loop_size=0;
    for(int i=0; i<N; i++){
      if(check[i]) continue;
      check[i] = true;

      int crr = fs[i];
      vector<int> list(1,i+1);
      while(!check[crr-1]){
        check[crr-1] = true;

        int next = fs[crr-1];
        bool lp = false;
        for(int j=0; j<list.size(); j++){
          if(list[j] == next){
            lp = true;
            max_loop_size = max(max_loop_size, int(list.size())+1-j);
          }
        }
        if(lp) break;

        list.push_back(crr);
        crr = next;
      }
    }

    int ans = 0;
    for(int i=0; i<loop2s.size(); i++){
      int a = loop2s[i].first, b = loop2s[i].second;

      function<int(int,int)> depth = [&](int top, int ex)->int{
        if(rs[top-1].size() == 0) return 1;

        int ret = 0;
        for(int k=0; k<rs[top-1].size(); k++){
          if(rs[top-1][k] != ex){ ret = max(ret, depth(rs[top-1][k], ex)); }
        }
        return ret + 1;
      };

      ans += depth(a, b);
      ans += depth(b, a);
    }

    cout << "Case #" << t+1 << ": " << max(ans, max_loop_size) << endl;
  }

  return 0;
}
