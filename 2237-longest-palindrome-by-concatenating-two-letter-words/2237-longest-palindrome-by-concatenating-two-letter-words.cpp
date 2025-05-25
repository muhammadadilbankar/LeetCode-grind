class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>mp;
        int result = 0;
        for(auto word : words){
            string temp = word;
            swap(temp[0], temp[1]);
            if(mp[temp] > 0){
                result += 4;
                mp[temp]--;
            }
            else mp[word]++;
        }
        for(auto it : mp){
            string word = it.first;
            int count = it.second;
            if(word[0] == word[1] && count > 0){
                result += 2;
                break;
            }
        }
        return result;
    }
};