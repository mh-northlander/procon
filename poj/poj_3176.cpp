#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;

using namespace std;

int bitCount(int);

int main(){
  //// input
  int N;
  cin >> N;

  vector<vector<int> > scores(N);
  for(int i=0; i<N; i++){
    for(int j=0; j<i+1; j++){
      int tmp;
      cin >> tmp;
      scores[i].push_back(tmp);
    }
  }

  //// main
  for(int i=1; i<N; i++){
    for(int j=0; j<i+1; j++){
      if(j==0){
        scores[i][j] += scores[i-1][j];
      } else if(j==i){
        scores[i][j] += scores[i-1][j-1];
      } else {
        scores[i][j] = max(scores[i][j]+scores[i-1][j-1],
                           scores[i][j]+scores[i-1][j]);
      }
    }
  }

  int mm=0;
  for(int i=0; i<N; i++){
    mm = max(mm, scores[N-1][i]);
  }

  cout << mm << endl;

  return 0;
}
