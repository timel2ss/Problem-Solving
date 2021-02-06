#include <iostream>
#include <vector>
using namespace std;

vector<int> adjacency[32001];
bool visited[32001];
int arr[32001];

int N, M;
int count = 0;

void dfs(int start) {
    visited[start] = true;
    for(int node : adjacency[start]) {
        if(!visited[node]) {
            dfs(node);
        }
    }
    arr[N - ++count] = start;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;


    while(M--) {
        int a, b;
        cin >> a >> b;
        adjacency[a].push_back(b);
    }

    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}