class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num : nums){
            freq[num] ++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto [num, count] : freq){
            pq.push({count, num});
        }
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
