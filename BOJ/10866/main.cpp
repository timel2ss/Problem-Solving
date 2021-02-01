#include <iostream>
using namespace std;

class Deque {
  private:
    int* arr;
    int front;
    int rear;
    int size;
    int count;
  
  public:
    Deque() {
      arr = new int[10001];
      front = 0;
      rear = 0;
      size = 10001;
      count = 0;
    }

    ~Deque() {
      delete[] arr;
    }

    bool empty() {
      return front == rear;
    }

    void empty_print() {
      if(empty()) {
        cout << "1\n";
      }
      else {
        cout << "0\n";
      }
    }

    void size_print() {
      cout << count << "\n";
    }

    void push_front(int X) {
      arr[front] = X;
      front = (front - 1 + size) % size;
      count++;
    }

    void push_back(int X) {
      rear = (rear + 1) % size;
      arr[rear] = X;
      count++;
    }

    void pop_front() {
      if(empty()) {
        cout << "-1\n";
      }
      else {
        front = (front + 1) % size;
        cout << arr[front] << "\n";
        count--;
      }
    }

    void pop_back() {
      if(empty()) {
        cout << "-1\n";
      }
      else {
        cout << arr[rear] << "\n";
        rear = (rear - 1 + size) % size;
        count--;
      }
    }

    void front_print() {
      if(empty()) {
        cout << "-1\n";
      }
      else {
        cout << arr[(front+1) % size] << "\n";
      }
    }

    void back_print() {
      if(empty()) {
        cout << "-1\n";
      }
      else {
        cout << arr[rear] << "\n";
      }
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int commands;
  cin >> commands;
  Deque deque;

  for(int i = 0; i < commands; i++) {
    string command;
    int val;
    cin >> command;
    if(command == "push_back") {
      cin >> val;
      deque.push_back(val);
    }
    else if(command == "push_front") {
      cin >> val;
      deque.push_front(val);
    }
    else if(command == "front") {
      deque.front_print();
    }
    else if(command == "back") {
      deque.back_print();
    }
    else if(command == "size") {
      deque.size_print();
    }
    else if(command == "empty") {
      deque.empty_print();
    }
    else if(command == "pop_front") {
      deque.pop_front();
    }
    else if(command == "pop_back") {
      deque.pop_back();
    }
  }
  return 0;
}