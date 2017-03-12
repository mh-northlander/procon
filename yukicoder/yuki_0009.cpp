#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

// const int maxN = 200000;
// bool ps[maxN-1];

int main(){
  ll N; // [1500]
  cin >> N;

  priority_queue<pair<int,int>,
                 vector<pair<int,int> >,
                 greater<pair<int,int> > > party;
  vector<int> monster(N);
  for(int i=0; i<N; i++){
    int tmp;
    cin >> tmp;
    party.push(make_pair(tmp,0));
  }
  for(int i=0; i<N; i++){
    cin >> monster[i];
  }

  // main
  int minmaxb = 2000; // > 1500
  // for from each monster begin,
  for(int i=0; i<N; i++){
    priority_queue<pair<int,int>,
                   vector<pair<int,int> >,
                   greater<pair<int,int> > > sim(party);
    // the result becomes,
    for(int j=0; j<N; j++){
      sim.push(make_pair(sim.top().first+monster[(i+j)%N]/2,
                         sim.top().second+1));
      sim.pop();
    }
    // max battle is,
    int maxb = 0;
    while(!sim.empty()){
      maxb = max(maxb, sim.top().second);
      //cout << sim.top().first<<" "<<sim.top().second<<",";
      sim.pop();
    }
    minmaxb = min(minmaxb, maxb);
  }

  cout << minmaxb << endl;

  return 0;
}
