#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  // read input
  int N;
  cin >> N;
  vector<int> vals(N);
  for(int i=0; i<N; i++){
    cin >> vals[i];
  }

  // exception N == 1 || 2
  if(N == 1){
    cout << 1 << endl;
    return 0;
  }
  if(N == 2){
    cout << ((vals[0] < vals[1]) ? 2 : 1) << endl;
    return 0;
  }

  // i番目を使う時の最大コンボ
  vector<int> maxCombo(N);
  maxCombo[0] = 1;
  maxCombo[1] = (vals[0] < vals[1]) ? 2 : 1;
  maxCombo[2] = maxCombo[1] + ((vals[1] < vals[2]) ? 1 : 0);

  for(int i=2; i<N; i++){
    maxCombo[i] = max({1,
          (vals[i-3] < vals[i] ? maxCombo[i-3]+1 : 0),
          (vals[i-2] < vals[i] ? maxCombo[i-2]+1 : 0),
          (vals[i-1] < vals[i] ? maxCombo[i-1]+1 : 0)});
  }

  cout << *max_element(maxCombo.begin(), maxCombo.end()) << endl;
  return 0;
}
