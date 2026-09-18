class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());
set<int>ins;

vector<vector<int>>ans;
        for(int i=0;i<nums1.size();i++){
             if(s2.find(nums1[i])==s2.end()){
                     ins.insert(nums1[i]);

             }
        }

        vector<int>v(ins.begin() ,ins.end());
        ans.push_back(v);

        ins.clear();
        v.clear();

         for(int i=0;i<nums2.size();i++){
             if(s1.find(nums2[i])==s1.end()){
                    ins.insert(nums2[i]);
             }
        }

        v=vector<int>(ins.begin() ,ins.end());
        ans.push_back(v);

        return ans;
    }
};