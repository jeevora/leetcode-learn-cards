#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 **/ 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
    TreeNode* buildTree(vector<int>& inorder, int i1, int i2, vector<int>& postorder, int p1, int p2) {
        if(i1 >= i2 || p1 >= p2)
            return nullptr;
        
        Tre
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size())
            return nullptr;
        return buildTree(inorder, 0, inorder.size(), postorder, 0, inorder.size());        
    }
};