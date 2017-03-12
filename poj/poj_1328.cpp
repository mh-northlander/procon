#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
#include <cfloat> // DBL_MAX

typedef long long ll;

using namespace std;

int main(){
  int pid=1;
  while(true){
    //// input / preprocess
    ll N;
    double D;
    cin >> N >> D;

    if(N==0 && D==0){
      break;
    }

    vector<pair<double,double> > island (N+1);
    int unable = false;
    double tx, ty;
    for(int i=0; i<N; i++){
      cin >> tx >> ty;

      if(ty > D){
        unable = true;
        continue;
      }

      double d = sqrt(D*D-ty*ty);
      island[i] = make_pair(tx-d,tx+d);
    }
    if(unable){
      cout << "Case " << pid++ << ": -1" << endl;
      continue;
    }

    // sentinel
    island[N] = make_pair(DBL_MAX, 0);

    //// main
    sort(island.begin(), island.end());

    int count=0;
    double lim=island[0].second;
    for(int i=1; i<N+1; i++){
      if(island[i].first > lim){
        count++;

        lim = island[i].second;
      } else {
        lim = min(lim, island[i].second);
      }
    }

    //// output
    cout << "Case " << pid++ << ": " << count << endl;
  }

  return 0;
}
