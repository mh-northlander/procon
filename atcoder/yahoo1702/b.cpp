#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> prices(N);
  for(int i=0; i<N; i++){
    cin >> prices[i];
  }

  std::sort(prices.begin(), prices.end());
  long long sum=0;
  for(int i=0; i<K; i++){
    sum += prices[i] + i;
  }

  cout << sum << endl;

  return 0;
}
