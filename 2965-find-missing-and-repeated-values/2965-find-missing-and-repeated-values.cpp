class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       vector<int>ans;
        int n=grid.size();

        unordered_map<int,int>freq;
        int repeated=0;
        int sum=0;
        for(int i=0;i<grid.size();i++){
             for(int j=0;j<grid[i].size();j++){
                int ele = grid[i][j];
                freq[ele]++;
                sum += ele;

                if(freq[ele]==2){
                     repeated = ele;
                }

             }
        }
sum-=repeated;
               n*=n;
        
        int total_sum =  n*(n+1)/2;
        int missing = total_sum - sum;
        ans.push_back(repeated);
        ans.push_back(missing);
        return ans;
        
    }
};