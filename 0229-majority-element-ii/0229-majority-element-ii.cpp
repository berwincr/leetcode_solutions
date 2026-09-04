class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>hm;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
              hm[nums[i]]++;
        }
        int n = nums.size();

       for(auto x : hm){
        if(x.second > n/3){
            ans.push_back(x.first);
        }
       }
        sort(ans.begin(),ans.end());
      
        return ans;
    }
};