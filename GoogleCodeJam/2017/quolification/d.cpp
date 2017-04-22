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

  for(int i=0; i<T; i++){
    ll N,M;
    cin >> N >> M;

    vector<string> stage(N, string(N, '.'));
    for(int j=0; j<M; j++){
      char c;
      int x,y;
      cin >> c >> x >> y;
      stage[x-1][y-1] = c;
    }

    vector<string> chs;
    // add
    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++){
        if(stage[j][k] != '.'){ continue; }
        // add +
        bool flg_p = true;
        // diag \ : x-y=num
        if(j-k < 0){
          for(int l=0; l < N-(k-j); l++){
            if(stage[l][k-j+l] == 'o' || stage[l][k-j+l] == '+'){
              flg_p = false;
              break;
            }
          }
        } else {
          for(int l=0; l < N-(j-k); l++){
            if(stage[j-k+l][l] == 'o' || stage[l][j-k+l] == '+'){
              flg_p = false;
              break;
            }
          }
        }
        // diag /
        if(k+j < 0){
          for(int l=0; l < N-(k-j); l++){
            if(stage[l][k-j+l] == 'o' || stage[l][k-j+l] == '+'){
              flg_p = false;
              break;
            }
          }
        } else {
          for(int l=0; l < N-(j-k); l++){
            if(stage[j-k+l][l] == 'o' || stage[l][j-k+l] == '+'){
              flg_p = false;
              break;
            }
          }
        }



        // x
      }
    }

    // update
    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++){
        if(stage[j][k] == '.' || stage[j][k] == 'o'){ continue; }

      }
    }

    int point=0;
    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++){
        if(stage[j][k] == '.'){ continue; }
        if(stage[j][k] == 'o'){ point+=2; continue; }
        point++;
      }
    }

    cout << "Case #" << i+1 << ": " << point << " " << chs.size() << endl;
    for(int j=0; j<chs.size(); j++){
      cout << chs[j] << endl;
    }
  }

  return 0;
}
