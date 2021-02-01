#include <iostream>
using namespace std;

int map[60][60];
int visit[60][60];
int M, N, K;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cnt = 0;

void dfs(int x, int y) {
  visit[y][x] = 1;

  for(int i = 0; i < 4; i++) {
    int dx = x + direction[i][1];
    int dy = y + direction[i][0];

    if(0 <= dx && dx < M && 0 <= dy && dy < N && map[dy][dx] == 1 && visit[dy][dx] == 0) {
      dfs(dx, dy);
    }
  }  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  for(int i = 0; i < T; i++ ) {
    cin >> M >> N >> K;
    for(int j = 0; j < K; j++) {
      int X, Y;
      cin >> X >> Y;
      map[Y][X] = 1;
    }
    for(int a = 0; a < N; a++) {
      for(int b = 0; b < M; b++) {
        if(map[a][b] == 1 && visit[a][b] == 0) {
          dfs(b, a);
          cnt++;
        }
      }
    }
    cout << cnt << "\n";

    for(int k = 0; k < N; k++) {
      for(int l = 0; l < M; l++) {
        map[k][l] = 0;
        visit[k][l] = 0;
      }
    }
    cnt = 0;
  }
  

  return 0;
}