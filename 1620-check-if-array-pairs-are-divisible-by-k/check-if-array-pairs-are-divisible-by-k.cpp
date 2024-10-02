class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i=0; i < n; i++)
        {
            int rem = ((arr[i]%k) +k )%k;
            mp[rem]++;
        }
         if(mp[0]%2 !=0)
            return false;
        for(int i =1 ; i<= k/2 ; i++)
        {
            if(mp[i] != mp[k-i])
            {
              return false;
            }
        }
        return true;
    }
};