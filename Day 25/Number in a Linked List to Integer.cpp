#include<iostream>
#include<vector>
using namespace std;



/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
 #include <bits/stdc++.h>
class Solution {
public:
    int getDecimalValue(ListNode* head) {
      ListNode* temp = head;
      int sum = 0;
      while(temp){
        sum = sum * 2 + temp->val;
        temp = temp->next;
      }
      return sum; 
    }
};