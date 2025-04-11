class Solution {
public:
    int countSymmetricIntegers(int low, int high) {

        int count = 0;

        for(int num = low ; num <= high ; num++)
        {
            string s = to_string(num);

            if(s.size()%2 == 0)
            {  int left = 0, right = 0;
                int mid = s.size() /2 ;

                for(int i = 0; i < mid; i++)
                {
                   left +=s[i] - '0';

                }
                
                for(int i = mid; i < s.size(); i++)
                {
                   right  +=s[i]-'0';
                   
                }
                if(left == right) count++;
             }
        }
        return count;
    }
};