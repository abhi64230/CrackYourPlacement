#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *aux = head->next;
       
        while(head && aux && aux->next){
            head=head->next;
            aux=aux->next->next;
            if(head==aux)return true;
        }
       
        return false;
    }
};