class Solution{
public:
    int recursion(int W, int ind, int val[], int wt[], vector<vector<int>> &dp){
        if(ind==0){
            return (int(W/wt[0]))*val[0];
        }
        
        if(dp[ind][W] != -1){
            return dp[ind][W];
        }
        
        int nottake = 0 + recursion(W, ind-1, val, wt, dp);
        int take = 0;
        
        if(wt[ind]<=W){
            take = val[ind] + recursion(W-wt[ind], ind, val, wt, dp);
        }
        
        dp[ind][W] = max(take, nottake);
        return dp[ind][W];
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        // code here
        return recursion(W,N-1,val,wt, dp);
    }
};
