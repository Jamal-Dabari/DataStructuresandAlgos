/*
 * Jamal Dabari
 * Hands on 6
 *
 *
 *
 *
 */

#include <iostream>
using namespace std;

struct TreeNode {
  int info;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    info = val;
    left = nullptr;
    right = nullptr;
  }
};

void inorderTraversal(TreeNode *);
void preorderTraversal(TreeNode *);
void postorderTraversal(TreeNode *);

int main() {

  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(7);
  root->right = new TreeNode(5);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(6);
  root->left->right->left = new TreeNode(5);
  root->left->right->right = new TreeNode(11);

  root->right->right = new TreeNode(9);
  root->right->right->left = new TreeNode(4);

  cout << "The Preorder Traversal looks like this: ";
  preorderTraversal(root);
  cout << endl;
  cout << "The Inorder Traversal looks like this: ";
  inorderTraversal(root);
  cout << endl;
  cout << "The Postorder Traversal looks like this: ";
  postorderTraversal(root);
  cout << endl;

  return 0;
}

void inorderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  inorderTraversal(root->left);
  cout << root->info << " ";
  inorderTraversal(root->right);
}

void preorderTraversal(TreeNode *root) {

  if (root == nullptr) {
    return;
  }

  cout << root->info << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->info << " ";
}
