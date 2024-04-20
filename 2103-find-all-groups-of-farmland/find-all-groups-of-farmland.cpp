class Solution {
public:
    int n;
    int m;
    vector<vector<int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};

    void bfs(vector<vector<int>>& land, int i, int j, int& top_left, int& right_bottom) {
        queue<pair<int,int>> pq;
        pq.push({i,j});
        land[i][j] = 0;

        while (!pq.empty()) {
            pair<int,int> it = pq.front();
            pq.pop();
            top_left = max(top_left, it.first);
            right_bottom = max(right_bottom, it.second);
            for (auto dir : direction) {
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];
                if (i_ < 0 || j_ < 0 || i_ >= n || j_ >= m || land[i_][j_] != 1)
                    continue;

                land[i_][j_] = 0;
                pq.push({i_, j_});
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        n = land.size();
        m = land[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    int top_left = -1;
                    int right_bottom = -1;
                    bfs(land, i, j, top_left, right_bottom);
                    result.push_back({i, j, top_left, right_bottom});
                }
            }
        }
        return result;
    }
};
