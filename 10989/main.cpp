#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  int arr[10000];

  for(int i = 0; i < 10000; i++) {
    arr[i] = 0;
  }

  while(N--) {
    int num;
    cin >> num;
    arr[num-1] += 1;
  }

  for(int i = 0; i < 10000; i++) {
    while(arr[i]--) {
      cout << i+1 << "\n";
    }
  }
  return 0;
}