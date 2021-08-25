#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    void connectRecursive(Node *root)
    {
        if (!root)
            return;
        
        if (root->left)
            root->left->next = root->right;

        if (root->right)
            root->right->next = root->next ? root->next->left : NULL;
        
        connectRecursive(root->left);
        connectRecursive(root->right);
    }
public:
    Node* connect(Node* root) {

        if(!root)
            return nullptr;

        queue<Node*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            while (size--)
            {
                Node* curr = queue.front();
                queue.pop();

                if(!size)
                    curr->next = nullptr;
                else
                    curr->next = queue.front();

                if(curr->left)
                    queue.push(curr->left);
                
                if (curr->right)
                    queue.push(curr->right);
            }            
        }
        return root;        
    }
};