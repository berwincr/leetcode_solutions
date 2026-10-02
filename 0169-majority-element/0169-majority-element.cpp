class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int votes=0;
        int candidate=-1;
int n =nums.size();
        for(int i=0;i<nums.size();i++){
            if(votes==0){
                candidate = nums[i];
                votes++;
            }
            else{
                if(candidate == nums[i]){
                    votes++;
                }
                else{
                    votes--;
                }
            }
        }

        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==candidate){
           count++;
            }
        }

        if(count>n/2){
            return candidate;
        }
return -1;
    }
};