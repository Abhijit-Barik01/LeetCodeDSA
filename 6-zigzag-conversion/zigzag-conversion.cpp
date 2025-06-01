class Solution {
public:
    string convert(string s, int numRows) {

        int n  = int(s.length());
        if (numRows == 1) return s;
        int numrow =0 , numcol = 0;
        
        int stringIndex= 0;

        int section = ceil(n/(2*numRows -2.0));

        int numCols = section*(numRows-1) ;
        vector<vector<char>>matrix(numRows,vector<char>(numCols,' '));

        while(stringIndex < n)
        {

            //down
            while(stringIndex < n &&  numrow < numRows)
            {
                matrix[numrow][numcol] = s[stringIndex];
                stringIndex++;
                numrow++;
            }

            //go up 
            numrow = numrow-2;
            numcol++;

              while(stringIndex < n &&  numrow > 0 && numcol < numCols)
            {
                matrix[numrow][numcol]  = s[stringIndex];
                stringIndex++;
                numrow--;
                numcol++;
            }

        }
        string answer = "";

        for(auto row: matrix)
        {
            for(auto charecter:row)
            {
                    if(charecter !=' ')
                    {
                        answer  +=charecter;
                    }
            }
        }

    return answer;
        
    }
};