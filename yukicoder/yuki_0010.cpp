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
  ll N, total; // [50, 100,000]
  cin >> N >> total;

  vector<int> As(N); // [10]
  for(int i=0; i<N; i++){
    cin >> As[i];
  }

  // main
  queue<pair<int,string> > fomulas;
  fomulas.push(make_pair(total, ""));

  for(int i=N-1; i>0; i--){
    queue<pair<int,string> > next;
    while(!fomulas.empty()){
      if(i==0){
        if(fomulas.front().first == As[0]){
          next.push(fomulas.front());
        }
        fomulas.pop();
      } else {
        pair<int,string> crr(fomulas.front());
        fomulas.pop();
        // +
        if(crr.first >= As[i]){
          next.push(make_pair(crr.first-As[i],
                              "+"+crr.second));
        }
        // *
        if(As[i]==0){ continue; }
        if(crr.first%As[i] == 0){
          next.push(make_pair(crr.first/As[i],
                              "*"+crr.second));
        }
      }
    }
    fomulas = next;
  }

  // output
  cout << fomulas.front().second << endl;

  return 0;
}
