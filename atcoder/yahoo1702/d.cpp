#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
  int Q,K;
  cin >> Q >> K;

  set<pair<long long int,long long int> > log;
  for(int q=0; q<Q; q++){
    long long int type, D, A;
    cin >> type;
    if(type == 1){ // 1 d a
      cin >> D >> A;
      log.insert(make_pair(D,A));
    } else {       // 2 d
      cin >> D;
      long long int sum = 0;
      long long int rest = 0;
      long long int day = 0;
      for(auto itr=log.begin(); itr!=log.end(); itr++){
        cout << itr->first << " " << itr->second << endl;

        if(D < itr->first){
          break;
        }

        rest += (itr->first - day) * K;
        day = itr->first;
        long long int tmp = min(rest, itr->second);
        sum += tmp;
        rest -= tmp;
      }

      cout << sum << endl;
    }
  }

  return 0;
}
