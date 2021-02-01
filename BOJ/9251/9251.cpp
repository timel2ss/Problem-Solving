#include <iostream>
#include <algorithm>
using namespace std;

int matrix[1001][1001];

void lcs(string a, string b) {
    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= b.size(); j++) {
            if(a[i - 1] == b[j - 1]) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
            }
            else {
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);
            }
        }
    }

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    lcs(a, b);

    cout << matrix[a.size()][b.size()];
    return 0;
}