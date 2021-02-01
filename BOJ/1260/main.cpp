#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int** matrix;
queue<int> q;
int* dfsVisit;

void bfs(int start, int size) {
  int* visit = new int[size+5];
  q.push(start);
  while(!q.empty()) {
    int temp = q.front();
    q.pop();
    cout << temp << " ";

    for(int i = 1; i <= N; i++) {
      if(matrix[temp][i] == 1 && visit[i] == 0) {
        visit[i] = 1;
        visit[start] = 1;
        q.push(i);
      }
    }
  }
  cout << "\n";
  delete[] visit;
}

void dfs(int start) {
  dfsVisit[start] = 1;
  cout << start << " ";
  for(int i = 1; i <= N; i++) {
    if(matrix[start][i] == 1 && dfsVisit[i] == 0) {
      dfs(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> V;
  matrix = new int*[N+1];
  for(int i = 0; i <= N; i++) {
    matrix[i] = new int[N+1];
  }
  for(int i = 1; i <= M; i++) {
    int node1, node2;
    cin >> node1 >> node2;

    matrix[node1][node2] = 1;
    matrix[node2][node1] = 1;
  }
  dfsVisit = new int[N+5];
  dfs(V);
  cout << "\n";

  bfs(V, N);
  delete[] dfsVisit;
  for(int i = 0; i <= N; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;  
}