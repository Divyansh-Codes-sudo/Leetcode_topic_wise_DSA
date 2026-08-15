class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resxor = 0;
        bool zeros = true;

        for (int &x : nums){
            resxor ^= x;

            if (x != 0) zeros=false;
        }

        if (zeros) return 0;

        return resxor==0 ? n-1 : n;
    }
};