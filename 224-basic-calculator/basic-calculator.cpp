class Solution {
public:
     stack<int>st;
    int calculate(string s) {

        int sign  = 1;
        int number =0;
        int result =0;

        for(int i =0; i<s.size();i++)
        {
            if( isdigit(s[i]))
            {
                number = number*10+(s[i]-'0');
            }
            else if(s[i] =='+')
            {
                result += number*sign;
                sign = 1;
                number =0;
            }
            else if(s[i] == '-')
            {
                result += number*sign;
                sign = -1;
                number =0;
            }
            else if (s[i]=='(')
            {
                st.push(result);
                st.push(sign);
                number =0;
                result =0;
                sign =1;
            }
            else if(s[i] == ')')
            {
                result += sign*number;
                number = 0;
                int top = st.top(); st.pop();
                result *=top;
                result +=st.top();
                st.pop();
            }
        }

       result +=number*sign; // end element;
       return result;

        
    }
};