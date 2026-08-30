class Solution {
public:
   int helperFunc(vector<int>nums , int k){
    int left =0;
    int count=0;

     unordered_map<int,int>mp;
    for(int right=0;right<nums.size(); right++){
        if(mp[nums[right]]==0){
            k--;
        }
        mp[nums[right]]++;

        while(k<0){
            mp[nums[left]]--;
            if(mp[nums[left]]==0){
                k++;
            }
            left++;
        }
         count += right-left+1;
    }
    return count;
   }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helperFunc(nums,k)- helperFunc(nums,k-1);
    }
};