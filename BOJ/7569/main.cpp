#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int M, N, H;
int boxes[101][101][101];
int visit[101][101][101];
int direction[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0 , 1}};
int cnt = 0;

queue<pair<tuple<int, int, int>, int>> q;

void check() {
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < M; k++) {
        if(boxes[i][j][k] == 0 && visit[i][j][k] == 0)
          cnt = -1;
      }
    }
  }
}

void bfs() {
  while(!q.empty()) {
    auto temp = q.front();
    int x = get<2>(temp.first);
    int y = get<1>(temp.first);
    int z = get<0>(temp.first);
    cnt = temp.second;
    q.pop();

    for(int i = 0; i < 6; i++) {
      int dx = x + direction[i][2];
      int dy = y + direction[i][1];
      int dz = z + direction[i][0];

      if(0 <= dx && dx < M && 0 <= dy && dy < N && 0 <= dz && dz < H && boxes[dz][dy][dx] == 0 && visit[dz][dy][dx] == 0) {
        visit[dz][dy][dx] = 1;
        q.push({make_tuple(dz, dy, dx), cnt + 1});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> M >> N >> H;

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < M; k++) {
        cin >> boxes[i][j][k];
        if(boxes[i][j][k] == 1) {
          q.push({make_tuple(i, j, k), 0});
          visit[i][j][k] = 1;
        }
      }
    }
  }

  bfs();
  check();
  cout << cnt;
  return 0;
}