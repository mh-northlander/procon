#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm> // sort
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;

bool cmp(pair<double,double> lhs, pair<double,double> rhs){
  return lhs.second < rhs.second;
}


int main(){
  ll T;
  cin >> T;

  for(int t=0; t<T; t++){
    ll N, K;
    cin >> N >> K;

    vector<pair<double,double> > Ps(N);
    for(int i=0; i<N; i++){
      double ri,hi;
      cin >> ri >> hi;
      Ps[i] = make_pair(ri, 2. * M_PI * ri * hi); // radius, side area
    }
    sort(Ps.begin(), Ps.end());

    // check all
    double ans = 0;
    for(int i=K-1; i<N; i++){
      double tmp = M_PI * Ps[i].first * Ps[i].first + Ps[i].second;

      vector<pair<double,double> > other(Ps);
      other.erase(other.begin()+i);
      sort(other.rbegin(), other.rend(), cmp);

      int cnt = 0;
      for(int j=0; cnt<K-1; j++){
        if(other[j].first <= Ps[i].first){
          tmp += other[j].second;
          cnt++;
        }
      }

      if(tmp > ans){ ans = tmp; }
    }

    cout << "Case #" << t+1 << ": " << setprecision(8) << ans << endl;
  }

  return 0;
}
