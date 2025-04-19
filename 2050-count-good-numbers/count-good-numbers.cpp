class Solution {
public:
    const int M= 1e9+7;

    long long findPower(long long a, long long b)
    {
        if(b == 0)
            return 1;
        long long  half = findPower(a,b/2);
        long long result = (half*half)%M;

        if(b %2 ==1)
        {
            result= (result*a)%M;
        }

        return result;



    }
    int countGoodNumbers(long long n) {
         
         long long  even = (n+1)/2;
         long long  odd = n/2;

         return (long long) (findPower(4,odd)*findPower(5,even))%M;

    }
};