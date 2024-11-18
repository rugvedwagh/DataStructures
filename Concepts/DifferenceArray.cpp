class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> dif(nums.size(), 0);

        for (auto i : queries) {
            int l = i[0];
            int r = i[1];

            dif[l]++;
            if (r + 1 < nums.size()) {
                dif[r + 1]--;
            }
        }

        for (int i = 1; i < dif.size(); i++) {
            dif[i] += dif[i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > dif[i]) {
                return false;
            }
        }

        return true;
    }
};

*/

Given Q
 ranges of the form [Li,Ri]
, find for each point x∈[1,N]
 the number of ranges that contain that point.

1≤N
, Q≤107

1≤Li≤Ri≤107



The Solution
One solution is to loop over each element for each range but this takes O(NQ)
 time. We can do better.

A difference array can be used to perform multiple range update where we need to find the answer only after performing all the queries. We can do this in O(N)
 time and space. We can update an arbitrary range in O(1)
. It is only when we need to print our final answer that we perform an O(N)
 computation.

Let N=5
. Let's create an array diff
 of size N+2
 which is initially filled with zeroes.


diff=[0,0,0,0,0,0,0]

Let Q=4
. Let's calculate the answer given these ranges — [1,3],[4,5],[3,4],[1,5]


Now, instead of iterating over each element of our array and adding the values, we can simply add the update value to index L
 of our difference array and subtract it from the index R+1
 of our difference array. We need a difference array of size N+2
 because we subtract the update value from R+1
. It is possible for R
 to be equal to N
.

Our diff
 array after each query:


diff=[0,0,0,0,0,0,0]
diff=[0,1,0,0,−1,0,0]
diff=[0,1,0,0,0,0,−1]
diff=[0,1,0,1,0,−1,−1]
diff=[0,2,0,1,0,−1,−2]


Finally, we will run a loop from 2
 to N
 (size of the array) and add diffi−1
 to diffi
.

When we added our update value to index L
 and subtracted it from index R+1
 and calculated prefix sums, for every range that we were supposed to increment by one, our update value got added to it. We subtracted the update value from index R+1
 of the difference array so that when we are summing it up, the update value we added to index L
 does not get added to elements outside the update range.

We can also perform range increment queries this way. It is not necessary for us to add a fixed value of 1
 to a range. It can be any arbitrary value.

*/
