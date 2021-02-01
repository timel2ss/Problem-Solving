#include <iostream>
using namespace std;

void merge(int arr[], int size, int p, int q, int r) {
  int i = p, j = q + 1, k = p;
  int* temp = new int[size];
  while(i <= q && j <= r) {
    if(arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    }
    else {
      temp[k++] = arr[j++];
    }
  }
  while(i <= q) {
    temp[k++] = arr[i++];
  }
  while(j <= r) {
    temp[k++] = arr[j++];
  }

  for(int l = p; l <= r; l++) {
    arr[l] = temp[l];
  }
  delete[] temp;
}

void mergeSort(int arr[], int size, int p, int r) {
  if(p < r) {
    int q = (p + r) / 2;
    mergeSort(arr, size, p, q);
    mergeSort(arr, size, q+1, r);
    merge(arr, size, p, q, r);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  int* arr = new int[N];

  for(int i = 0; i < N; i++) {
    int val;
    cin >> val;
    arr[i] = val;
  }

  mergeSort(arr, N, 0, N-1);
  for(int i = 0; i < N; i++) {
    cout << arr[i] << "\n";
  }

  delete[] arr;
  return 0;
}