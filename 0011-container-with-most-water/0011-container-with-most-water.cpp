class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n - 1;
        int ans = INT_MIN;
        while(l < r){
            int val = min(heights[l], heights[r]) * (r - l);
            ans = max(ans, val);
            if(heights[l] < heights[r]) l++;
            else if(heights[r] < heights[l]) r--;
            else{
                l++;
                r--;
            }
        }
        return ans;
    }
};