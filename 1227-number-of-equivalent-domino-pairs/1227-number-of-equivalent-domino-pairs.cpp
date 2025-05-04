class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        unordered_map<string, int> freq;
        int count = 0;
        for(int i=0; i<n; i++){
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            string key = to_string(min(a, b)) + to_string(max(a, b));
            count += freq[key];
            freq[key]++;
        }
        return count;
    }
};