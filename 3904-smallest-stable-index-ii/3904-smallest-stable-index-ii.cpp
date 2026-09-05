class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n = nums.size();
        vector<int>PrefixMax(n);
        vector<int>SuffixMin(n);
       int min_idx=INT_MAX;
        PrefixMax[0]= nums[0];
        SuffixMin[n-1] = nums[n-1];
        int min_element = INT_MAX;
        int max_element = INT_MIN;

        for(int i=1;i<n;i++){
               PrefixMax[i]= max(nums[i], PrefixMax[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            SuffixMin[i] = min(nums[i] , SuffixMin[i+1]);
        }

        for(int i=0;i<n;i++){
            int instability_score = PrefixMax[i]-SuffixMin[i];

            if(instability_score <= k){
                 return i;
            }
            instability_score=0;
        }
        
     return -1;       
            
            
            
            }
};