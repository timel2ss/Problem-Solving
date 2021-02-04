#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

string removeNumber(const string s) {
    string result = "";
    int size = s.size();
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        if(!isdigit(*iter)) {
            result += *iter;
        }
    }
    return result;
}

vector<int> makeTable(const string p) {
    int pSize = p.size();
    int j = 0;
    vector<int> table(pSize, 0);

    for(int i = 1; i < pSize; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = table[j - 1];
        }
        if(p[i] == p[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

bool KMP(const string s, const string p) {
    int size = s.size();
    int pSize = p.size();
    int j = 0;
    vector<int> table = makeTable(p);

    for(int i = 0; i < size; i++) {
        while(j > 0 && s[i] != p[j]) {
            j = table[j - 1];
        }
        if(s[i] == p[j]) {
            if(j == pSize - 1) {
                return true;
            }
            else {
                j++;
            }
        }
    }
    return false;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;

    string K;
    cin >> K;

    S = removeNumber(S);
    cout << KMP(S, K);
    return 0;
}