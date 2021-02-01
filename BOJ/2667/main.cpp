#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt = 0;
int map[30][30];
int visit[30][30] = {0,};
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y) {
  cnt++;
  visit[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int dx = x + direction[i][1];
    int dy = y + direction[i][0];

    if(0 < dx && dx <= N && 0 < dy && dy <= N && map[dy][dx] == 1 && visit[dy][dx] == 0) {
      dfs(dx, dy);
    }
  }
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  vector<int> v;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(map[i][j] == 1 && visit[i][j] == 0) {
        dfs(j, i);
        v.push_back(cnt);
        cnt = 0;
      }
    }
  }

  int size = v.size();
  printf("%d\n", size);
  
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++) {
    printf("%d\n", v[i]);
  }
  return 0;
}