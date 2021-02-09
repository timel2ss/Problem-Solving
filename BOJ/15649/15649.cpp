#include <iostream>
using namespace std;

#define MAX 9

int N, M;
int arr[MAX];
bool visited[MAX];

void solve(int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            solve(count + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    solve(0);

    return 0;
}