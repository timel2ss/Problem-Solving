#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visit[100002];
int cnt = 0;

queue<pair<int, int>> q;

void bfs(int start) {
  q.push({start, 0});
  visit[start] = 1;
  while(!q.empty()) {
    auto temp = q.front();
    int position = temp.first;
    cnt = temp.second;
    q.pop();

    int walkBackward = position - 1;
    int walkForward = position + 1;
    int teleport = position * 2;

    if(position == K)
      break;

    if(walkBackward < 100001 && visit[walkBackward] == 0) {
      q.push({walkBackward, cnt + 1});
      visit[walkBackward] = 1;
    }
    if(walkForward < 100001 && visit[walkForward] == 0) {
      q.push({walkForward, cnt + 1});
      visit[walkForward] = 1;
    }
    if(teleport < 100001 && visit[teleport] == 0) {
      q.push({teleport, cnt + 1});
      visit[teleport] = 1;
    }

  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  bfs(N);
  
  cout << cnt;
  return 0;
}