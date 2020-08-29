#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int oneTwoThree[11];
  oneTwoThree[1] = 1;
  oneTwoThree[2] = 2;
  oneTwoThree[3] = 4;
  for(int i = 4; i < 11; i++) {
    oneTwoThree[i] = oneTwoThree[i-1] + oneTwoThree[i-2] + oneTwoThree[i-3];
  }

  int T;
  cin >> T;

  while(T--) {
    int n;
    cin >> n;
    cout << oneTwoThree[n] << "\n";
  }

  return 0;
}