class Solution {
public:
    string longestPrefix(string s) {
        int stringSize = s.size();
        int j = 0;
        vector<int> table(stringSize, 0);
        
        for(int i = 1; i < stringSize; i++) {
            while(j > 0 && s[i] != s[j]) {
                j = table[j - 1];
            }
            if(s[i] == s[j]) {
                table[i] = ++j;
            }
        }
        
        string ans = "";
        for(int i = 0; i < table[stringSize - 1]; i++) {
            ans += s[i];
        }
        return ans;
    }
};