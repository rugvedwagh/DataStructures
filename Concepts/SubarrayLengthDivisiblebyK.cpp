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
This is an application of the Pigeonhole Principle. The idea is that since there are n possible remainders when an integer is divided by n
that at least two of the n+1 integers in the set {x0,x1,…,xn} must have the same remainder when divided by n.
If they have the same remainder when divided by n, their difference is divisible by n.

The possible remainders when an integer is divided by n are 0,1,2,…,n−1.
If you have n integers, then it is possible for each of them to have a different remainder when divided by n However, if you have n+1
integers, at least two of them must have the same remainder when divided by n, Hence, in the set {x0,x1,…,xn}
, there are two numbers xi and xj with i≠j, that have the same remainder when they are divided by n.
Thus, there exist k,m,r∈N, with 0≤r≤n−1, such that

xixj=kn+r=mn+r

If we take their difference, we obtain

xi−xj=(kn+r)−(mn+r)=kn−mn=(k−m)n

Therefore, xi−xj is divisible by n.
https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
*/
