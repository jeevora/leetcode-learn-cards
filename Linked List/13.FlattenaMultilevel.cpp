#include<iostream>
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *next;
    Node* child;
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:

    Node *head = nullptr;

    Node* flatten(Node* head) {

        if (!head)
            return nullptr;        

        Node *dumy = new Node(-1);
        dumy->next = head;
        head->prev = dumy;
        Node *curr = dumy;

        Node *headRemain = nullptr, *ptRemain = nullptr;

        while (curr->next)
        {
            if(curr->next->child){
                ptRemain = curr->next->next;                
                pushAtHead(headRemain, ptRemain);

                curr->next->next = curr->next->child;
                curr->next->child->prev = curr->next;

                Node *dumyTwo = new Node(-1);
                dumyTwo->next = curr->next->child;
                curr->next->child = nullptr;

                curr = dumyTwo;
                
                dumyTwo = nullptr;
                delete dumyTwo;
            }
            else
                curr = curr->next;
        }

        if (headRemain)
        {
            curr->next = headRemain;
            headRemain->prev = curr;
        }  

        headRemain = nullptr;
        delete headRemain;
        
        dumy = nullptr;
        delete dumy;

        head->prev = nullptr;
        return head;
    }

    void pushAtHead(Node *&head, Node *&remain)
    {
        if (!remain) return;
        
        Node* curr = remain;

        if (!head){  
            head = remain; 
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = head;
        head->prev = curr;
        head = remain;
    }

    void pushBack(int data, Node *l)
    {
        Node* temp = new Node(data);
        temp->child = l;
        Node* curr = head;

        if (!head){  
            head = temp;
            return;
        }       

        while(curr && curr->next) 
            curr = curr->next;
        curr->next = temp;
        temp->prev = curr;
    }
};

int main(){

    Solution l1, l2, l3;

    l3.pushBack(11, nullptr);
    l3.pushBack(12, nullptr);

    l2.pushBack(7, nullptr);
    l2.pushBack(8, l3.head);
    l2.pushBack(9, nullptr);
    l2.pushBack(10, nullptr);

    l1.pushBack(1, nullptr);
    l1.pushBack(2, nullptr);
    l1.pushBack(3, l2.head);
    l1.pushBack(4, nullptr);
    l1.pushBack(5, nullptr);
    l1.pushBack(6, nullptr);

    l1.flatten(l1.head);
}