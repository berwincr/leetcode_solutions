class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        int candidate;
        int j=0;
        int unique=0;
        for(int i=0;i<nums.size();i++){
              candidate = nums[i];
         if(i!=0 && candidate==nums[i-1]){
            cnt++;
            if(cnt<2){
                unique+=1;
                nums[j++]=nums[i];
            }
         }
         else if(i==0 || candidate != nums[i-1]){
            unique+=1;
            cnt=0;
            nums[j++]=nums[i];
         }
        }
        return unique;
    }
};