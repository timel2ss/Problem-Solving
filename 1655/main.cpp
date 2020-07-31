#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> min_heap;
  priority_queue<int> max_heap;

  for(int i = 0; i < N; i++) {
    int val;
    cin >> val;

    if(max_heap.empty()) {
      max_heap.push(val);
    }
    else if(max_heap.size() == min_heap.size()) {
      max_heap.push(val);
    }
    else {
      min_heap.push(val);
    }

    if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
      int a = max_heap.top();
      int b = min_heap.top();

      max_heap.pop();
      min_heap.pop();        max_heap.push(b);
      min_heap.push(a);
    }

    cout << max_heap.top() << "\n";
  }

  return 0;  
}