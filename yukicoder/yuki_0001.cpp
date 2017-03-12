#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

struct log {
  int pos;
  int cost;
  int time;
};

int main(){
  ll N,C,V; // [50],[300],[1500]
  cin >> N >> C >> V;

  vector<int> ss(V), ts(V), cs(V), ms(V);
  for(int i=0; i<V; i++){ cin >> ss[i]; }
  for(int i=0; i<V; i++){ cin >> ts[i]; }
  for(int i=0; i<V; i++){ cin >> cs[i]; }
  for(int i=0; i<V; i++){ cin >> ms[i]; }

  auto gt = [](struct log l, struct log r)->bool {
    return l.time > r.time;
  }; // increacing order of time
  priority_queue<struct log, vector<struct log>,
                 decltype(gt)> roots(gt);

  struct log start = {1,0,0};
  roots.push(start);

  while(true){
    if(roots.empty()) { break; }
    struct log crr = roots.top();
    roots.pop();

    //cout<<crr.pos<<" "<<crr.cost<<" "<<crr.time<<endl;

    if(crr.pos == N){ // goal
      cout << crr.time << endl;
      return 0;
    }

    for(int i=0; i<V; i++){
      if(ss[i]!=crr.pos) { continue; }
      if(cs[i]+crr.cost > C) { continue; }
      struct log next = {ts[i], crr.cost+cs[i], crr.time+ms[i]};
      roots.push(next);
    }
  }

  cout << -1 << endl;

  //// TLE, search all root whose cost<C
  // queue<struct log> roots;
  // struct log tmp = {1,0,0};
  // roots.push(tmp);
  // int minTime = maxN*maxM;

  // while(true){
  //   if(roots.empty()){ break; }

  //   struct log crr  = roots.front();

  //   for(int i=0; i<V; i++){
  //     if(ss[i]!=crr.pos){ continue; }

  //     if(crr.cost + cs[i] <= C){
  //       if(ts[i]==N){ // goal
  //         minTime = min(minTime, ms[i]+crr.time);
  //       } else {
  //         tmp.pos  = ts[i];
  //         tmp.cost = cs[i]+crr.cost;
  //         tmp.time = ms[i]+crr.time;
  //         roots.push(tmp);
  //       }
  //     }
  //   }
  //   roots.pop();
  // }

  // //
  // if(minTime == maxN*maxM){
  //   minTime = -1;
  // }
  // cout << minTime << endl;

  return 0;
}
