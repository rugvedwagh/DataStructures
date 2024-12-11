class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        vector<long long> mp(k, LLONG_MAX);
        long long maxSum = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int mod = i % k;

            if (i >= k) {
                maxSum = max(maxSum, preSum[i] - mp[mod]);
            }

            mp[mod] = min(mp[mod], preSum[i]);
        }

        return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};

/*
In an array if we find two indexes which on dividing by an integer 'k', give the same remainder then,
the distance between those two indexs is completely divisible by (k)."

Suppose for eg, i%k == 1 and j%k == 1, then this implies that (j-i) % k == 0.

https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
*/
