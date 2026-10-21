class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        v.push_back({1});

        for(int i=1;i<numRows;i++){
            vector<int>level;

            level.push_back(1);

          for(int j=1;j<i;j++){
            int a = v[i-1][j-1]+v[i-1][j];
                level.push_back(a);
          }
          level.push_back(1);
           v.push_back(level);
        }

        return v;
    }
};