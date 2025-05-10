class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int zero1 = count(nums1.begin(), nums1.end(), 0);
        int zero2 = count(nums2.begin(), nums2.end(), 0);

        long long min1 = sum1 + zero1;
        long long min2 = sum2 + zero2;

        if ((!zero1 && min2 > min1) || (!zero2 && min1 > min2)) return -1;

        return max(min1, min2);   
    }
};
