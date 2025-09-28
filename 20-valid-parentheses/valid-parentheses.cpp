class Solution {
public:
    bool valid(char s,stack<char>&st )
    {
        char s1= st.top();

        if ((s1=='(' && s==')') || (s1=='[' && s==']') || (s1=='{' && s=='}') )
        {
            return true;
        }
         
            return false;
    }
    bool isValid(string s) {
        stack<char>st;

        for(int i =0; i< s.size(); i++)
        {
            if(  s[i] == '(' || s[i] == '{' || s[i] =='[' || st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(valid(s[i],st))
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }

        if (st.empty())
            return true;
    return false;
        
    }
};