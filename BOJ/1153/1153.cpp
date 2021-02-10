#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000001

int N;
int prime[MAX];
vector<int> fourNumbers;

void primeNumber() {
    for(int i = 2; i <= N; i++) {
        prime[i] = i;
    }

    for(int i = 2; i <= N; i++) {
        if(prime[i] == 0) {
            continue;
        }
        
        for(int j = i + i; j <= N; j += i) {
            prime[j] = 0;
        }
   }
}

vector<int> goldBach(int N) {
    vector<int> v;
    for(int i = 2; i <= N / 2; i++) {
        if(prime[i] != 0 && prime[N - i] != 0) {
            v.push_back(i);
            v.push_back(N - i);
            break;
        }
    }
    return v;
}

void solve() {
    if(N < 8) {
        cout << -1;
        return;
    }
    
    vector<int> twoPrimeNumber;

    if(N % 2 == 1) {
        fourNumbers.push_back(2);
        fourNumbers.push_back(3);
        twoPrimeNumber = goldBach(N - 5);
        for(int primeNum : twoPrimeNumber) {
            fourNumbers.push_back(primeNum);
        }
    }
    else {
        fourNumbers.push_back(2);
        fourNumbers.push_back(2);
        twoPrimeNumber = goldBach(N - 4);
        for(int primeNum : twoPrimeNumber) {
            fourNumbers.push_back(primeNum);
        }
    }

    for(int num : fourNumbers) {
        cout << num << " ";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    primeNumber();
    solve();
    return 0;
}
