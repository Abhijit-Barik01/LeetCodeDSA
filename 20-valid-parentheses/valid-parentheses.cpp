class Solution {
public:
    
    bool matching(char a, char b){
        return ((a=='(' && b==')' )  ||(a=='{' && b=='}') ||( a=='[' && b==']') );
    }
    
    bool isValid(string s) {
        stack<char>s1;
        for(char x:s)
        {
            if(x=='('||x=='{'||x=='[')
            {
                s1.push(x);
                
            }
            
        else 
            {
                
                
                if(s1.empty()==true) //when input')'
                     return false;
                     
                if(matching(s1.top(),x)==false)
                    return false;
                else
                    s1.pop();
                
            }
        }
        return(s1.empty()==true);
    }
};