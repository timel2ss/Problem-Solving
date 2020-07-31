#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  char arr[11];
  cin >> arr;

  sort(arr, arr + strlen(arr), greater<int>());
  for(int i = 0; i < strlen(arr); i++) {
    cout << arr[i];
  }
  return 0;
}