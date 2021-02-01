#include <iostream>
#include <queue>
using namespace std;

int main() {
  int N, M;
  int arr[200][200] = {0, };
  int dist[200][200] = {0, };
  int direct[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%1d", &arr[i][j]);
    }
  }

  queue<pair<int, int>> Q;
  Q.push({0, 0});
  int checked[200][200] = {0, };
  dist[0][0] = 1;
  while(!Q.empty()) {
    auto temp = Q.front();
    Q.pop();

    for(int i = 0; i < 4; i++) {
      int x = temp.second + direct[i][0];
      int y = temp.first + direct[i][1];
      
      if(y < N && y >= 0 && x < M && x >= 0 && arr[y][x] == 1 && checked[y][x] == 0) {
        Q.push({y, x});
        dist[y][x] = dist[temp.first][temp.second] + 1;
        if(!checked[0][0])
          checked[0][0] = 1;
        checked[y][x] = 1;
      }
    }
  }
  cout << dist[N-1][M-1];
  return 0;
}