class Solution {
public:
    int n;
    void solve(string &tiles ,vector<bool>&used,string &result,unordered_set<string>&ans)
    {
        ans.insert(result);

        for(int i=0; i<n;i++)
        {
           if(used[i])
            continue;

            used[i] =true;
            result.push_back(tiles[i]);
            solve(tiles,used,result,ans);
            used[i] =false;
            result.pop_back();
        }


    }
    int numTilePossibilities(string tiles) {
        n= tiles.length();

        vector<bool>used(n,false);
        string result="";
        unordered_set<string>ans;

        solve(tiles,used,result,ans);

        return ans.size() -1;


        
    }
};