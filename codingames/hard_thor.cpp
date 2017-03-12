#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility> // pair
#include <algorithm>
using namespace std;


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
    // cout << "RIGHT" << endl; // Kirk's next move (UP DOWN LEFT or RIGHT).
  }
}
