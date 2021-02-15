#include <iostream>
using namespace std;

int arr[1000001];

unsigned long long solve(int N) {
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= N; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    }
    return arr[N] % 15746;
} 

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    cout << solve(N);
    return 0;
}