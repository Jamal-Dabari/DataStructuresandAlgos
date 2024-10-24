/* Hands-on-7
 * Jamal Dabari
 */

#include <iostream>
using namespace std;

struct TreeNode {
  int info;
  TreeNode *left;
  TreeNode *right;
};

void inOrder(TreeNode *);
void insert(TreeNode *&, int);
int countNodes(TreeNode *);
TreeNode *TreeSearch(TreeNode *, int);

int main() {
  TreeNode *tree = nullptr;
  insert(tree, 10);
  insert(tree, 18);
  insert(tree, 7);
  insert(tree, 2);
  insert(tree, 20);
  insert(tree, 15);

  cout << "Binary Search Tree Taversal: ";
  inOrder(tree);
  cout << endl;

  cout << "Binary Search Tree Node Count:";
  int num = countNodes(tree);
  cout << num << endl;

  int searchValue = 7;
  int searchValue2 = 13;
  TreeNode *searchResult = TreeSearch(tree, searchValue);
  TreeNode *searchResult2 = TreeSearch(tree, searchValue2);

  cout << "Binary Search Tree Search: ";

  if (searchResult != nullptr) {
    cout << searchValue << " is in the tree." << endl;
  } else {
    cout << searchValue << " is not in the tree." << endl;
  }

  if (searchResult2 != nullptr) {
    cout << searchValue2 << " is in the tree." << endl;
  } else {
    cout << searchValue2 << " is not in the tree." << endl;
  }

  return 0;
}

void inOrder(TreeNode *node) {
  if (node == nullptr)
    return;
  inOrder(node->left);
  cout << node->info << " ";
  inOrder(node->right);
}

void insert(TreeNode *&node, int val) {
  if (node == nullptr) {
    node = new TreeNode;
    node->info = val;
    node->left = nullptr;
    node->right = nullptr;
  } else if (val < node->info) {
    insert(node->left, val);
  } else {
    insert(node->right, val);
  }
}

int countNodes(TreeNode *node) {
  if (node == nullptr)
    return 0;
  return 1 + countNodes(node->left) + countNodes(node->right);
}

TreeNode *TreeSearch(TreeNode *node, int value) {
  if (node == nullptr || node->info == value) {
    return node;
  }
  if (value < node->info) {
    return TreeSearch(node->left, value);
  } else {
    return TreeSearch(node->right, value);
  }
}
