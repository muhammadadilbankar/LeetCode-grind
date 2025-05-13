class Solution {
public:
    int M = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int> hash(26, 0);
        for(auto ch : s){
            hash[ch - 'a'] ++;
        }
        for(int i=0; i<t; i++){
            vector<int> temp(26, 0);
            for(int i=0; i<26; i++){
                char ch = i + 'a';
                int freq = hash[i];
                if(ch != 'z'){
                    temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % M;
                }
                else{
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
                }
            }
            hash = move(temp);
        }
        int ans = 0;
        for(int i=0; i<26; i++) ans = (ans + hash[i]) % M;
        return ans;
    }
};