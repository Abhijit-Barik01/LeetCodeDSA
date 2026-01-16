class Solution {
public:
//Intitution :
//Find maximum lenth  Contigious subarray in VBars.
//Find maximum length Contigious subarray in hBars.
// As we ave to find contigious maximum length subarray we need to sort input vBars,hBars

//hight =width = min legth+1
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars),end(hBars));
        sort(begin(vBars),end(vBars));

        int maximum_VBars =1;
        int maximum_hBars=1;
        
        int consecutiveNum =1;
        for(int i=1;i<hBars.size();i++)
        {
            if(hBars[i] - hBars[i-1] == 1 )
            {
                consecutiveNum++;
            }
            else
            {
               
                consecutiveNum =1;
            }
             maximum_hBars = max(maximum_hBars,consecutiveNum);
        }


          consecutiveNum =1;
        for(int j=1; j <vBars.size();j++)
        {
            if(vBars[j] - vBars[j-1] == 1 )
            {
                consecutiveNum++;
            }
            else
            {
                consecutiveNum =1;
            }
            maximum_VBars = max(maximum_VBars,consecutiveNum);
        }

        int side = min(maximum_VBars,maximum_hBars)+1;
        return side*side;
        
    }
};