class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // solving using sliding window approach
        int n = s.size();
        unordered_set<char> hash;
        int ans = 0;
        int l = 0, r = 0;
        while(r < n){
            if(hash.find(s[r]) == hash.end()){
                //character is not in the set so we can add that
                hash.insert(s[r]);
                ans = max(ans, r-l+1);
                r++;
            }
            else{
                //character is already seen so we shrink the window from the left
                hash.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};