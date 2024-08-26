#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* d=new ListNode(-1);
        ListNode* tmp=d;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it.second->next)
                pq.push({it.second->next->val,it.second->next});
                tmp->next=it.second;
                tmp=tmp->next;
            
        }
        return d->next;
    }
};