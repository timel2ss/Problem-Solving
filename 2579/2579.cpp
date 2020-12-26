#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> scores;
int maxScore[301];

int maxValue(int n) {
    if(n >= 1) {
        maxScore[1] = scores[1];
    }
    if(n >= 2) {
        maxScore[2] = max(scores[2], maxScore[1] + scores[2]); 
    }

    for(int i = 3; i <= n; i++) {
        maxScore[i] = max(maxScore[i-3] + scores[i-1] + scores[i], maxScore[i-2] + scores[i]);
    }
    return maxScore[n];
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    scores.push_back(0);

    for(int i = 0; i < n; i++) {
        int score;
        cin >> score;
        scores.push_back(score);
    }

    cout << maxValue(n);
    return 0;
}