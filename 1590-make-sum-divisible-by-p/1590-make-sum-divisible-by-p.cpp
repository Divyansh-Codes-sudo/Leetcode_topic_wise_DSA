class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long s = accumulate(begin(nums) , end(nums) , 0LL);

        if (s % p == 0) return 0;

        int target = s % p;

        unordered_map<int , int> mp;

        mp[0] = -1;

        int cur = 0;
        int ans = nums.size();

        for (int i = 0 ; i<nums.size() ; i++){
            cur = (cur + nums[i]) % p;

            int needed = (cur - target + p) % p;

            if (mp.count(needed)){
                ans = min(ans , i-mp[needed]);
            }

            mp[cur] = i;

        }

        return (ans<nums.size()) ? ans : -1 ;

    }
};