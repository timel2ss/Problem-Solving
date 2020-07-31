#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> heap;

  for(int i = 0; i < N; i++) {
    int val;
    cin >> val;
    if(val != 0) {
      heap.push(val);
    }
    else {
      if(heap.empty()) {
        cout << "0\n";
      }
      else {
        cout << heap.top() << "\n";
        heap.pop();
      }
    }
  }
  return 0;
}