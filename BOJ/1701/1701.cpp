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


    string str;
    getline(cin, str);

    int size = str.size();
    int result = 0;

    for(int i = 0; i < size; i++) {
        string substr = str.substr(i, size);
        vector<int> table = makeTable(substr);
        
        sort(table.begin(), table.end());
        result = max(result, table[table.size() - 1]);
    }
    cout << result;
    return 0;
}