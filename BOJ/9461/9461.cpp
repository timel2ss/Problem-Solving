#include <iostream>
using namespace std;

long long arr[101];
int idx = 3;

long long solve(int N) {
    if(arr[N] != 0) {
        return arr[N];
    }
    else {
        for(int i = idx; i <= N; i++) {
            arr[i] = arr[i - 2] + arr[i - 3];
        }
        idx = N + 1;
        return arr[N];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    arr[1] = 1;
    arr[2] = 1;

    while(T--) {
        int N;
        cin >> N;
        cout << solve(N) << "\n";
    }

    return 0;
}