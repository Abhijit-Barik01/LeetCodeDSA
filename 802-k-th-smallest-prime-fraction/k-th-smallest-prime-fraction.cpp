class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    priority_queue<vector<double>>pq;
    int n= arr.size();

     for(int i=0 ; i<n-1; i++)
     {
        for(int j=i+1; j<n ; j++)
        {   
            double div = static_cast<double>(arr[i])/arr[j];
            pq.push(vector<double>{static_cast<double>(div),static_cast<double>(arr[i]),static_cast<double>(arr[j])});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }
     }
      
     vector<int>result(2);
     auto vec = pq.top();
     result[0]= vec[1];
     result[1] = vec[2];

     return result;
        
    }
};