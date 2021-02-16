#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 9

int N, M;
int arr[MAX];
vector<int> numbers;
bool visited[MAX];

void solve(int count) {
    if(count == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            arr[count] = numbers[i];
            visited[i] = true;
            solve(count + 1);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    solve(0);

    return 0;
}