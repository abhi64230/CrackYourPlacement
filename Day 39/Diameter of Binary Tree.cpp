#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    // this funcation will return levels of the tree subject to root
    int levelsOfTree(TreeNode* root){
        if(root==NULL) return 0; 
        return 1 + max(levelsOfTree(root->left),levelsOfTree(root->right));
    }
    // this funcation will visit every node as root & will get the maximum diameter
    void visitNode(TreeNode* root,int &MaxdiaMeter){
        // base case
        if(root==NULL) return; 
        int diaMeter = levelsOfTree(root->left) + levelsOfTree(root->right);
        MaxdiaMeter=max(diaMeter,MaxdiaMeter);
        // recursion
        visitNode(root->left,MaxdiaMeter);
        visitNode(root->right,MaxdiaMeter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int MaxdiaMeter=0;
        visitNode(root,MaxdiaMeter);
        return MaxdiaMeter;
    }
};