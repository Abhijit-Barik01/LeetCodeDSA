class Solution {
public:
    int minOperations(vector<string>& logs) {

        stack<string>folderStack;

        for(const string& currentoption: logs)
        {
            if(currentoption =="../")
            {
                if(!folderStack.empty())
                {
                    folderStack.pop();
                }
            }

            else if(currentoption !="./")
            {
               folderStack.push(currentoption) ;
            }
        }
        return folderStack.size();
    }
};