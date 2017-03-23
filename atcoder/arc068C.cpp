#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
#include <cfloat> // DBL_MAX

typedef long long ll;
using namespace std;

int main(){
  ll X;
  cin >> X;

  ll ans = (X/11) * 2;
  ll tmp = X%11;
  if(tmp == 0){
    ans += 0;
  } else if(tmp <= 6){
    ans += 1;
  } else {
    ans += 2;
  }

  cout << ans << endl;
  return 0;
}
