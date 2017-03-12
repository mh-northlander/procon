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

map<vector<int>, bool> memo;

vector<int> simplify(vector<int> from){
  // rm <0 elem and [n][n]
  sort(from.begin(), from.end());

  while(from[0]<=0){
    from.erase(from.begin());
  }
  for(uint i=1; i<from.size();){
    if(from[i-1] == from[i]){
      from.erase(from.begin()+(i-1), from.begin()+i+1);
      continue;
    }
    i++;
  }

  return from;
}

bool lookup(vector<int> w){
  // for(uint i=0; i<w.size(); i++){
  //   cout << w[i] << " " ;
  // }
  // cout << endl;

  w = simplify(w);

  // simple check
  if(w.empty()){ return memo[w] = false; }
  if(w.size() == 1){ return memo[w] = true; }
  if(w.size() == 2){ return memo[w] = !(w[0]==w[1]); }


  // exist?
  map<vector<int>,bool>::iterator itr = memo.find(w);
  if(itr != memo.end()) { return itr->second; }

  // add memo
  for(int i=w.size()-1; i>=0; i--){
    for(int j=1; j<w[i]; j++){
      vector<int> v(w);
      v[i] -=j;
      if(!lookup(v)) { return true; }
    }
  }

  return false;
}


int main(){
  ll N; // [2, 100 000 000]
  cin >> N;

  // prime factorization
  vector<int> nums;
  for(int i=2; N>1; i++){
    int count = 0;
    while(N%i == 0){
      N /= i;
      count++;
    }
    if(count>0){ nums.push_back(count); }
  }

  /*
    we have nums.size() sets, each contains nums[i] *s.
    every turn, player choose one of sets and
    take any number of *s from that set.
    one who take last * is the winner.

    [n]: A
    [n],[n]:B, [n],[m]:A
    [n],[n],[m]:A,
    [1],[2],[3]:B, -> (2elems)\in([1],[2],[3]) + [n>4]:A
    [1],[4],[5]:B,
    [2],[4],[6]:B,
    [1],[2],[3],[4]:A

    ...1:* and ...2:B <-> ...1+...2:*
    ..,[i],[j],[j],[k],..:* -> ..,[i],[k],..:*
    able to remove same numbers
    [1][2][3][3] = [1][2] = [3]
    ...1:A and ...2:A -> ...1+...2:?

    [l],[m>l],[n>m]:
    if l=1
    if m=2k and n=2k+1 -> B
    else -> A
    if l=2
    if m=3 -> A
    if m=2k and n=2k+1 -> A t
    if m=2k+1>3 and n=2k+2 -> A? 2,5,6A, 2,2k+1,2k+2
    2,7,8A -> 2,5,8. 2,5,7.
    if m=2k -> ? 2, 2k, n>2k+1

    if m=2k and n=2k+2 -> B f 2,4,6B
    if m=2k+1 and n=2k+2 -> A f
    else -> A 2,5,7

    A
    34- 35- 36- 37- 38-    3,9,-  3,10-, 3,11-
    B
    347 356         3,8,11 3,9,10
    A
    45- 46- 47- 48- 49- 410-  411-  412- 413- 41415
    B
    458 469             41012 41113

    1,2k+0,2k+1 -> B, else A
    2,4k+{0,1},4k+{2,3} -> B, else A
    3,4k+{0,1},4k+{3,2} -> B, else A

    n,n+1,n+2: n=2k:A, n=2k+1:B?

    2k,2k+1 \in l,m,n -> if other=1 then B else A


    [l],[m],[n],[o]:
  */

  // main
  if(lookup(nums)){
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }

  // sort(nums.begin(), nums.end());

  // // rm [n][n]
  // for(uint i=0; i<nums.size()-1;){
  //   if(nums[i] == nums[i+1]){
  //     nums.erase(nums.begin()+i, nums.begin()+i+1);
  //     continue;
  //   }
  //   i++;
  // }



  // 10**8 < 2**27, atmost 26
  // 10**8 < 2**5 * 3**4 * 5**3 * 7**2 * 11, atmost 4 groups
  // switch(nums.size()){
  // case 0:
  //   cout << "Bob" << endl; break;
  // case 1:
  //   cout << "Alice" << endl; break;
  // case 2:
  //   cout << "Bob" << endl; break;
  // case 3:
  //   //cout << "Bob" << endl;
  //   break;
  // case 4:
  //   //cout << "Bob" << endl;
  //   break;
  // }

  return 0;
}
