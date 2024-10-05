class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n= skill.size();

        long long  totalchemisitry = skill[0]*skill[n-1];
        int low =1;
        int high = n-2;
        int targetSkill = skill[0]+skill[n-1];

        while(low < high)
        {
              int cuurentSkill = skill[low]+skill[high];
              if(cuurentSkill != targetSkill)
                return -1;
              totalchemisitry +=(long long)skill[low]*(long long)skill[high] ;
              low++;
              high--;
        }
        return totalchemisitry;
    }
};