class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int used = 0;
        multiset<int>st(workers.begin(), workers.begin()+mid);
        for(int i=mid-1; i>=0; i--){
            int reqd = tasks[i];
            auto it = prev(st.end());
            if(*it >= reqd){
                st.erase(it);
            }
            else if(used >= pills) return false;
            else{
                auto weakestIt = st.lower_bound(reqd - strength);
                if(weakestIt == st.end()) return false;
                st.erase(weakestIt);
                used++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
       int m = tasks.size();
       int n = workers.size();

       int l = 0;
       int r = min(m, n);
       sort(tasks.begin(), tasks.end());
       sort(workers.begin(), workers.end(), greater<int>());
       int ans = 0;
       while(l<=r){
        int mid = l + (r-l)/2;
        if(check(tasks, workers, pills, strength, mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
       } 
       return ans;
    }
};