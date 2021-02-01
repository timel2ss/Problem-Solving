#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    stack<int> s;

    int N;
    cin >> N;

    int index;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    vector<int> ans(v.size(), -1);

    for(int i = 0; i < N; i++) {
        while(!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}