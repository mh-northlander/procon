#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm> // sort
#include <utility> // pair
#include <cfloat> // DBL_MAX

typedef long long ll;
using namespace std;


struct node{
  ll idx;
  ll size;
  ll num;
  node(ll i, ll s, ll n): idx(i), size(s), num(n) {}
};

int main(){
  ll N;
  cin >> N;

  map<ll, pair<ll,ll> > stnmap;
  for(ll i=0; i<N; i++){
    ll tmp;
    cin >> tmp;
    if(stnmap.find(tmp) == stnmap.end()){
      stnmap[tmp] = make_pair(i,1);
    } else {
      stnmap.at(tmp).second += 1;
    }
  }

  queue<node> q;
  for(auto itr = stnmap.rbegin(); itr!=stnmap.rend(); itr++){
    q.push(node(itr->second.first, itr->first, itr->second.second));
  }
  q.push(node(0,0,0));

  // while(!q.empty()){
  //   cerr << q.front().idx << " " << q.front().size << " " << q.front().num << endl;
  //   q.pop();
  // } return 0;

  vector<ll> ans(N,0);
  while(q.front().size != 0){
    //cerr << q.front().idx << " " << q.front().size << " " << q.front().num << endl;

    node crr = q.front();
    q.pop();

    // cerr << crr.idx << " " << crr.size << " " << crr.num << endl;
    // cerr << q.front().idx << " " << q.front().size << " " << q.front().num << endl;
    // cerr << crr.idx << " " << (crr.size - q.front().size) * crr.num << endl;

    ans[crr.idx] += (crr.size - q.front().size) * crr.num;
    ll tmp = min(q.front().idx, crr.idx);
    q.front().idx = tmp;
    q.front().num += crr.num;
  }

  for(ll i=0; i<N; i++){
    cout << ans[i] << endl;
  }


  return 0;
}
