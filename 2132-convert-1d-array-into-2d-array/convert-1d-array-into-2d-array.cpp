class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
          vector<vector<int>>result(m,vector<int>(n,0));
                if (m * n != original.size()) {
            // If not, return an empty 2D array
            return {};
        }

          for(int k=0; k< original.size();k++)
          {
            result[k/n][k%n]=original[k];
          }


          return result;
        
    }
};