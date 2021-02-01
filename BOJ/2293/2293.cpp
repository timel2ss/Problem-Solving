#include <iostream>
#include <vector>
using namespace std;

vector<int> coins;
int val[10001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    coins.push_back(0);
    val[0] = 1;

    for(int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j >= coins[i]) {
                val[j] += val[j - coins[i]];
            }
        }
    }

    cout << val[k];
    return 0;
}