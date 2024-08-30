#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int>stk;
        for(int i=0;i<mat.size();i++){
            stk.push(i);    
        }
        
        while(stk.size()!=1){
            int a=stk.top();stk.pop();
            int b=stk.top();stk.pop();
            
            if(mat[a][b]){//confusion
                // a is not celerity , b might be
                stk.push(b);
            }
                else{
                    // b is not celebrity , a might be
                    stk.push(a);
                }
            }
             //step 3-> check f the single elemnt is celebrity
        int mightbeceleb=stk.top();stk.pop();
        
        //celeb should not know anyone
        for(int i=0;i<mat.size();i++){
            if(mat[mightbeceleb][i]!=0) return -1;
        }
        //everyone should know celeb
        for(int i=0;i<mat.size();i++){
            if(mat[i][mightbeceleb]==0 && i!=mightbeceleb){
                return -1;
            }
        }
        
        return mightbeceleb;
        
        
       
        
    }
};
