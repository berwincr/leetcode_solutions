class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> freq(100001, 0);
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
            maxDiff = max(maxDiff, diff);
        }

        for (int d = maxDiff; d > 0 && k > 0; d--) {
            if (freq[d] == 0) {
                continue;
            }

            int nextCount = freq[d - 1];
            long long move = min(k, (long long)freq[d]);

            freq[d] -= move;
            freq[d - 1] += move;
            k -= move;
        }

        if (k > 0) {
            return 0;
        }

        long long sum = 0;

        for (int d = 1; d <= maxDiff; d++) {
            sum += 1LL * d * d * freq[d];
        }

        return sum;
    }
};