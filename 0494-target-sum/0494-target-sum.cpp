class Solution {
public:
    int helper(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(dp[ind][target] != -1) return dp[ind][target];
        // if(target == 0) return 1;
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[0]) return 1;
            else return 0;
        }

        int notTake = helper(ind - 1, target, nums, dp);
        int take = 0;
        if(nums[ind] <= target){
            take = helper(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = notTake + take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if(totSum - target < 0) return 0;
        if((totSum - target) % 2 == 1) return 0;
        int s2 = (totSum - target) / 2;
        vector<vector<int>>dp(n, vector<int>(s2+1, -1));
        return helper(n-1, s2, nums, dp);
    }
};