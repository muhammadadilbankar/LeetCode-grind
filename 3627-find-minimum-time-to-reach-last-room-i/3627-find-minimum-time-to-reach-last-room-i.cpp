class Solution {
public:
    vector<vector<int>> directions{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    typedef pair<int, pair<int, int>> p;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        result[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int curr = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();
            if(i == m-1 && j == n-1) return curr;
            for(auto d: directions){
                int i_ = i + d[0];
                int j_ = j + d[1];
                if(i_ >= 0 && i_<m && j_ >=0 && j_<n){
                    int wait = max(moveTime[i_][j_] - curr, 0);
                    int arr = curr + wait + 1;
                    if(result[i_][j_] > arr){
                        result[i_][j_] = arr;
                        pq.push({arr, {i_, j_}});
                    }
                }
            }
        }
        return -1;
    }
};