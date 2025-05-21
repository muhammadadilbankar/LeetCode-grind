class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<int> diff(n+1, 0);
        for(int i=0; i<shifts.size(); i++){
            int x = shifts[i] % 26;
            diff[0] += x;
            diff[i+1] -= x;
        }
        vector<int> res(n, 0);
        int curr = 0;
        for(int i=0; i<n; i++){
            curr += diff[i];
            res[i] = curr;
        }
        for(int i=0; i<n; i++){
            int shift = res[i] % 26;
            s[i] = ((s[i] - 'a') + shift) % 26 + 'a';
        }
        return s;
    }
};