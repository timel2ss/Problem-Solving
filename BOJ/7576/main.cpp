#include <iostream>
#include <queue>
using namespace std;

int M, N;
int map[1001][1001] = {0, };
int visit[1001][1001] = {0, };
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cnt = 0;

queue<pair<pair<int, int>, int>> q;

void check() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(map[i][j] == 0 && visit[i][j] == 0) 
        cnt = -1;
    }
  }
}

void bfs() {
  while(!q.empty()) {
    auto temp = q.front();
    cnt = temp.second;
    q.pop();
    
    for(int i = 0; i < 4; i++) {
      int dx = temp.first.second + direction[i][1];
      int dy = temp.first.first + direction[i][0];

      if(0 <= dx && dx < M && 0 <= dy && dy < N && map[dy][dx] == 0 && visit[dy][dx] == 0) {
        visit[dy][dx] = 1;
        q.push({{dy, dx}, cnt + 1});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> M >> N;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> map[i][j];
      if(map[i][j] == 1) {
        visit[i][j] = 1;
        q.push({{i, j}, 0});
      }
    }
  }

  bfs();
  check();
  
  cout << cnt;
  return 0;
}