#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm> // sort
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;

struct P{
  int n1,n2;
  string s1,s2;
  P(){};
  P(int n1,int n2,string s1,string s2): n1(n1), n2(n2), s1(s1), s2(s2) {};
  bool operator<(const P& rhs) const { return n1 < rhs.n1; };
};

int main(){
  ll T;
  cin >> T;

  for(int t=0; t<T; t++){
    ll N,R,O,Y,G,B,V;
    cin >> N >> R >> O >> Y >> G >> B >> V;

    if(R-G < 0 || Y-V < 0 || B-O < 0){ // cannot make RGR/YVY/BOB
      cout << "Case #" << t+1 << ": " << "IMPOSSIBLE" << endl;
      continue;
    }

    // exceptions
    if(O==0 && Y==0 && B==0 && V==0 && R==G){
      cout << "Case #" << t+1 << ": ";
      for(int i=0; i<R; i++){ cout << "RG"; }
      cout << endl;
      continue;
    }
    if(R==0 && O==0 && G==0 && B==0 && Y==V){
      cout << "Case #" << t+1 << ": ";
      for(int i=0; i<Y; i++){ cout << "YV"; }
      cout << endl;
      continue;
    }
    if(R==0 && Y==0 && G==0 && V==0 && B==O){
      cout << "Case #" << t+1 << ": ";
      for(int i=0; i<B; i++){ cout << "BO"; }
      cout << endl;
      continue;
    }

    // num of RorRGR, num of RGR, "R", "RGR"
    vector<P> ps;
    ps.push_back(P(R-G, G, "R", "GR"));
    ps.push_back(P(Y-V, V, "Y", "VY"));
    ps.push_back(P(B-O, O, "B", "OB"));

    sort(ps.rbegin(), ps.rend());

    // for(int i=0; i<3; i++){
    //   cerr<< ps[i].n1<<" "<<ps[i].n2<<" "<<ps[i].s1<<" "<<ps[i].s2 <<endl;
    // }

    if(ps[0].n1 > ps[1].n1 + ps[2].n1){
      cout << "Case #" << t+1 << ": " << "IMPOSSIBLE" << endl;
      continue;
    }

    int rest = ps[1].n1 + ps[2].n1 - ps[0].n1;
    string ans = "";
    while(ps[0].n1 > 0 || ps[1].n1 > 0 || ps[2].n1 > 0){
      if(rest-- > 0){
        ans += ps[0].s1;
        if(ps[0].n2 > 0){ for(int i=0; i<ps[0].n2; ps[0].n2--){ans += ps[0].s2;} }
        ans += ps[1].s1;
        if(ps[1].n2 > 0){ for(int i=0; i<ps[1].n2; ps[1].n2--){ans += ps[1].s2;} }
        ans += ps[2].s1;
        if(ps[2].n2 > 0){ for(int i=0; i<ps[2].n2; ps[2].n2--){ans += ps[2].s2;} }
      } else if(ps[1].n1 > 0){
        ans += ps[0].s1;
        if(ps[0].n2 > 0){ for(int i=0; i<ps[0].n2; ps[0].n2--){ans += ps[0].s2;} }
        ans += ps[1].s1;
        if(ps[1].n2 > 0){ for(int i=0; i<ps[1].n2; ps[1].n2--){ans += ps[1].s2;} }
      } else {
        ans += ps[0].s1;
        if(ps[0].n2 > 0){ for(int i=0; i<ps[0].n2; ps[0].n2--){ans += ps[0].s2;} }
        ans += ps[2].s1;
        if(ps[2].n2 > 0){ for(int i=0; i<ps[2].n2; ps[2].n2--){ans += ps[2].s2;} }
      }
      ps[0].n1--; ps[1].n1--; ps[2].n1--;
    }

    cout << "Case #" << t+1 << ": " << ans << endl;
  }

  return 0;
}
