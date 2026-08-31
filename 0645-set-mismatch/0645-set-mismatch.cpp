class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int n = nums.size();

    set<int> s(nums.begin(), nums.end());

    vector<int> freq(n + 1, 0);
    vector<int> ans;

 
    for(int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        if(freq[i] > 1) {
            ans.push_back(i);
            break;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(s.find(i) == s.end()) {
            ans.push_back(i);
            break;
        }
    }

    return ans;
    }
};