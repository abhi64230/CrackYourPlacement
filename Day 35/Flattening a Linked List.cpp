#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* f(Node* r, Node* s){
        Node* head=r;
        if(r==NULL ||(s && (r->data)>(s->data))){
            head=s;
            s=s->bottom;
            head->next=NULL;
        }
        else{
        r->next=NULL;
            r=r->bottom;
        }
        Node* p=head;
        while(r!=NULL && s!=NULL){
            if((r->data)>(s->data)){
                p->bottom=s;
                p=p->bottom;
                s=s->bottom;
                p->bottom=NULL;
            }
            else{
                p->bottom=r;
                p=p->bottom;
                r=r->bottom;
                p->bottom=NULL;
            }
        }
        while(r){
            p->bottom=r;
            p=p->bottom;
            r=r->bottom;
            p->bottom=NULL;
        }
        while(s){
            p->bottom=s;
            p=p->bottom;
            s=s->bottom;
            p->bottom=NULL;
        }
        // cout<<"p ";
        // Node* e=head;
        //     while(e){
        //         cout<<(e->data)<<" ";
        //         e=e->next;
        //     }
        //     cout<<endl;
        return head;
    }
    Node *flatten(Node *root) {
        Node* h=NULL,*q=root;
        while(q){
            Node *r=q;
            q=q->next;
            h=f(h,r);
            // Node* e=h;
            // while(e){
            //     cout<<(e->data)<<" ";
            //     e=e->next;
            // }
            // cout<<endl;
        }
        return h;
    }
};