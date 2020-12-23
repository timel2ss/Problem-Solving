#include <iostream>
using namespace std;

unsigned long long arr[101][10];

unsigned long long stair(int N) {
    unsigned long long sum = 0;

    for(int n = 1; n <= N; n++) {
        for(int i = 0; i < 10; i++) {
            if(n == 1) {
                if(i != 0) {
                    arr[n][i] = 1;
                }
            }
            else {
                if(i == 0) {
                    arr[n][i] = arr[n-1][i+1] % 1000000000;
                }
                else if(i == 9) {
                    arr[n][i] = arr[n-1][i-1] % 1000000000;
                }
                else {
                    arr[n][i] = (arr[n-1][i-1] + arr[n-1][i+1]) % 1000000000;
                }
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        sum += arr[N][i] % 1000000000;
    }
    return sum % 1000000000;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    cout << stair(N);
    return 0;
}
