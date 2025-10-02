class Solution {
public:
int calculate(stack<int> &st,string token)
{
    int a = st.top();
    st.pop();
    int b = st.top();
     st.pop();

    if(token == "+")
        return (long)a+(long)b;

    if(token == "-")
        return b-a;
    
    if(token == "*")
        return (long)a*(long)b;

    if( token =="/")
        return b/a;
    return -1;
}
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto &token:tokens)
        {
            if( token =="+" || token =="-" || token == "*" || token =="/")
            {
               int result = calculate(st,token);
               st.push(result);
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};