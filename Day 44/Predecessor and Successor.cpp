#include<iostream>
#include<vector>
using namespace std;




class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& succ, int key) {
        pre = NULL;
        succ = NULL;
        Node* temp = root;

        // Traverse the tree to find the key
        while (temp && temp->key != key) {
            if (temp->key > key) {
                succ = temp;  // Potential successor
                temp = temp->left;
            } else {
                pre = temp;   // Potential predecessor
                temp = temp->right;
            }
        }

        if (!temp) return;  // Key not found in the tree

        // Find the predecessor (largest value in the left subtree)
        if (temp->left) {
            Node* leftTree = temp->left;
            while (leftTree->right) {
                leftTree = leftTree->right;
            }
            pre = leftTree;
        }

        // Find the successor (smallest value in the right subtree)
        if (temp->right) {
            Node* rightTree = temp->right;
            while (rightTree->left) {
                rightTree = rightTree->left;
            }
            succ = rightTree;
        }
    }
};