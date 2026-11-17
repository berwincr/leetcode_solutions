class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        vector<int>v;
        set<int>s(nums.begin(),nums.end());
        for(int i:s){
            v.push_back(i);
        }
        int n =v.size();
      int currCnt=1;
      int maxCnt=1;
        for(int i=0;i<n-1;i++){
             if(v[i]+1==v[i+1] ){
               currCnt++;
               maxCnt=max(maxCnt, currCnt);
             }
             else{
                currCnt=1;
             }
        }
        return maxCnt;
    }
};