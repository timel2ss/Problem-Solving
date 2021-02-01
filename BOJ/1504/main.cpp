#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int N, E;
vector<pair<int, int>> v[801];
int v1, v2;
priority_queue<pair<int, int>> pq;

vector<int> dijkstra(int start, int end) {
  vector<int> d(end, INF);
  d[start] = 0;
  pq.push({0, start});

  while(!pq.empty()) {
    int node = pq.top().second;
    int distance = -pq.top().first;
    pq.pop();
    
    if(d[node] < distance)
      continue;

    for(int i = 0; i < v[node].size(); i++) {
      int next = v[node][i].first;
      int nextDistance = distance + v[node][i].second;

      if(nextDistance < d[next]) {
        d[next] = nextDistance;
        pq.push({-nextDistance, next});
      }
    }
  }
  return d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> E;

  for(int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }

  cin >> v1 >> v2;

  vector<int> result = dijkstra(1, N+1);
  vector<int> temp1 = dijkstra(v1, N+1);
  vector<int> temp2 = dijkstra(v2, N+1);

  int answer = min({ result[v1] + temp1[v2] + temp2[N], result[v2] + temp2[v1] + temp1[N] });

  if(answer >= INF || answer < 0)
    cout << -1 << "\n";
  else
    cout << answer << "\n";
  
  return 0;
}