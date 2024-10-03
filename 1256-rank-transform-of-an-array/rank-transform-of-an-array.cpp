class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      vector<int> sortedArr(arr);
      map<int,int>numToRank;
      sort(sortedArr.begin(),sortedArr.end());
        int rank =1;

       for(int i= 0; i< sortedArr.size();i++ )
       {
         
           if(i > 0 && sortedArr[i] > sortedArr[i-1])
           {
               rank++;
               
           }
           numToRank[sortedArr[i]]=rank;
       }
         for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }
      
        return arr;
    }
};