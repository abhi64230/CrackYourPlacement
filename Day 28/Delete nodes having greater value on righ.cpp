#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    Node *compute(Node *head) {
        // your code goes here
        if(head->next==NULL) return head;
        Node* temp=compute(head->next);
        if(head->data>=temp->data){
            head->next=temp;
            return head;
        }
        else{
            return temp;
        }
    }
};