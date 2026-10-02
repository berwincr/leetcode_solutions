class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        sort(nums.begin(),nums.end());
int j=0;
int cnt=0;
        for(int i=0;i<nums.size();i++){
                if(i==0 || nums[i]!=nums[i-1]){
                   cnt++;
                   nums[j++]=nums[i];
                }
        }
  return cnt;      
    }
};