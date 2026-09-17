class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        set<int>s(nums.begin(),nums.end());
        
        for(int i=1;i<=nums.size();i++){
           if(s.find(i)==s.end()){
            return i;
           }
        }
        return 0;
    }
};