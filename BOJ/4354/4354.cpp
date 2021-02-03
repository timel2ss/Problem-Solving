#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> makeTable(string s) {
    int size = s.size();
    int j = 0;
    vector<int> table(size, 0);

    for(int i = 1; i < size; i++) {
        while(j > 0 && s[i] != s[j]) {
            j = table[j - 1];
        }
        if(s[i] == s[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        string str;
        getline(cin, str);

        if(str == ".") {
            break;
        }

        int size = str.size();

        vector<int> table = makeTable(str);
        int maxVal = table[table.size() - 1];
        
        if(maxVal == 0 || size % (size - maxVal) != 0) {
            cout << "1\n";
        }
        else {
            cout << size  / (size - maxVal) << "\n";
        }
    }
    return 0;
}