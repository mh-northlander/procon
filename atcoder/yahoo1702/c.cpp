#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
  int N,K;
  cin >> N >> K;

  set<int> idx;
  for(int i=0; i<K; i++){
    int tmp;
    cin >> tmp;
    idx.insert(tmp);
  }

  vector<string> strIn;
  vector<string> strOut;
  for(int i=0; i<N; i++){
    string tmp;
    cin >> tmp;
    if(idx.count(i+1) == 1){
      strIn.push_back(tmp);
    } else {
      strOut.push_back(tmp);
    }
  }

  /*
  for(int i=0; i<strIn.size(); i++){
    cout << "in  " << i << " " << strIn[i]  << endl;
  }
  for(int i=0; i<strOut.size(); i++){
    cout << "out " << i << " " << strOut[i] << endl;
    }
  //*/

  std::sort(strIn.begin(),  strIn.end());
  std::sort(strOut.begin(), strOut.end());

  // pref
  string pref = "";
  string mm = strIn[0];
  string MM = strIn.back();
  int len = min(mm.length(), MM.length());
  for(int i=0; i<len; i++){
    if(mm[i] == MM[i]){
      pref.push_back(mm[i]);
    } else {
      break;
    }
  }

  // null str
  if(strOut.size() == 0){
    cout << "" << endl;
    return 0;
  }

  // exist
  for(int i=0; i<strOut.size(); i++){
    if(strOut[i].substr(0, pref.length()) == pref){
      cout << -1 << endl;
      return 0;
    }
  }

  //
  int maxL = 0;
  for(int i=0; i<strOut.size(); i++){
    int l = min(strOut[i].length(), pref.length());
    for(int j=1; j<=l; j++){
      if(strOut[i].substr(0,j) == pref.substr(0,j)){
        maxL = max(maxL, j);
      } else {
        break;
      }
    }
  }

  cout << pref.substr(0, maxL+1) << endl;

  return 0;


  // exist ?
  int l = pref.length();
  for(int i=0; i<strOut.size(); i++){
    if(strOut[i].substr(0,l) == pref){
      cout << -1 << endl;
      return 0;
    }
  }

  // shortst
  for(; l>=0; l--){
    bool flg = false;
    string cand = pref.substr(0,l);
    // cout << cand << endl;
    for(int i=0; i<strOut.size(); i++){
      if(strOut[i].substr(0,l) == cand){
        flg = true;
        break;
      }
    }
    if(flg){ break; }
  }

  //cout << pref << endl;
  //cout << (unsigned long)(l+1) << endl;
  cout << pref.substr(0,l+1) << endl;

  return 0;
}
