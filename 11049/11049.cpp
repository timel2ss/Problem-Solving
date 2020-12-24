#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int opCount[501][501];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        v.push_back({r, c});
    }

    for(int l = 2; l <= N; l++) {
        for(int i = 1; i <= N - l + 1; i++) {
            int j = i + l - 1;
            opCount[i][j] = ~(1 << 31);
            for(int k = i; k <= j - 1; k++) {
                int q = opCount[i][k] + opCount[k+1][j] + v[i-1].first * v[k-1].second * v[j-1].second;
                if(q < opCount[i][j]) {
                    opCount[i][j] = q;
                }
            }
        }
    }
    
    cout << opCount[1][N];
    return 0;
}