class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map <int,int> PrefixSum;
         int sum=0;
        PrefixSum[0]=1;
        int count=0;
        for(int num:nums){
             sum += num;

            if(PrefixSum.find(sum-goal)!= PrefixSum.end()){
                count += PrefixSum[sum-goal];
            }
            PrefixSum[sum]++;
        }
        return count;
    }
};