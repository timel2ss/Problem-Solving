#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  queue<int> Q;
  int N;

  cin >> N;
  for(int i = 1; i <= N; i++) {
    Q.push(i);
  }

  for(int i = 1; i < N; i++) {
    Q.pop();
    int top = Q.front();
    Q.pop();
    Q.push(top);
  }

  cout << Q.front();
  return 0;
}