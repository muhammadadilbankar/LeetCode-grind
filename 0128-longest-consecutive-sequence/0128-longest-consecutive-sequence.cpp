class Solution {
public:
//optimal solution using O(2N) Time complexity
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        int longest = 1;
        //putting all the elements in the set
        for(int i=0; i<n; i++) st.insert(nums[i]);
        for(auto e : st){
            if(st.find(e-1) == st.end()){
                int cnt = 1;
                int x = e;
                while(st.find(x+1) != st.end()){
                    cnt ++;
                    x++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};