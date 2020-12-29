#include <iostream>
#include <cctype>
#include <map>
using namespace std;

map<int, string> m1;
map<string, int> m2;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        m1.insert({i, name});
        m2.insert({name, i});
    }

    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if(isdigit(str[0])) {
            cout << m1.find(stoi(str))->second << "\n";
        }
        else {
            cout << m2.find(str)->second << "\n";
        }
    }
    return 0;
}