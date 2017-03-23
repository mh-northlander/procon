#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
#include <cfloat> // DBL_MAX

typedef long long ll;
using namespace std;

string oxs;
string ans;

bool cond(int idx, char sw, char ox){
  return ans[idx] == sw && ans[idx] == ox;
}

char inv(char c){
  if(c=='o') return 'x';
  return 'o';
}
char ox2sw(char c){
  if(c=='o') return 'S';
  return 'W';
}

int main(){
  ll N;
  cin >> N;

  string oxs;
  cin >> oxs; cin.ignore();

  vector<string> inits(4);
  inits[0] = "oo"; inits[1] = "ox"; inits[2] = "xo"; inits[3] = "xx";

  string ans;
  bool flg=false;
  for(auto itr=inits.begin(); itr!=inits.end(); itr++){
    ans = *itr;
    for(int i=2; i<N; i++){ // fill
      if(ans[i-1] == oxs[i-1]){ // s-o or w-x
        ans.push_back(    ans[i-2]);
      } else {
        ans.push_back(inv(ans[i-2]));
      }
    }
    // cerr << ans << endl;

    // cntr?
    // oks:
    // 1ssss-oo, 2sssw-ox, 4ssws-xx, 3ssww-xo
    // 4swss-xx, 3swsw-xo, 1swws-oo, 2swww-ox
    // 3wsss-xo, 4wssw-xx, 2wsws-ox, 1wsww-oo
    // 2wwss-ox, 1wwsw-oo, 3wwws-xo, 4wwww-xx
    if((ans[N-1]=='o') ^ (ans[N-2]==ans[0])){ // if true, oxs[N-1] should be 'x'
      if(oxs[N-1] != 'x'){ continue; }
    } else {
      if(oxs[N-1] != 'o'){ continue; }
    }

    if((ans[  0]=='o') ^ (ans[N-1]==ans[1])){ // if true, oxs[  0] should 'x'
      if(oxs[0] != 'x'){ continue; }
    } else {
      if(oxs[0] != 'o'){ continue; }
    }

    flg = true;
    break;
  }

  // out
  if(flg){
    for(int i=0; i<ans.length(); i++){ ans[i] = ox2sw(ans[i]); }
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
