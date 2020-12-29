#include <iostream>
using namespace std;

int nums[10];

int solve(int N) {
    int sum = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 10; j++) {
            if(i == 1) {
                nums[j] = 1;
            }
            else {
                if(j != 0) {
                    nums[j] += nums[j-1];
                    nums[j] %= 10007;
                }
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        sum += nums[i];    
    }
    return sum % 10007;
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