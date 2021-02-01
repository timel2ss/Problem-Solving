#include <iostream>
#include <vector>
using namespace std;

char sequence = 'A';

class Node {
  private:
    char val;
    Node* left;
    Node* right;
  public:
    Node() : val(sequence++), left(nullptr), right(nullptr) {}

    void setLeft(Node* leftNode) {
      left = leftNode;
    }

    void setRight(Node* rightNode) {
      right = rightNode;
    }

    Node* getLeft() {
      return left;
    }
    
    Node* getRight() {
      return right;
    }
    
    char getVal() {
      return val;
    }
};

void inOrder(Node* n) {
  if(n != NULL) {
    inOrder(n->getLeft());
    cout << n->getVal();
    inOrder(n->getRight());
  }
}

void preOrder(Node* n) {
  if(n != NULL) {
    cout << n->getVal();
    preOrder(n->getLeft());
    preOrder(n->getRight());
  }
}

void postOrder(Node* n) {
  if(n != NULL) {
    postOrder(n->getLeft());
    postOrder(n->getRight());
    cout << n->getVal();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;

  vector<Node*> v;

  for(int i = 0; i < N; i++) {
    v.push_back(new Node);
  }
  for(int i = 0; i < N; i++) {
    char root, left, right;
    cin >> root >> left >> right;
    if(left != '.')
      v[(int)(root - 'A')]->setLeft(v[(int)(left - 'A')]);
    if(right != '.')
      v[(int)(root - 'A')]->setRight(v[(int)(right - 'A')]);
  }

  preOrder(v[0]);
  cout << "\n";
  inOrder(v[0]);
  cout << "\n";
  postOrder(v[0]);
  return 0;
}