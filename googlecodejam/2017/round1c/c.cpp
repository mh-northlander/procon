#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm> // sort
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;


double prob(vector<double> ps, int i, int k){ // bug
  // prob of more than k cores (in after idx i) works
  // prob(Ps, 0, K)
  // cerr << i << " " << k << endl;
  if(k<=0){ return 1.0; }
  if(i+k > ps.size()){ return 0.0; }
  return prob(ps, i+1, k)*(1.0-ps[i]) + (prob(ps, i+1, k-1))*ps[i];
  //return prob(ps, i+1, k)*(1.0-ps[i]) + (prob(ps, i+1, k-1)+prob(ps,i+1,k))*ps[i];
}

int main(){
  ll T;
  cin >> T;

  for(int t=0; t<T; t++){
    ll N,K;
    double U;
    cin >> N >> K >> U;

    vector<double> Ps(N);
    for(int i=0; i<N; i++){
      cin >> Ps[i];
    }
    sort(Ps.begin(), Ps.end());

    // small : K=N
    // maximize min_i pi.
    // for(int i=0; i<N; i++){
    //   double tmp = (Ps[i+1]-Ps[i]) * (i+1);
    //   if(tmp <= U){
    //     for(int j=0; j<i+1; j++){
    //       Ps[j] = Ps[i+1];
    //     }
    //     U -= tmp;
    //   } else {
    //     for(int j=0; j<=i; j++){
    //       Ps[j] += U / (i+1);
    //       U = 0;
    //     }
    //     break;
    //   }
    // }

    for(int i=N-K; i<N; i++){
      double tmp = (Ps[i+1]-Ps[i]) * (i+1 - (N-K));
      if(tmp <= U){
        for(int j=N-K; j<i+1; j++){
          Ps[j] = Ps[i+1];
        }
        U -= tmp;
      } else {
        for(int j=N-K; j<=i; j++){
          Ps[j] += U / (i+1-(N-K));
          U = 0;
        }
        break;
      }
    }

    double ans = prob(Ps, 0, K);
    cout << "Case #" << t+1 << ": " << setprecision(8) << ans << endl;;
  }

  return 0;
}
