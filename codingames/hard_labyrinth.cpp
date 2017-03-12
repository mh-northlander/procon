#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility> // pair
#include <algorithm>
using namespace std;

int MR, MC; // number of rows / columns.

struct node{
  int R;
  int C;
  bool flg;
  int dist;
  string how_to_go;
  node(int r, int c, bool f, int d, string s): R(r), C(c), flg(f), dist(d), how_to_go(s) {}
};

vector<vector<node> > fillMap(const int toR,  const int toC, const vector<string> map){
  vector<vector<node> > dists(MR);
  for(int i=0; i<MR; i++){ dists[i].assign(MC, node(-1,-1,false,100*200,"")); }
  dists[toR][toC].flg = true;
  dists[toR][toC].dist = 0;

  queue<pair<int,int> > q;
  q.push(make_pair(toR,toC));
  while(!q.empty()){
    pair<int,int> crr = q.front();
    q.pop();

    vector<node> dir;
    dir.push_back(node( 0, 1, false, 1, "LEFT"));
    dir.push_back(node( 0,-1, false, 1, "RIGHT"));
    dir.push_back(node( 1, 0, false, 1, "UP"));
    dir.push_back(node(-1, 0, false, 1, "DOWN"));

    for(auto itr=dir.begin(); itr!=dir.end(); itr++){
      int nR = crr.first  + itr->R;
      int nC = crr.second + itr->C;

      if(0<=nR && nR<MR && 0<=nC && nC<MC &&
         map[nR][nC] != '#' && map[nR][nC] != '?' && !dists[nR][nC].flg){
        dists[nR][nC].flg = true;
        dists[nR][nC].dist = dists[crr.first][crr.second].dist + itr->dist;
        dists[nR][nC].how_to_go = itr->how_to_go;
        q.push(make_pair(nR,nC));
      }
    }
  }

  return dists;
}

string go_to_nearest_q(const int fromR, const int fromC, vector<string> map){
  vector<vector<node> > dists(MR);
  for(int i=0; i<MR; i++){ dists[i].assign(MC, node(-1,-1,false,0,"")); }
  dists[fromR][fromC].flg = true;

  queue<pair<int,int> > q;
  q.push(make_pair(fromR,fromC));
  while(!q.empty()){
    pair<int,int> crr = q.front();
    q.pop();

    vector<node> dir;
    dir.push_back(node( 0, 1, false, 1, "RIGHT")); // memoize first step only
    dir.push_back(node( 0,-1, false, 1, "LEFT"));
    dir.push_back(node( 1, 0, false, 1, "DOWN"));
    dir.push_back(node(-1, 0, false, 1, "UP"));

    for(auto itr=dir.begin(); itr!=dir.end(); itr++){
      int nR = crr.first  + itr->R;
      int nC = crr.second + itr->C;

      if(0<=nR && nR<MR && 0<=nC && nC<MC && !dists[nR][nC].flg){
        if(map[nR][nC] == '?'){ return dists[crr.first][crr.second].how_to_go; }

        if(map[nR][nC] != '#'){
          dists[nR][nC].flg = true;
          dists[nR][nC].how_to_go = (dists[crr.first][crr.second].how_to_go == "") ?
            itr->how_to_go : dists[crr.first][crr.second].how_to_go;
          q.push(make_pair(nR,nC));
        }
      }
    }
  }
  return "ERR";
}


int main(){
  int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
  cin >> MR >> MC >> A; cin.ignore();
  cerr << MR << " " << MC << " " << A << endl;

  int TR=-1, TC=-1;
  int CR=-1, CC=-1;
  bool gotoT = false;
  bool gotoC = false;

  // game loop
  while (1) {
    int KR; // row where Kirk is located.
    int KC; // column where Kirk is located.
    cin >> KR >> KC; cin.ignore();
    cerr << KR << " " << KC << endl;

    vector<string> map(MR);
    for (int i = 0; i < MR; i++) {
      //string ROW; // C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
      //cin >> ROW; cin.ignore();
      cin >> map[i]; cin.ignore();
      cerr << map[i] << endl;
    }

    if(TR<0){ // check loc of T
      bool fin=false;
      for(int i=0; i<MR; i++){
        for(int j=0; j<MC; j++){
          if(map[i][j] == 'T'){
            TR = i;
            TC = j;
            break;
          }
        }
        if(fin){ break; }
      }
    }
    if(CR<0){ // check loc of C
      bool fin=false;
      for(int i=0; i<MR; i++){
        for(int j=0; j<MC; j++){
          if(map[i][j] == 'C'){
            CR = i;
            CC = j;
            break;
          }
        }
        if(fin){ break; }
      }
    }


    // vector<vector<node> > toT;

    // control deactivated : go to T
    gotoT = gotoT || (KR==CR && KC==CC);
    if(gotoT){
      cerr << "goto T" << endl;
      vector<vector<node> > toT = fillMap(TR,TC,map);
      cout << toT[KR][KC].how_to_go << endl;
      continue;
    }

    // control found && pass to start < A : go to C
    if(!gotoC && CR>=0){
      vector<vector<node> > toT = fillMap(TR,TC,map);
      gotoC = (toT[CR][CC].dist <= A);
    }
    if(gotoC){
      cerr << "goto C" << endl;
      vector<vector<node> > toC = fillMap(CR,CC,map);
      cout << toC[KR][KC].how_to_go << endl;
      continue;
    }

    // control found && pass not found : search route include '?'
    /*
    if(CR >= 0){
      cerr << "goto C (?)" << endl;
      vector<vector<node> > toC = fillMap(CR,CC,map, false);
      cout << toC[KR][KC].how_to_go << endl;
      continue;
    } //*/

    // control not found : search control
    cerr << "seraching.." << endl;
    cout << go_to_nearest_q(KR,KC,map) << endl;

    // cout << "RIGHT" << endl; // Kirk's next move (UP DOWN LEFT or RIGHT).
  }
}
