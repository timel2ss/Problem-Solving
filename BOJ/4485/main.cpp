#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;

int N;
int matrix[126][126];
int dist[126][126];
int direction[4][2] = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
priority_queue<pair<int, pair<int, int>>> pq;

int dijkstra() {
  dist[0][0] = 0;
  pq.push({0, {0, 0}});
  while(!pq.empty()) {
    int cost = -pq.top().first;
    int x = pq.top().second.second;
    int y = pq.top().second.first;
    pq.pop();

    if(dist[y][x] < cost)
      continue;
    
    for(int i = 0; i < 4; i++) {
      int dx = x + direction[i][1];
      int dy = y + direction[i][0];
      int nextCost = cost + matrix[dy][dx];

      if(0 <= dx && dx < N && 0 <= dy && dy < N) {
        if(nextCost < dist[dy][dx]) {
          dist[dy][dx] = nextCost;
          pq.push({-nextCost, {dy, dx}});
        }
      }
    }
  }
  return dist[N-1][N-1] + matrix[0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int index = 0;
  while(true) {
    cin >> N;
    if(N == 0)
      break;
    index++;

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        cin >> matrix[i][j];
        dist[i][j] = INF;
      }
    }
   
    cout << "Problem " << index << ": " << dijkstra() << "\n";
  }
  return 0;
}