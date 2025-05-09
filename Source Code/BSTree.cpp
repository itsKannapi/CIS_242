//
// Created by Joey Tamondong on 4/17/25.
//
#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BinarySearchTree {
private:
    TreeNode* root;
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
        1
        }
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int val) {
        root = insert(root, val);
    }
    void inorder() {
        inorderTraversal(root);
    }
};
int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    cout << "Inorder Traversal: ";
    bst.inorder();
    cout << endl;
    // finish code work to display preorder/postorder traversals
}