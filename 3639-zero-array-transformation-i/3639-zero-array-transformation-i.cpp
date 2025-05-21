class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            diff[l] += 1;
            diff[r+1] -= 1;
        }
        vector<int> res(n);
        int curr = 0;
        for(int i=0; i<n; i++){
            curr += diff[i];
            res[i] = curr;
        }
        for(int i=0; i<n; i++){
            if(nums[i] - res[i] > 0) return false;
        }
        return true;
    }
};