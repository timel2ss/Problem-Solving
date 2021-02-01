#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int testCase;
  cin >> testCase;

  int N, M, value;

  for(int i = 0; i < testCase; i++) {
    queue<pair<int, int>> Q;
    priority_queue<int> H;
    cin >> N >> M;
    int count = 0;
    for(int j = 0; j < N; j++) {
      cin >> value;
      Q.push({j, value});
      H.push(value);
    }
    while(!Q.empty()) {
      int index = Q.front().first;
      int value = Q.front().second;
      Q.pop();
      if(H.top() == value) {
        H.pop();
        ++count;
        if(index == M) {
          cout << count << "\n";
          break;
        }
      }
      else {
        Q.push({index, value});
      }
    }
  }
  return 0;
}