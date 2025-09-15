class Solution {
public:
    int nextGreater( int n )
    {   int totalSum =0;
        while(n >0 )
        {
            int digit = n%10;
            n = n/10;
            totalSum += digit * digit;

        }
        return totalSum;
    }
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n != 1 && seen.find(n) == seen.end())
        {   seen.insert(n);
             n = nextGreater(n);

        }

       return n == 1;
        
    }
};