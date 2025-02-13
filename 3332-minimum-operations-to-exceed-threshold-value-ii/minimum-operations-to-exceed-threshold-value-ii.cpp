class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>,greater<long>>pq(nums.begin(),nums.end());

        int count =0;

        while(!pq.empty())
        {
            long a = pq.top();
            if( a >=k)
                break;
            pq.pop();
            long b = pq.top();
            pq.pop();
            long  res = (a*2)+b;
            pq.push(res);
            count ++;
        }
        
    return count ;
        
    }
};