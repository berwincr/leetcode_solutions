class Solution {
public:

    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int max_ele;
        int min_ele;
        int min_stability = INT_MAX;
        int min_idx = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int instability_score=0;
           max_ele =*max_element(nums.begin(), nums.begin()+i);
           min_ele = *min_element(nums.begin()+i , nums.begin()+ n);
           instability_score =  max_ele - min_ele;
           
           if(instability_score <=  k){
              min_stability = min(min_stability , instability_score);
              min_idx=min (min_idx , i);
           }

        }
        if(min_stability!= INT_MAX){
            return min_idx;
        } 

      return -1;
    }
};