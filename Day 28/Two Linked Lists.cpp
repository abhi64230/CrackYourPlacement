#include<iostream>
#include<vector>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *pointerA = headA;
        ListNode *pointerB = headB;

        while (pointerA != pointerB) {
            pointerA = pointerA == nullptr ? headB : pointerA->next;
            pointerB = pointerB == nullptr ? headA : pointerB->next;
        }

        return pointerA;
    }
};