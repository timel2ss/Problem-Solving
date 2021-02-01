#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> memoryBytes;
vector<int> costs;
int minCost[10001];
int sum;

int solve(int N, int M) {
    int result = 0;
    for(int i = 1; i <= N; i++) {
        int mi = memoryBytes[i-1];
        int ci = costs[i-1];
        for(int j = sum; j >= ci; j--) {
            minCost[j] = max(minCost[j], minCost[j - ci] + mi);
        }
    }
    for(int i = 0; i <= sum; i++) {
        if(minCost[i] >= M) {
            result = i;
            break;
        }
    }
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int m;
        cin >> m;
        memoryBytes.push_back(m);
    }

    for(int i = 0; i < N; i++) {
        int c;
        cin >> c;
        sum += c;
        costs.push_back(c);
    }

    cout << solve(N, M);
    return 0;
}