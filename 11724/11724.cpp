#include <iostream>
#include <vector>
using namespace std;

vector<int> list[1001];
bool visit[1001];

void bfs(int start) {
    visit[start] = true;

    for(int i = 0; i < list[start].size(); i++) {
        int adjacency = list[start][i];
        if(!visit[adjacency]) {
            bfs(adjacency);
        }
    }    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    while(M--) {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    int count = 0;

    for(int i = 1; i <= N; i++) {
        if(!visit[i]) {
            bfs(i);
            count++;
        }
    }
    cout << count;
    return 0;
}