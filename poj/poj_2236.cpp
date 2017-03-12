#include <iostream>
#include <cstdio>
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

//// union-find tree
vector<int> parent;
vector<int> rank;
void init(int N){
  parent = vector<int>(N);
  for(int i=0; i<N; i++){ parent[i]=i; }
  rank = vector<int>(N,0);
}
int find(int a){
  if(parent[a]==a) { return a; }
  return parent[a] = find(parent[a]);
}
void merge(int a, int b){
  int pa=find(a), pb=find(b);
  if(pa==pb){ return; }
  if(rank[pa]<rank[pb]){ parent[pa]=pb; }
  else {
    parent[pb]=pa;
    if(rank[pa]==rank[pb]) { rank[pa]++; }
  }
}
bool same(int a, int b){ return find(a)==find(b); }
////

bool inRange(double d, pair<double,double> p1, pair<double,double> p2){
  return (p1.first-p2.first)*(p1.first-p2.first)
    + (p1.second-p2.second)*(p1.second-p2.second)
    <= d*d;
}

int main(){
  int N;
  double D;
  cin >> N >> D;

  vector<pair<double,double> > pcs(N);
  vector<bool> repaired(N, false);
  for(int i=0; i<N; i++){
    double x,y;
    cin >> x >> y;
    pcs[i] = make_pair(x,y);
  }

  init(N);

  char op;
  int t1,t2;
  while(cin >> op){
    if(op == 'O'){ // repair pc
      cin >> t1;
      repaired[t1-1] = true;
      for(int i=1; i<=N; i++){
        if(i==t1) { continue; }
        if(inRange(D, pcs[t1-1], pcs[i-1]) && repaired[i-1]){
          merge(t1-1,i-1);
        }
      }
      // for(int i=0; i<N; i++){
      //   printf("%d ", parent[i]);
      // }
      // printf("\n");
    } else if(op=='S'){ // communication test
      cin >> t1 >> t2;
      if(repaired[t1-1] && repaired[t2-1] && same(t1-1,t2-1)){
        cout << "SUCCESS" << endl;
      } else {
        cout << "FAIL" << endl;
      }
    } else { break; }
  }

  return 0;
}
