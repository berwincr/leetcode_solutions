class Solution {
public:
    int minMoves(vector<int>& nums) {
                sort(nums.begin(),nums.end());
                int n = nums.size();
                   int cmp = nums[n-1];
                   int moves=0;
                for(int i=n-2;i>=0;i--){
                  moves+= (cmp-nums[i]);
                }
return moves;
    }
};