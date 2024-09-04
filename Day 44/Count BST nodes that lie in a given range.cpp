#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
    int traverse(Node *root, int l, int h)
    {
        if(root == NULL)
            return 0;
        if(root->data < l)
            return traverse(root->right,l,h);
        if(root->data > h)
            return traverse(root->left,l,h);
        if(root->data >=l && root->data <= h)
            return 1+traverse(root->left,l,h) + traverse(root->right,l,h);
    }

    int getCount(Node *root, int l, int h)
    {
      // your code goes here
      return traverse(root,l,h);
    }
};