class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int dec = 1;
    int inc = 1;
    int maxdec = 1;
    int maxinc = 1;

    int n = nums.size();

    for(int i = 0; i < n-1; i++) {
        if(nums[i] > nums[i+1]) {
            dec++;
            inc = 1;
        }
        else if(nums[i] < nums[i+1]) {
            inc++;
            dec = 1;
        }
        else {
            inc = 1;
            dec = 1;
        }

        maxdec = max(maxdec, dec);
        maxinc = max(maxinc, inc);
    }

    return max(maxdec, maxinc);
    }
};