#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

const int maxC = 2500;
const int maxL = 2500;


int main(){
  ll C,L; // [2500],[2500]
  cin >> C >> L;

  vector<pair<int,int> > cows(C);
  for(int i=0; i<C; i++){
    int mm,MM;
    cin >> mm >> MM;
    cows[i] = make_pair(MM,mm); // NOTICE! : invarting
  }

  vector<pair<int,int> > lotions(L);
  for(int i=0; i<L; i++){
    int spf,num;
    cin >> spf >> num;
    lotions[i] = make_pair(spf,num);
  }

  // main
  sort(cows.begin(),cows.end());
  sort(lotions.begin(),lotions.end());

  int count = 0;
  for(int i=0; i<C; i++){
    int spfm, spfM;
    spfM = cows[i].first;
    spfm = cows[i].second;
    for(int j=0; j<L; j++){
      int spf, num;
      spf = lotions[j].first;
      num = lotions[j].second;

      if(spfm>spf || num<=0){ continue; }
      if(spf>spfM){ break; }
      count++;
      lotions[j].second--;
      break;
    }
  }

  cout << count << endl;

  return 0;
}
