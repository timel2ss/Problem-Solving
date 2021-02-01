#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int V, E, start;
vector<pair<int, int>> list[20001];
priority_queue<pair<int, int>> pq;
int d[20001];

void dijkstra(int start) {
  d[start] = 0;
  pq.push({0, start});
  while(!pq.empty()) {
    int node = pq.top().second;
    int distance = -pq.top().first;
    pq.pop();

    if(d[node] < distance)
      continue;

    for(int i = 0; i < list[node].size(); i++) {
      int next = list[node][i].first;
      int nextDistance = distance + list[node][i].second;
      if(nextDistance < d[next]) {
        d[next] = nextDistance;
        pq.push({-nextDistance, next});
      }

    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> V >> E;
  cin >> start;

  for(int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    list[u].push_back({v, w});
  }

  for(int i = 1; i <= V; i++) {
    d[i] = INT_MAX;
  }

  dijkstra(start);

  for(int i = 1; i <= V; i++) {
    if(d[i] == INT_MAX) {
      cout << "INF" << "\n";
    }
    else {
      cout << d[i] << "\n";
    }
  }
  return 0;
}