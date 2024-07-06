class Solution {
public:
    int passThePillow(int n, int time) {

        int currentPos = 1;
        int direction = 1;

        while( time >0)
        {
            if( 1 <= currentPos+direction  && currentPos+direction <=n )
            {
                time = time-1;
                currentPos=currentPos+direction;
            }
            else
            {
                direction = direction*(-1);
            }
        }

        return currentPos;
        
    }
};