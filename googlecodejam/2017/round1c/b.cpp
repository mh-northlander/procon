#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm> // sort
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;

struct seg{
  int s,t;
  bool c;
  seg(int s,int t,bool c): s(s), t(t), c(c){}
  bool operator<(const seg& rhs) const {
    return s < rhs.s;
  }
};

int main(){
  ll T;
  cin >> T;

  for(int t=0; t<T; t++){
    ll Ac, Aj;
    cin >> Ac >> Aj;
    ll N = Ac+Aj;

    int sum_c = 0;
    vector<seg> As;
    for(int i=0; i<Ac; i++){
      ll c, d;
      cin >> c >> d;
      As.push_back(seg(c,d,true));
      sum_c += d-c;
    }
    for(int i=0; i<Aj; i++){
      ll c, d;
      cin >> c >> d;
      As.push_back(seg(c,d,false));
    }
    sort(As.begin(), As.end());

    // main
    vector<int> cc;
    vector<int> jj;
    vector<int> cj;
    for(int i=0; i<N-1; i++){
      if(As[i].c != As[i+1].c){
        cj.push_back(As[i+1].s - As[i].t);
      } else if(As[i].c){
        cc.push_back(As[i+1].s - As[i].t);
      } else {
        jj.push_back(As[i+1].s - As[i].t);
      }
    }
    if(As[0].c != As[N-1].c){
      cj.push_back(As[0].s + 24*60 - As[N-1].t);
    } else if(As[0].c){
      cc.push_back(As[0].s + 24*60 - As[N-1].t);
    } else {
      jj.push_back(As[0].s + 24*60 - As[N-1].t);
    }

    sort(cc.begin(), cc.end());
    sort(cj.rbegin(), cj.rend());
    sort(jj.rbegin(), jj.rend());
    // for(int i=0; i<cc.size(); i++){ cerr << cc[i] << " "; } cerr << endl;
    // for(int i=0; i<cj.size(); i++){ cerr << cj[i] << " "; } cerr << endl;
    // for(int i=0; i<jj.size(); i++){ cerr << jj[i] << " "; } cerr << endl;

    int ans = 2 * Ac;
    // cerr << "ans init " << ans << endl;
    int idx = 0;
    while(sum_c < 720 && idx < cc.size()){
      if(cc[idx] + sum_c > 720){
        // cerr << "cc fill" << endl;
        sum_c = 720;
        break;
      }
      // cerr << "cc take" << endl;
      sum_c += cc[idx++];
      ans -= 2;
    }

    idx = 0;
    while(sum_c < 720 && idx < cj.size()){
      if(cj[idx] + sum_c > 720){
        // cerr << "cj fill" << endl;
        sum_c = 720;
        break;
      }
      // cerr << "cj take" << endl;
      sum_c += cj[idx++];
    }

    idx = 0;
    while(sum_c < 720 && idx < jj.size()){
      if(jj[idx] + sum_c > 720){
        // cerr << "jj fill" << endl;
        ans += 2;
        sum_c = 720;
        break;
      }
      // cerr << "jj take" << endl;
      sum_c += jj[idx++];
      ans += 2;
    }

    cout << "Case #" << t+1 << ": " << ans << endl;
  }

  return 0;
}
