#include <iostream>
#include <vector>
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

   int L;
   cin >> L;

   string s;
   cin >> s;

   vector<int> table = makeTable(s);

   cout << L - table[L  - 1];
   return 0;
}