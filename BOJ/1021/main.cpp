#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

void first(deque<int>& deq) {
  deq.pop_front();
}

void second(deque<int>& deq) {
  int temp = deq.front();
  deq.pop_front();
  deq.push_back(temp);
}

void third(deque<int>& deq) {
  int temp = deq.back();
  deq.pop_back();
  deq.push_front(temp);
}

bool find(deque<int>& deq, int val) {
  int middle = ceil(deq.size() / 2.0);
  for(int i = 0; i < middle; i++) {
    if(deq[i] == val){
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int size, num;
  cin >> size >> num;

  deque<int> target;
  for(int i = 0; i < num; i++) {
    int val;
    cin >> val;
    target.push_back(val);
  }

  deque<int> deq;
  for(int i = 1; i <= size; i++) {
    deq.push_back(i);
  }

  int count = 0;
  while(!target.empty()) {
    if(deq.front() == target.front()) {
      first(deq);
      target.pop_front();
    }
    else {
      if(find(deq, target.front())) {
        while(deq.front() != target.front()) {
          second(deq);
          count++;
        }
      }
      else {
        while(deq.front() != target.front()) {
          third(deq);
          count++;
        }
      }
    }
  }
  cout << count;
  return 0;
}