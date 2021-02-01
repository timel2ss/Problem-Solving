#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int nodes, edges;
  cin >> nodes;
  cin >> edges;

  vector<int> v;
  queue<int> q;

  int** matrix = new int*[nodes+1];
  for(int i = 0; i <= nodes; i++) {
    matrix[i] = new int[nodes];
  }

  while(edges--) {
    int node1, node2;
    cin >> node1 >> node2;

    matrix[node1][node2] = 1;
    matrix[node2][node1] = 1;
  }

  q.push(1);
  int* visit = new int[nodes+1];
  int cnt = 0;

  while(!q.empty()) {
    int worm = q.front();
    q.pop();

    for(int i = 1; i <= nodes; i++) {
      if(matrix[worm][i] == 1 && visit[i] == 0) {
        q.push(i);
        visit[i] = 1;
        visit[1] = 1;
        cnt++;
      }
    }
  }

  cout << cnt;
  for(int i = 0; i <= nodes; i++) {
    delete[] matrix[i];
  }

  delete[] matrix;
  delete[] visit;

  return 0;
}