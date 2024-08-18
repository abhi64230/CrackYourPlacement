#include<iostream>
#include<vector>
using namespace std;

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long n = 1000000007;
        long long num1 =0,num2 =0;
        while(first || second){
            if(first){
                num1 = ((num1)*10)%n +first->data;
                first = first->next;
            }
            if(second){
                num2 = ((num2)*10)%n+second->data;
                second = second->next; 
            }
        }
        return ((num1)%n*(num2)%n)%n;
    }
};
