#include <iostream>
#include <cmath>
#include <cstdlib> // rand
#include <cfloat> // DBL_MAX
#include <vector>
#include <algorithm> // sort
#include <utility> // pair

typedef long long ll;
using namespace std;

struct fenwick{
  vector<int> arr;
  fenwick(const int n){
    arr = vector<int> (n,0);
  };

  int lsb(const int i){
    return i & (-i);
  }
  int sum(const int idx){
    ll ret = 0;
    int i=idx;
    while(i>0){
      ret += arr[i-1];
      i -= lsb(i);
    }
    return ret;
  }
  int num(const int idx){
    ll ret=0;
    int i=idx-1, j=idx;
    while(j>i){
      ret += arr[j-1];
      j -= lsb(j); // remove LSB (least significant bit) (-i : !i-1)
    }
    while(i>j){
      ret -= arr[i-1];
      i -= lsb(i);
    }
    return ret;
  }
  void update(const int l, const int r){
    /* TLE, O((r-l)*log M)
    for(int i=l; i<=r; i++){
      int idx = i-1;
      while(idx < arr.size()){
        arr[idx] += 1;
        idx += lsb(idx+1);
      }
      }*/
    int idx = l-1;
    while(idx < arr.size()){
      arr[idx] += 1;
      idx += lsb(idx+1);
    }
    idx = r;
    while(idx < arr.size()){
      arr[idx] -= 1;
      idx += lsb(idx+1);
    }
  }
};

int main(){
  ll N,M;
  cin >> N >> M;

  vector<int> ans(M,0);
  vector<pair<int,int> > lr(N);
  for(int i=0; i<N; i++){
    int l,r;
    cin >> l >> r;
    lr[i] = make_pair(l,r);

    // for(int j=1; j<=r; j++){ // naive count (TLE)
    //   if(r-l >= r%j){
    //     ans[j-1] += 1;
    //   }
    // }
  }

  sort(lr.begin(), lr.end(), [](pair<int,int> a, pair<int,int> b)->bool{
      return (a.second-a.first) < (b.second-b.first);
    });

  fenwick fw(M);

  int idx=0;
  for(int d=1; d<=M; d++){
    while(idx<N && lr[idx].second - lr[idx].first + 1 <= d){
      fw.update(lr[idx].first, lr[idx].second);
      idx++;
    }

    ans[d-1] += N-idx; // r-l+1 <= d, always stop
    for(int i=d; i<=M; i+=d){
      // cout << d << " " << fw.sum(i) << " " << i << endl;
      ans[d-1] += fw.sum(i);
    }
  }

  // out
  for(int i=0; i<M; i++){
    cout << ans[i] << endl;
  }

  return 0;
}
