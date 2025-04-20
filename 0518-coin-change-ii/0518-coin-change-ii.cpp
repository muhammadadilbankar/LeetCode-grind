class Solution {
public:
    int helper(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        //checking if we have already solved the subproblem
        if(dp[ind][amount] != -1) return dp[ind][amount];
        //base case
        if(ind == 0){
            if(amount % coins[ind] == 0) return 1;
            else return 0;
        }
        //operations for the function
        int notTake = helper(ind - 1, amount, coins, dp);
        int take = 0;
        if(coins[ind] <= amount){
            take = helper(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        return helper(n-1, amount, coins, dp);
    }
};