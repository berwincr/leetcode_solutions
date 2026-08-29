class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> nums_with_indices;
         for(int i=0;i<nums.size();i++){
            nums_with_indices.push_back({nums[i],i});

         }

         sort(nums_with_indices.begin(), nums_with_indices.end());

        int n= nums.size();
         int i=0;
         while(i<n){
            int j=i;
             while (j + 1 < n &&  nums_with_indices[j + 1].first - nums_with_indices[j].first <= limit) {
                j++;
            }

            vector<int>indices;

            for(int k=i;k<=j;k++){
                indices.push_back(nums_with_indices[k].second);
            }
            sort(indices.begin(),indices.end());

            for (int k = 0; k < indices.size(); k++) 
            {
                nums[indices[k]] = nums_with_indices[i + k].first;
            }
            
            i = j + 1;
      }
      return nums;
    }
};