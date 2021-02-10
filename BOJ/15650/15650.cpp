#include <iostream>
using namespace std;

#define MAX 9

int N, M;
int arr[MAX];
int visited[MAX];

void solve(int count, int idx) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = idx; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            solve(count + 1, i);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    solve(0, 1);
    return 0;
}