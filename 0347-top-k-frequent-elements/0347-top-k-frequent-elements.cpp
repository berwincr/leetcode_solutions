class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i:nums){
            mp[i]++;
        }
        vector<pair<int,int>>v;

        for(auto& p:mp){
           v.push_back({p.second , p.first});
        }
        sort(v.begin(),v.end(), greater<pair<int, int>>());
        int m=0;
        for(auto& p: v){
             if(m==k){
                break;
             }
             ans.push_back(p.second);
             m++;
        }
return ans;

    }
};