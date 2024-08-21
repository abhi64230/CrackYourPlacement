#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* itr1 = l1;
        ListNode* itr2 = l2;
        ListNode* itr3 = l1;
        int c = 0;
        int b=0;
        while(itr1 != NULL && itr2 != NULL){
            int a = itr1->val + itr2->val;
            a+=c;
            c=0;
            if(a>9){
                c=a/10;
                a=a%10;
            }
            itr1->val=a;
            itr2->val=a;
            itr3=itr1;
            itr1=itr1->next;
            itr2=itr2->next;
        }
        while(itr1 != NULL){
            int a = itr1->val;
            a+=c;
            c=0;
            if(a>9){
                c=a/10;
                a=a%10;
            }
            itr1->val=a;
            itr3=itr1;
            itr1=itr1->next;
        }
        while(itr2 != NULL){
            int a = itr2->val;
            a+=c;
            c=0;
            if(a>9){
                c=a/10;
                a=a%10;
            }
            itr2->val=a;
            itr3=itr2;
            itr2=itr2->next;
            b=1;
        }
        if(c!=0){
            ListNode* x = new ListNode();
            x->val=c;
            itr3->next = x;
            x->next=NULL;
        }
        if(b==1){
            return l2;
        }
        return l1;
    }
};