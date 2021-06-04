// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node *left;
    Node *right;
  };

 private:
  Node *root;
  Node *addNode(Node *root, T value) {
    if (root == nullptr) {
      root = new Node;
      root->value = value;
      root->count = 1;
      root->left = root->right = nullptr;
    } else if (root->value > value) {
      root->left = addNode(root->left, value);
    } else if (root->value < value) {
      root->right = addNode(root->right, value);
    } else {
      root->count++;
    }
    return root;
  }
  int depthTree(Node *root) {
    if (root == nullptr)
      return 0;
    else if (root->left == nullptr && root->right == nullptr)
      return 0;
    else {
      int lh = depthTree(root->left);
      int rh = depthTree(root->right);
      return (lh > rh ? lh + 1 : rh + 1);
    }
  }
  int searchNode(Node *root, T value) {
    if (root == nullptr)
      return 0;
    else if (root->value == value)
      return root->count;
    else if (root->value < value)
      return searchNode(root->right, value);
    else
      return searchNode(root->left, value);
  }

 public:
  BST():root(nullptr);
  ~BST();
  void add(T value) {
    root = addNode(root, value);
  }
  int depth() {
    return depthTree(root);
  }
  int search(T value) {
    return searchNode(root, value);
  }
};
#endif  // INCLUDE_BST_H_
