class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        bool ans = false;
        for(int i=2; i<n; i++){
            if(arr[i]%2 == 1 && arr[i-1]%2==1 && arr[i-2]%2==1) ans= true;
        }
        return ans;
    }
};