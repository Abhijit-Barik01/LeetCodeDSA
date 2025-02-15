class Solution {
public:
     bool check(int sqr, int currSum,int num)
     {
        if(sqr == 0)
        {
            return currSum == num;
        }

        return check(sqr/10,currSum+sqr%10,num) || check(sqr/100,currSum+sqr%100,num) || check(sqr/1000,currSum+sqr%1000,num) || check(sqr/10000,currSum+sqr%10000,num) ;
     }
    int punishmentNumber(int n) {
        int punish  = 0;
         for(int i=1; i<=n ;i++)
         {
            int sqr = i*i;

            if( check(sqr,0,i))
            {
               punish+=sqr;
            }


         }

          return punish;
    }
};