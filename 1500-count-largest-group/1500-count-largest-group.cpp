class Solution {
public:
    int summing(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxi = 0;
        int count = 0;
        for(int i=1; i<=n; i++){
            int digitSum = summing(i);
            mp[digitSum] ++;
            if(mp[digitSum] == maxi) count ++;
            else if(mp[digitSum] > maxi){
                maxi = mp[digitSum];
                count = 1;
            }
        }
        return count;
    }
};