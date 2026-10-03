class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>rem;
        k = k % nums.size();
        int rotate_ele = nums.size()-k;

        for(int i=0;i<rotate_ele;i++){
           rem.push_back(nums[i]);
        }
int j=0;
        for(int i=rotate_ele;i<nums.size();i++){
             nums[j++]=nums[i];
        }
        for(int i=0;i<rem.size();i++){
    nums[j++]= rem[i];
}
        return;
    }
};