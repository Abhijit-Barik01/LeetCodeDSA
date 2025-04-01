#define ll long long
class Solution {
public:
   long long mostPoints(vector<vector<int>>& questions){
       int n = questions.size();
       
       ll dp[n + 1];
       dp[n] = 0; // Base case

       for(int i = n - 1; i >= 0; i--){
           // Pick Current
           ll pick = ((i + questions[i][1] + 1) > n ? 0 : dp[i + questions[i][1] + 1]) + questions[i][0];

           // Skip Current
           ll skip = dp[i + 1];

           dp[i] = max(pick, skip);
       }
       return dp[0];
   }
};