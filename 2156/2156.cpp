#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int maxAmount[10001];

int maxValue(int a, int b, int c) {
    return a > b ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int amount;
        cin >> amount;
        v.push_back(amount);
    }
    
    maxAmount[0] = 0;
    maxAmount[1] = v[0];
    maxAmount[2] = v[0] + v[1];

    for(int i = 3; i <= n; i++) {
        maxAmount[i] = maxValue(maxAmount[i-1], maxAmount[i-2] + v[i-1], maxAmount[i-3] + v[i-2] + v[i-1]);    
    }
    cout << maxAmount[n];
    return 0;
}
