class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++){
            bool found = false;
            for(int j=0; j<words[i].size(); j++){
                if(words[i][j] == x && found == false){
                    ans.push_back(i);
                    found = true;
                }
            }
        }
        return ans;
    }
};