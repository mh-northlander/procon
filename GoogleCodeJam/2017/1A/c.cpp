#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm> // sort
#include <utility>
#include <tuple>
#include <cmath>

typedef long long ll;
using namespace std;

bool has_overlap(pair<int,int> p1, pair<int,int> p2){
  if(p1.second < p2.first) return false;
  if(p2.second < p1.first) return false;
  return true;
}

struct S{
  ll Hd, Ad, Hk, Ak;
  ll turn;
  S(){ Hd = Ad = Hk = Ak = turn = 0; };
  S(ll hd, ll ad, ll hk, ll ak, ll t): Hd(hd), Ad(ad), Hk(hk), Ak(ak), turn(t) {};
  bool operator <(const S& r) const {
    return tie(turn,Hd,Ad,Hk,Ak) < tie(turn,r.Hd,r.Ad,r.Hk,r.Ak);
  }
};

int main(){
  ll T;
  cin >> T;

  for(int i=0; i<T; i++){
    ll Hd, Ad, Hk, Ak, B, D;
    cin >> Hd >> Ad >> Hk >> Ak >> B >> D;

    priority_queue<S> q;
    q.push(S(Hd,Ad,Hk,Ak,0));
    map<S, bool> memo;
    memo[q.top()] = true;

    int ans=-1;
    while(!q.empty()){
      S crr = q.top();
      if(crr.Hk <= 0)
      q.pop();

      S next;
      // attack
      next = S(crr.Hd-crr.Ak,   crr.Ad,    crr.Hk-crr.Ad, crr.Ak,      crr.turn+1);
      // buff
      next = S(crr.Hd-crr.Ak,   crr.Ad+B,  crr.Hk,        crr.Ak,      crr.turn+1);
      // cure
      next = S(    Hd-crr.Ak,   crr.Ad,    crr.Hk,        crr.Ak,      crr.turn+1);
      // debuff
      ll debuffed_Ak = crr.Ak-D < 0 ? 0 : crr.Ak-D;
      next = S(crr.Hd-debuffed_Ak, crr.Ad, crr.Hk,        debuffed_Ak, crr.turn+1);
    }


    cout << "Case #" << i+1 << ": " << ans << endl;
  }

  return 0;
}
