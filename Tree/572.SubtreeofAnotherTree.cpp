#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;


int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {1,2,2};
    vector<int> inOrder1 = {1,2,2};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    // vector<int> preOrder1 = {0};
    // vector<int> inOrder1 = {0};

    // TreeNode* root1 = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    for(auto it: sl.findMode(root))
        cout << it << endl;
}