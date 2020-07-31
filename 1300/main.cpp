#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, k;
  cin >> N >> k;

  int start = 1;
  int end = k;
  int res = 0;

  while(start <= end) {
    int count = 0;
    int mid = (start + end) / 2;
    for(int i = 1; i <= N; i++) {
      count += min(mid / i, N);
    }
    if(count < k) {
      start = mid + 1;
    }
    else {
      res = mid;
      end = mid - 1;
    }
  }
  cout << res;
  return 0;
}