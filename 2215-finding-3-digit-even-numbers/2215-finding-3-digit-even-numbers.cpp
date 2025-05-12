class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j || j==k || i==k) continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num >= 100 && num%2 == 0) temp.insert(num);
                }
            }
        }
        vector<int> ans;
        for(auto e : temp){
            ans.push_back(e);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};