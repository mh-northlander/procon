#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <utility>
#include <cmath>


typedef long long ll;
using namespace std;

// wrong
int is_tidy(ll in){
  int crr = 10;
  for(int i=0; in > 0; i++){
    if(in % 10 > crr){ return false; }
    crr = in % 10;
    in /= 10;
  }
  return true;
}
int non_tidy_digit(ll in){
  int d = -1;
  int crr = 10;
  for(int i=0; in > 0; i++){
    if(in % 10 >= crr){ d = i; }
    crr = in % 10;
    in /= 10;
  }
  return d;
}

int main(){
  ll T;
  cin >> T;

  for(int i=0; i<T; i++){
    ll N;
    cin >> N;

    ll t = 1;
    ll ans = 0;
    while(t < N){ t = 10*t + 1; }
    for(int i=0; i<9; i++){
      while(t > N){ t /= 10; }
      N -= t;
      ans += t;
      if(N <= 0) { break; }
    }

    cout << "Case #" << i+1 << ": " << ans << endl;

    // wrong
    // if(is_tidy(N)){
    //   cout << "Case #" << i+1 << ": " << N << endl;
    // } else {
    //   ll base = ll(pow(10, non_tidy_digit(N)));
    //   cout << "Case #" << i+1 << ": " << (N / base) * base -1 << endl;
    // }
  }

  return 0;
}
