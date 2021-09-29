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


class BuildTreeFromPreOrderArray {
    TreeNode* buildTree(vector<int>& preorder, int p1, int p2, vector<int>& inorder, int i1, int i2) {
        if(p1 > p2)
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[p1]);
        int i = i1;
        while (i <= i2) {
            if (inorder[i] == root->val) break;
            i ++;
        }

        int diff = i - i1 - 1;
        p1++;
        
        root->left = buildTree(preorder, p1, p1 + diff, inorder, i1, i1 + diff);
        root->right = buildTree(preorder, p1 + diff + 1, p2, inorder, i + 1,  i2);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!inorder.size())
            return nullptr;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

class Solution {
    //pre-order traversal iterativelly
    int _dfs_iterativelly(TreeNode* root, int& sum){

        stack<TreeNode*> st;

        st.push(root);

        while (!st.empty())
        {
            TreeNode* tmp = st.top();
            st.pop();

            if(tmp->left && !tmp->left->left && !tmp->left->right)   
                sum += tmp->left->val;

            if(tmp->left)
                st.push(tmp->left);

            if(tmp->right)
                st.push(tmp->right);
        }
        return sum;        
    }
    // in-order traversal recursive
    int _dfs_left(TreeNode* root, int& sum){
        
        if(!root)
            return 0;
            
        _dfs_left(root->left, sum);
        
        if(root->left && !root->left->left && !root->left->right)   
            sum += root->left->val;
        
        _dfs_left(root->right, sum);

        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        return _dfs_iterativelly(root, sum);
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {3,9,20,15,7};
    //         4
    //     2       6
    // 1      3          
    vector<int> inOrder1 = {9,3,15,20,7};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    cout << sl.sumOfLeftLeaves(root);
}