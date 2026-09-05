class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>PrefixSum;

        PrefixSum[0]=1;
        int oddCount=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 !=0){
                oddCount++;
            }

                if(PrefixSum.find(oddCount-k) != PrefixSum.end()){
                          count+= PrefixSum[oddCount-k];
                }

                PrefixSum[oddCount]++;
        }
        return count;
    }
};