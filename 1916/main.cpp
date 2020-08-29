#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;

int N, M;
int start, end_;
vector<pair<int, int>> v[1001];

int dijkstra(int start, int end_) {
  vector<int> d(N+1, INF);
  priority_queue<pair<int, int>> pq;
  d[start] = 0;
  pq.push({0, start});

  while(!pq.empty()) {
    int node = pq.top().second;
    int cost = pq.top().first;
    pq.pop();
    
    if(d[node] < cost)
      continue;
    
    for(int i = 0; i < v[node].size(); i++) {
      int next = v[node][i].first;
      int nextCost = cost + v[node][i].second;

      if(nextCost < d[next]) {
        d[next] = nextCost;
        pq.push({nextCost, next});
      }
    }
  }
  return d[end_];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  cin >> M;

  for(int i = 0; i < M; i++) {
    int start, dest, cost;
    cin >> start >> dest >> cost;
    v[start].push_back({dest, cost});
  }

  cin >> start >> end_;

  cout << dijkstra(start, end_);
  return 0;
}