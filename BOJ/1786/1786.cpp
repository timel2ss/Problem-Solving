#include <iostream>
#include <vector>
using namespace std;

vector<int> makeTable(string p) {
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

vector<int> KMP(string t, string p) {
    vector<int> result;

    int tSize = t.size();
    int pSize = p.size();
    int j = 0;
    vector<int> table = makeTable(p);

    for(int i = 0; i < tSize; i++) {
        while(j > 0 && t[i] != p[j]) {
            j = table[j - 1];
        }
        if(t[i] == p[j]) {
            if(j == pSize - 1) {
                result.push_back(i - pSize + 2);
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
    return result;
} 

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> indexes = KMP(T, P);
    cout << indexes.size() << "\n";

    for(int i : indexes) {
        cout << i << " ";
    }
    
    return 0;
}