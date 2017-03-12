#include <iostream>
#include <cmath>
#include <vector>
// #include <array>
#include <queue>
#include <set>
#include <map>
#include <sstream>   // istringstream
#include <algorithm> // sort
#include <utility>   // pair
#include <cfloat>    // DBL_MAX

typedef long long ll;
using namespace std;

const int maxN = 10000;
bool ps[maxN-1]; // 2~maxN-1 : 0~maxN-3

const int INF = 10000;

int main(){
  // prime (1000 ~ 10000) to idx map
  ll K=1000, N=10000;
  map<int,int> p2i;
  vector<int> primes;
  for(int i=0; i<N-1; i++){ ps[i] = true; }
  for(int i=2; i*i<N; i++){
    if(ps[i-2]){
      for(int j=i*i; j<=N; j+=i){
        ps[j-2] = false;
      }
    }
  }
  int count = 0;
  for(int i=K; i<=N; i++){
    if(ps[i-2]){
      p2i[i] = count++;
      primes.push_back(i);
    }
  }
  int np = primes.size();
  // cout << np << endl;

  // graph
  vector<vector<int> > nbid(np);
  for(int i=0; i<np; i++){
    int p = primes[i];
    int ms[4] = {1,10,100,1000};
    int ds[4];
    for(int j=0; j<4; j++){
      ds[j] = (p/ms[j])%10;
    }
    for(int j=0; j<4; j++){
      for(int k=0; k<10; k++){
        if(ds[j]==k){continue;}
        int pp = p+(k-ds[j])*ms[j];
        if(ps[pp-2] && pp>=1000){
          nbid[p2i[p]].push_back(p2i[pp]);
        }
      }
    }
  }

  // input
  ll P; // [100]
  cin >> P;

  // main
  for(int i=0; i<P; i++){
    int p1,p2;
    cin >> p1 >> p2;

    vector<bool> reached(np, false);
    queue<pair<int,int> > root;
    reached[p1] == true;
    root.push(make_pair(p1,0));

    bool imp = true;
    while(!root.empty()){
      int crrp = root.front().first;
      int crrd = root.front().second;
      root.pop();

      if(crrp == p2){
        cout << crrd << endl;
        imp=false; break;
      }

      for(int j=0; j<nbid[p2i[crrp]].size(); j++){
        int tgt = nbid[p2i[crrp]][j];
        if(reached[tgt]) {continue;}
        reached[tgt] = true;

        root.push(make_pair(primes[tgt], crrd+1));
      }
    }
    if(imp){ cout << "Impossible" << endl; }
  }

  // for(int i=0; i<nbid[p2i[P]].size(); i++){
  //   cout << primes[nbid[p2i[P]][i]] << endl;
  // }

  return 0;
}
