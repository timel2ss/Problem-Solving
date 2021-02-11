#include <iostream>
using namespace std;

#define MAX 8

int N, M;
int arr[MAX];

void solve(int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++) {
        arr[count] = i;
        solve(count + 1);
        arr[count] = 0;
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