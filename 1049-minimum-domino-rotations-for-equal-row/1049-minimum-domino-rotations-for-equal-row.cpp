class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms, int val){
        //checking the tops
        int tswap = 0;
        int bswap = 0;
        for(int i=0; i<tops.size(); i++){
            if(tops[i] != val && bottoms[i] != val) return -1;
            else if(tops[i] != val) tswap++;
        }
        for(int i=0; i<bottoms.size(); i++){
            if(tops[i] != val && bottoms[i] != val) return -1;
            else if(bottoms[i] != val) bswap++;
        }
        return min(tswap, bswap);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;
        for(int val = 1; val <= 6; val ++){
            int swaps = find(tops, bottoms, val);
            if(swaps != -1){
                result = min(swaps, result);
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
};