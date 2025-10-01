class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
          int ConsumedBottles =0;

            while(numBottles >=numExchange )
            {

                ConsumedBottles+=numExchange;
                numBottles-=numExchange;
                numBottles++;


            }

            return ConsumedBottles+numBottles;
        
    }
};