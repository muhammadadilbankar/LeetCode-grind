class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxp = 0;
        while(right < prices.size()){
            if((prices[right] - prices[left]) > 0){
                maxp = max(maxp, prices[right]-prices[left]);
                right++;
            }
            else{
                left = right;
                right ++;
            }
        }
        return maxp;
    }
};