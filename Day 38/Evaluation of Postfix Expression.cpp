#include<iostream>
#include<vector>
using namespace std;


class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(int i=0; i<S.length(); i++){
            if (S[i] >= '0' && S[i] <= '9') {
                st.push(S[i] - '0');
            }
            else{
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                
                switch (S[i]) {
                    case '+': st.push(val1 + val2); break;
                    case '-': st.push(val1 - val2); break;
                    case '*': st.push(val1 * val2); break;
                    case '/': st.push(val1 / val2); break;
                }
                
            }
        }
        return st.top();
    }
};