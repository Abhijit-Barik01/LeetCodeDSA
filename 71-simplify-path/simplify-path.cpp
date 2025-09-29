class Solution {
public:
    string simplifyPath(string path) {
        string temp;

        stringstream ss(path);
        vector<string>st;

        while( getline(ss,temp,'/'))
        {
            if(temp == ".." )
            {
                if(!st.empty())
                    st.pop_back();
            }
            else if( temp !="." && !temp.empty())
            {
                st.push_back(temp);
            }
        }
        string result="";
        for(auto ele:st)
        {
             result+="/" + ele;
        }

        return result.empty()? "/":result;
        
    }
};