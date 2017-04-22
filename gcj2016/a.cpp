#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // sort
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;

int main(){
  ll T;
  cin >> T;

  for(int t=0; t<T; t++){
    string S;
    cin >> S; cin.ignore();

    string ans = S.substr(0,1);
    for(int j=1; j<S.length(); j++){
      if(S[j] < ans[0]){
        ans.append(S,j,1);
      } else {
        string tmp = S.substr(j,1);
        tmp.append(ans);
        ans = tmp;
      }
    }

    cout << "Case #" << t+1 << ": " << ans << endl;
  }

  return 0;
}
