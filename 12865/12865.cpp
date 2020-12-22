#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> items;
int backpack[105][100005];

int knapsack(int N, int K) {
    for(int i = 1; i <= N; i++) {
        int wi = items[i-1].first;
        int vi = items[i-1].second;
        for(int j = 1; j <= K; j++) {
            if(j < wi) {
                backpack[i][j] = backpack[i-1][j];
            }
            else {
                backpack[i][j] = max(backpack[i-1][j - wi] + vi, backpack[i-1][j]);
            }
        }
    }
    return backpack[N][K];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;
        items.push_back({W, V});
    }

    cout << knapsack(N, K);
    return 0;
}