#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  cin >> N >> K;
  
  queue<int> Q;
  vector<int> V;
  for(int i = 1; i <= N; i++) {
    Q.push(i);
  }

  for(int i = 0; i < N; i++) {
    for(int j = 1; j < K; j++) {
      int top = Q.front();
      Q.pop();
      Q.push(top);
    }
    int del = Q.front();
    Q.pop();
    V.push_back(del);
  }

  cout << "<" << V[0];
  for(int i = 1; i < N; i++) {
    cout << ", " << V[i];
  }
  cout << ">";
  return 0;
}