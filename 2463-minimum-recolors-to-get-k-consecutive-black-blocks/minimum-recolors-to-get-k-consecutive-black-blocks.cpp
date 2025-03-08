class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       int n = blocks.length();
       int ans =INT_MAX;
    for(int i =0 ; i <=n-k;i++)
    {
       string sub = blocks.substr(i,k);

       int countW= count(sub.begin(),sub.end(),'W');

       ans =min(ans,countW);

    }
       return ans; 
    }
};