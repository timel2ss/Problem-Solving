#include <iostream>
#include <vector>
using namespace std;

vector<int> makeTable(string p) {
    int patternSize = p.size();
    int j = 0;

    vector<int> table(patternSize, 0);

    for(int i = 1; i < patternSize; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = table[j - 1];
        }
        if(p[i] == p[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

bool KMP(string s, string p) {
    int stringSize = s.size();
    int patternSize = p.size();
    vector<int> table = makeTable(p);
    int j = 0;
    
    for(int i = 0; i < stringSize; i++) {
        while(j > 0 && s[i] != p[j]) {
            j = table[j - 1];
        }
        if(s[i] == p[j]) {
            if(j == patternSize - 1) {
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

    string s, p;
    cin >> s;
    cin >> p;

    cout << KMP(s, p);
    return 0;
}