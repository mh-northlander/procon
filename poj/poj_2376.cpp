#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
  //// input
  int N, T;
  cin >> N >> T;

  vector<pair<int,int> > cows (N+1);
  int t1, t2;
  for(int i=0; i<N; i++){
    cin >> t1 >> t2;
    cows[i] = make_pair(t1,t2);
  }
  cows[N] = make_pair(T+1,T+1); // sentinel

  //// main
  sort(cows.begin(), cows.end());

  // shift already covered, could covered, cows asigned
  int lim=1, cover=0, count=0;
  for(int i=0; i<N+1; i++){
    if(cows[i].first > lim){
      if(cover+1 < cows[i].first){
        // shift cannot covered exists
        count = -1;
        break;
      }

      lim = cover+1;
      count++;
    }

    cover = max(cows[i].second, cover);
  }

  //// output
  cout << count << endl;

  return 0;
}
